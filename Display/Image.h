//
// Created by barti on 30.03.2025.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <vector>

#include "lightIntensity.h"

using namespace std;
namespace display {
    class Image {
    public:
        int width, height;
        vector<lightIntensity> pixels;
        Image(int width, int height);

        void setPixel(int x, int y, const lightIntensity &pixel);
        void save(const string &filename) const;

    };
}


#endif //IMAGE_H
