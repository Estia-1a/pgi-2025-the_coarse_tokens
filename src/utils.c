#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB* get_pixel(unsigned char* data, unsigned int width, unsigned int height, unsigned int n, unsigned int x, unsigned int y) {
    if (data == NULL || x >= width || y >= height) {
        return NULL;
    }

    int index = (y * width + x) * n;

    pixelRGB* p = malloc(sizeof(pixelRGB));
    if (p == NULL) return NULL;

    p->R = data[index];
    p->G = data[index + 1];
    p->B = data[index + 2];

    return p;
}
