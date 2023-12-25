#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <cstdint>


//将颜色打包成一个32位的整数
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=255) {
    return (a<<24) + (b<<16) + (g<<8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) {
    //使用位运算能够将颜色分离出来，只拿最低8位。在这里不使用与运算也是可以的，因为uint8_t只有8位
    r = (color >>  0) & 255;
    g = (color >>  8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t w, const size_t h) {
    //断言 保证图片的大小和容器的大小一致?如果等于w*h那么不报错

    assert(image.size() == w*h);
    //创建文件
    std::ofstream ofs(filename, std::ios::binary);
    //写入文件头
    ofs << "P6\n" << w << " " << h << "\n255\n";
    //写入文件内容
    for (size_t i = 0; i < h*w; ++i) {
        uint8_t r, g, b, a;
        unpack_color(image[i], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

int main() {
    //创建图片大小
    //将图片初始化为512*384大小，并且填充255， 使用usign32_t去填充
    const size_t win_width = 512;
    const size_t win_height = 384;
    //创建容器
    std::vector<uint32_t> framebuffer(win_width * win_height, 255);
    //将容器填充映射到容器中
    //fill the screen with color gradients
    for (size_t j = 0; j < win_height; j++) {
        for (size_t i = 0; i < win_width; i++) {
            uint8_t r = 255 * i / float(win_width);
            uint8_t g = 255 * j / float(win_height);
            uint8_t b = 0;
            //将二维数组转化为一维数组
            framebuffer[i + j * win_width] = pack_color(r, g, b);
        }
    }
    //将容器中的数据写入到文件中
    drop_ppm_image("./out.ppm", framebuffer, win_width, win_height);

    return 0;

}