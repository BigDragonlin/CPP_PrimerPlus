#include <iostream>
#include <fstream> //file stream
#include <vector>
#include <cstdint> //C stand integer
#include <cassert> //C assert

void UnPack(uint32_t subImage, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a){
    r = (subImage>>24)&255;
    g = (subImage>>16)&255;
    b = (subImage>>8)&255;
    a = (subImage>>0)&255;
}

void dropImagePPM(const std::string &fileName, const std::vector<uint32_t>& image, size_t width, size_t high){
//使用断言判断image.size()是否等于width*height
    assert(image.size() == width * high);
//设置输出流
    std::ofstream ofs(fileName, std::ios::binary);
//写入文件头
    ofs << "P6\n" << width << " "<< high << "\n255\n";
//写入文件内容
    for (size_t i = 0; i < high * width; ++i) {
        uint8_t r, g, b, a;
        UnPack(image[i], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

//将颜色打包成一个32位的整数
uint32_t Pack(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255){
    return (r<<24) + (g<<16) + (b<<8) + a;
}

/*
 *
 * */
void draw_rectangle(std::vector<uint32_t> &image, const size_t img_w, const size_t img_h, const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color){
    //断言判断是不是image size 大小有没有改变
    assert(image.size() == img_w * img_h);
    for (size_t i=0; i<w; i++) {
        for (size_t j=0; j<h; j++) {
            size_t cx = x+i;
            size_t cy = y+j;
            assert(cx<img_w && cy<img_h);
            image[cx + cy*img_w] = color;
        }
    }
}


int main() {
    //创建图片大小
    const size_t width = 512;
    const size_t high = 512;
    //将图片初始化为512*384大小，并且填充255， 使用usign32_t去填充
    std::vector<uint32_t> image(width * high, 255);
    const size_t map_w = 16;
    const size_t map_h = 16;
    const char map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
                       "1     0        0"\
                       "0     0  1110000"\
                       "0     3        0"\
                       "0   10000      0"\
                       "0   0   11100  0"\
                       "0   0   0      0"\
                       "0   0   1  00000"\
                       "0       1      0"\
                       "2       1      0"\
                       "0       0      0"\
                       "0 0000000      0"\
                       "0              0"\
                       "0002222222200000"; // our game map
    assert(sizeof(map) == map_w * map_h + 1);


    //创建容器
    for (size_t w = 0; w < width; w++) {
        for (size_t h = 0;  h < high; h++) {
            uint8_t r = 255 * h / float(high);
            uint8_t g = 255 * w / float (width);
            uint8_t b = 0;
            //将容器填充映射到容器中
            image[w + h * high] = Pack(r, g, b);
        }
    }

    const size_t rect_w = width / map_w;
    const size_t rect_h = high / map_h;
    for (size_t i = 0; i < map_w; i++) {
        for (size_t j = 0; j < map_h; j++) {
            //判断部分map是不是空字符串，是空的话跳过，不是空的话，把这部分坐标给绘制程序
            if (map[i+j*map_h] == ' ') continue;
            //当前地图单元在图像中的位置
            size_t rect_x = i * rect_w;
            size_t rect_y = j * rect_h;
            draw_rectangle(image, width, high, rect_x, rect_y, rect_w, rect_h, Pack(0, 255, 255));
        }
    }

    //fill the screen with color gradients
    //将容器中的数据写入到文件中
    dropImagePPM("./outPut.ppm", image, width, high);
    return 0;
}
