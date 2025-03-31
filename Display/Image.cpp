#include "Image.h"
//
// Created by barti on 30.03.2025.

#include <fstream>
#include <iostream>

using namespace display;
#include "Image.h"


Image::Image(int width, int height) : width(width), height(height) {
    pixels.resize(width * height);
}
void Image::setPixel(int x, int y, lightIntensity &pixel) {
    if(x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Pixel out of bounds");
    }
    pixels[y * width + x] = pixel;
}

void Image::save(const string &filename) const{
    ofstream file(filename);
    if(!file.is_open()) {
        cout << "Could not open file" << endl;
        return;
    }
    file << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const lightIntensity &pixel = pixels[y * width + x];
            file << pixel.r << " " << pixel.g << " " << pixel.b << "\n";
        }
        file << "\n";
    }
    file.close();
}