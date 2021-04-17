#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

const int width     = 3601;
const int height    = 3601;

uint16_t swap_bytes(uint16_t in)
{
        uint16_t lower  = in & 0x00ff;
        uint16_t higher = (in & 0xff00) >> 8;
        return higher | (lower << 8);
}

int main(int argc, char *argv[])
{
        /* read data */
        FILE *filp = fopen("N50E008.hgt", "rb");
        if (!filp)
                return 1;

        const int len       = width * height;
        uint16_t *data_in   = malloc(len * sizeof(uint16_t));
        fread(data_in, sizeof(uint16_t), len, filp);

        uint16_t lowest = 0xffff, highest = 0;
        for (size_t i = 0; i < len; i++) {
                data_in[i] = swap_bytes(data_in[i]);

                if (data_in[i] < lowest)
                        lowest = data_in[i];

                if (data_in[i] > highest)
                        highest = data_in[i];
        }

        printf("lowest: %um, highest: %um\n", lowest, highest);

        /* coloring */
        uint8_t *gradient;
        int gradient_width, gradient_height;
        int gradient_channels;
        gradient = stbi_load("gradient.png", &gradient_width, &gradient_height,
                  &gradient_channels, 4);
        printf("0x%x %d %d\n", gradient, gradient_width, gradient_channels);

        const double fac = 2.0;

        double b = (double)gradient_width / (highest - lowest);
        uint8_t *img_data   = malloc(len * 3);
        for (size_t i = 0; i < len; i++) {
                double x = gradient_width - (b * data_in[i] - lowest * b);
                x = x * fac - (fac - 1.0) * gradient_width;
                x = x < 0 ?
                        0 : x > (gradient_width - 1) ?
                        (gradient_width - 1) : x;

                img_data[i * 3 + 0] = gradient[(int)x * gradient_channels + 0];
                img_data[i * 3 + 1] = gradient[(int)x * gradient_channels + 1];
                img_data[i * 3 + 2] = gradient[(int)x * gradient_channels + 2];
        }

        stbi_write_jpg("out.jpeg", width, height, 3, img_data, 100);

        return 0;
}
