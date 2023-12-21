#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>


//����ɫ�����һ��32λ������
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=255) {
    return (a<<24) + (b<<16) + (g<<8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) {
    //ʹ��λ�����ܹ�����ɫ���������ֻ�����8λ�������ﲻʹ��������Ҳ�ǿ��Եģ���Ϊuint8_tֻ��8λ
    r = (color >>  0) & 255;
    g = (color >>  8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t w, const size_t h) {
    //���� ��֤ͼƬ�Ĵ�С�������Ĵ�Сһ��?
    assert(image.size() == w*h);
    //�����ļ�
    std::ofstream ofs(filename, std::ios::binary);
    //д���ļ�ͷ
    ofs << "P6\n" << w << " " << h << "\n255\n";
    //д���ļ�����
    for (size_t i = 0; i < h*w; ++i) {
        uint8_t r, g, b, a;
        unpack_color(image[i], r, g, b, a);
        //ΪʲôҪ��uint8_tת����char?
        //��Ϊuint8_t��һ���ֽڣ���charҲ��һ���ֽڣ����Կ���ֱ��ת����Ϊ������ƥ�䣬����Ҫ���м���
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

int main() {
    //����ͼƬ��С
    //��ͼƬ��ʼ��
    const size_t win_width = 512;
    const size_t win_height = 384;
    //��������
    std::vector<uint32_t> framebuffer(win_width * win_height, 255);
    //���������ӳ�䵽������
    //fill the screen with color gradients 
    for (size_t j = 0; j < win_height; j++) {
        for (size_t i = 0; i < win_width; i++) {
            uint8_t r = 255 * i / float(win_width);
            uint8_t g = 255 * j / float(win_height);
            uint8_t b = 0;
            framebuffer[i + j * win_width] = pack_color(r, g, b);
        }
    }
    //�������е�����д�뵽�ļ���
    drop_ppm_image("./out.ppm", framebuffer, win_width, win_height);

    return 0;
}