#include <iostream>
#include <vector>
#include <fstream> mn
#include <cassert>



uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=255) {
    return (a<<24) + (b<<16) + (g<<8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) {
    r = (color >>  0) & 255;
    g = (color >>  8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t w, const size_t h) {
    assert(image.size() == w*h);
    std::ofstream ofs(filename, std::ios::binary);
    ofs << "P6\n" << w << " " << h << "\n255\n";
    for (size_t i = 0; i < h*w; ++i) {
        uint8_t r, g, b, a;
        unpack_color(image[i], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

int main() {
    const size_t win_width = 512; //size_t 是一种数据类型，用于保存内存中任何对象的大小
    const size_t win_height = 384;
    std::vector<uint32_t> framebuffer(win_width * win_height, 255);

    for (size_t j = 0; j < win_height; j++) {
        for (size_t i = 0; i < win_width; i++) {
            uint8_t r = 255 * i / float(win_width);
            uint8_t g = 255 * j / float(win_height);
            uint8_t b = 0;
            framebuffer[i + j * win_width] = pack_color(r, g, b);
        }
    }

    drop_ppm_image("./out.ppm", framebuffer, win_width, win_height);

    return 0;
}