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


int main() {
    //创建图片大小
    const size_t width = 512;
    const size_t high = 512;
    //将图片初始化为512*384大小，并且填充255， 使用usign32_t去填充
    std::vector<uint32_t> image(width * high, 255);
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

    //fill the screen with color gradients
    //将容器中的数据写入到文件中
    dropImagePPM("./outPut.ppm", image, width, high);
    return 0;
}
