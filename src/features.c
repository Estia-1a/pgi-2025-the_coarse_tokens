#include <estia-image.h>
#include <stdio.h>

#include <string.h>
#include "features.h"
#include "utils.h"
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".'
 */

void helloWorld() {
    printf("Hello World !");
}


void tenth_pixel (char *source_path){
    int width, height, channel_count ;
    unsigned char *data; 

    read_image_data (source_path, &data, &width, &height, &channel_count);
    printf("tenth_pixel: %d, %d, %d" , data [27] , data[28] , data[29]);
}
    
void dimension (char *source_path) {
    int height ;
    int width  ;
    int channel_count ;
    unsigned char *data ;
   
    int resultat = read_image_data (source_path, &data, &height, &width, &channel_count);
    if(resultat) {
    printf("dimension: %d, %d ", height, width);
    }
    else {
     printf("erreur: ");
    }
}
void first_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int resultat1 = read_image_data (source_path, &data, &width, &height, &channel_count);
    if (resultat1) { 
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];
    printf("first_pixel: %d, %d, %d", r, g, b);
    }
    else {
     printf("erreur: ");
    }  
}
void print_pixel(char *source_path, int x, int y) {
    int width, height, channel_count;
    unsigned char *data;

    if (!read_image_data(source_path, &data, &width, &height, &channel_count)) {
        return;
    }

    pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
    if (pixel) {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
        free(pixel);
    }

    free(data);
}


void second_line(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second_line: %d, %d, %d", data[3 * width], data[3 * width + 1],  data[3 * width + 2]);
}
void max_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int max_sum = -1;
    int max_x = 0, max_y = 0;
    pixelRGB max_pixel = {0, 0, 0};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (pixel == NULL) continue;

            int sum = pixel->R + pixel->G + pixel->B;

            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_pixel = *pixel;
            }

            free(pixel); 
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);

    free(data); 
}

void min_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_sum = 256 * 3 ; 
    int min_x = 0, min_y = 0;
    pixelRGB min_pixel = {255, 255, 255};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel= get_pixel(data, width, height, channel_count, x, y);
            int sum = pixel->R + pixel ->G + pixel->B;

            if (sum < min_sum ) {
                min_sum=sum;
                min_x=x;
                min_y=y;
                min_pixel=*pixel;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
}

void max_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int max_value = -1; 
    int max_x_component = 0, max_y_component = 0 ;

    for (int y = 0; y < height ; y++ ) { 
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int value ;

            if (component == 'R'){
                value = pixel->R;
            } else if (component == 'G') { 
                value = pixel->G;
            } else {
                value = pixel->B;
            }

            if (value > max_value) { 
                max_value = value;
                max_x_component=x; 
                max_y_component=y;  
            }
        }

    }
    printf("max_component %c ( %d, %d ): %d", component, max_x_component , max_y_component , max_value);
}
void min_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int min_value = 256 ; 
    int min_x_component = 0, min_y_component = 0 ;

    for (int y = 0; y < height ; y++ ) { 
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int value ;

            if (component == 'R'){
                value = pixel->R;
            } else if (component == 'G') { 
                value = pixel->G;
            } else {
                value = pixel->B;
            }

            if (value < min_value) { 
                min_value = value;
                min_x_component=x; 
                min_y_component=y;  
            }
        }

    }
    printf("min_component %c ( %d, %d ): %d", component, min_x_component , min_y_component , min_value);
}


void color_red(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data=(unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));
    for (int y = 0; y < height; y++){
        for (int x=0; x < width; x++){
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char red = pixel->R;
            new_data[(y * width + x) * channel_count] = red;
            new_data[(y * width + x) * channel_count + 1] = 0;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_green(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data=(unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));
    for (int y = 0; y < height; y++){
        for (int x=0; x < width; x++){
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char green = pixel->G;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = green;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}


void stat_report(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    // max_pixel et min_pixel
    int max_sum = -1, min_sum = 256 * 3;
    int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
    pixelRGB max_pixel = {0, 0, 0};
    pixelRGB min_pixel = {255, 255, 255};

    // min/max par composantes
    int max_value_R = -1, max_value_G = -1, max_value_B = -1;
    int max_x_R = 0, max_y_R = 0, max_x_G = 0, max_y_G = 0, max_x_B = 0, max_y_B = 0;
    int min_value_R = 256, min_value_G = 256, min_value_B = 256;
    int min_x_R = 0, min_y_R = 0, min_x_G = 0, min_y_G = 0, min_x_B = 0, min_y_B = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            if (!pixel) continue;

            int sum = pixel->R + pixel->G + pixel->B;

            // max_pixel
            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_pixel = *pixel;
            }

            // min_pixel
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_pixel = *pixel;
            }

            // composante R
            if (pixel->R > max_value_R) {
                max_value_R = pixel->R;
                max_x_R = x;
                max_y_R = y;
            }
            if (pixel->R < min_value_R) {
                min_value_R = pixel->R;
                min_x_R = x;
                min_y_R = y;
            }

            // composante G
            if (pixel->G > max_value_G) {
                max_value_G = pixel->G;
                max_x_G = x;
                max_y_G = y;
            }
            if (pixel->G < min_value_G) {
                min_value_G = pixel->G;
                min_x_G = x;
                min_y_G = y;
            }

            // composante B
            if (pixel->B > max_value_B) {
                max_value_B = pixel->B;
                max_x_B = x;
                max_y_B = y;
            }
            if (pixel->B < min_value_B) {
                min_value_B = pixel->B;
                min_x_B = x;
                min_y_B = y;
            }

            free(pixel);
        }
    }

    FILE *fp = fopen("stat_report.txt", "w");
    if (fp) {
        fprintf(fp, "max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);
        fprintf(fp, "min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
        fprintf(fp, "max_component R (%d, %d): %d\n", max_x_R, max_y_R, max_value_R);
        fprintf(fp, "max_component G (%d, %d): %d\n", max_x_G, max_y_G, max_value_G);
        fprintf(fp, "max_component B (%d, %d): %d\n", max_x_B, max_y_B, max_value_B);
        fprintf(fp, "min_component R (%d, %d): %d\n", min_x_R, min_y_R, min_value_R);
        fprintf(fp, "min_component G (%d, %d): %d\n", min_x_G, min_y_G, min_value_G);
        fprintf(fp, "min_component B (%d, %d): %d\n", min_x_B, min_y_B, min_value_B);
        fclose(fp);
    }

    free_image_data(data);
}
void color_blue(char *source_path) {
 int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char blue  = pixel->B ;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = 0 ;
            new_data[(y * width + x) * channel_count + 2] = blue;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_gray(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char gray = (pixel->R + pixel->G + pixel->B) / 3;
            new_data[(y * width + x) * channel_count] = gray;
            new_data[(y * width + x) * channel_count + 1] = gray ;
            new_data[(y * width + x) * channel_count + 2] = gray;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_gray_luminance(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char value = 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
            new_data[(y * width + x) * channel_count] = value;
            new_data[(y * width + x) * channel_count + 1] =value;
            new_data[(y * width + x) * channel_count + 2] = value ; 
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
} 

void color_invert(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            new_data[(y * width + x) * channel_count] = 255 - pixel->R;
            new_data[(y * width + x) * channel_count + 1] =255 - pixel->G;
            new_data[(y * width + x) * channel_count + 2] = 255 - pixel->B ; 
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}  

void rotate_acw(char *source_path) {
    int width, height, channels;
    unsigned char *data = NULL;
 
    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        fprintf(stderr, "Erreur : lecture de l'image échouée.\n");
        return;
    }
 
    int new_width = height;
    int new_height = width;
    unsigned char *rotated_data = malloc(width * height * channels);
 
    if (!rotated_data) {
        fprintf(stderr, "Erreur : mémoire insuffisante pour la rotation.\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_index = ((width - 1 - x) * height + y) * channels + c;
                rotated_data[dest_index] = data[src_index];
            }
        }
    }
 
    if (write_image_data("image_out.bmp", rotated_data, new_width, new_height) != 0) {
        fprintf(stderr, "Erreur : écriture de l'image échouée.\n");
    }
 
    free(data);
    free(rotated_data);
}
 
void rotate_cw(char *source_path) {
    int width, height, channels;
    unsigned char *data = NULL;

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        fprintf(stderr, "Erreur : lecture de l'image échouée.\n");
        return;
    }

    int new_width = height;
    int new_height = width;
    unsigned char *rotated_data = malloc(width * height * channels);

    if (!rotated_data) {
        fprintf(stderr, "Erreur : mémoire insuffisante pour la rotation.\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_index = (x * height + (height - 1 - y)) * channels + c;
                rotated_data[dest_index] = data[src_index];
            }
        }
    }

    if (write_image_data("image_out.bmp", rotated_data, new_width, new_height) != 0) {
        fprintf(stderr, "Erreur : écriture de l'image échouée.\n");
    }

    free(data);
    free(rotated_data);
}
void mirror_horizontal(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) { 
        for (int x = 0; x < width; x++) {
            int new_x = width - 1 - x;
            int new_y = y;

            for (int c = 0; c < channel_count; c++) {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}

void mirror_vertical(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) { 
        for (int x = 0; x < width; x++) {
            int new_x = x;
            int new_y = height - 1 - y;

            for (int c = 0; c < channel_count; c++) {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}

void mirror_total(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) { 
        for (int x = 0; x < width; x++) {
            int new_x = width - 1 - x;
            int new_y = height - 1 - y;

            for (int c = 0; c < channel_count; c++) {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}

void scale_nearest(char *source_path, float scale) {
    int width, height, channels;
    unsigned char *data = NULL;
 
    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        fprintf(stderr, "Erreur : lecture de l'image échouée.\n");
        return;
    }
 
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *scaled_data = malloc(new_width * new_height * channels);
 
    if (!scaled_data) {
        fprintf(stderr, "Erreur : mémoire insuffisante.\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale + 0.5f);
            int src_y = (int)(y / scale + 0.5f);
 
            if (src_x >= width) src_x = width - 1;
            if (src_y >= height) src_y = height - 1;
 
            for (int c = 0; c < channels; c++) {
                int dest_index = (y * new_width + x) * channels + c;
                int src_index = (src_y * width + src_x) * channels + c;
                scaled_data[dest_index] = data[src_index];
            }
        }
    }
 
    if (write_image_data("image_out.bmp", scaled_data, new_width, new_height) != 0) {
        fprintf(stderr, "Erreur : écriture de l'image échouée.\n");
    }
 
    free(data);
    free(scaled_data);
}
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}
 
void scale_bilinear(char *source_path, float scale) {
    int width, height, channels;
    unsigned char *data = NULL;
 
    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        fprintf(stderr, "Erreur : lecture de l'image échouée.\n");
        return;
    }
 
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *scaled_data = malloc(new_width * new_height * channels);
 
    if (!scaled_data) {
        fprintf(stderr, "Erreur : mémoire insuffisante.\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            float src_x = x / scale;
            float src_y = y / scale;
 
            int x1 = (int)src_x;
            int y1 = (int)src_y;
            int x2 = x1 + 1;
            int y2 = y1 + 1;
 
            float dx = src_x - x1;
            float dy = src_y - y1;
 
            if (x1 >= width) x1 = width - 1;
            if (x2 >= width) x2 = width - 1;
            if (y1 >= height) y1 = height - 1;
            if (y2 >= height) y2 = height - 1;
 
            for (int c = 0; c < channels; c++) {
                float Q11 = data[(y1 * width + x1) * channels + c];
                float Q12 = data[(y1 * width + x2) * channels + c];
                float Q21 = data[(y2 * width + x1) * channels + c];
                float Q22 = data[(y2 * width + x2) * channels + c];
 
                float R1 = lerp(Q11, Q12, dx);
                float R2 = lerp(Q21, Q22, dx);
                float P = lerp(R1, R2, dy);
 
                scaled_data[(y * new_width + x) * channels + c] = (unsigned char)(P + 0.5f);
            }
        }
    }
 
    if (write_image_data("image_out.bmp", scaled_data, new_width, new_height) != 0) {
        fprintf(stderr, "Erreur : écriture de l'image échouée.\n");
    }
 
    free(data);
    free(scaled_data);
}
 
void color_desaturate(char *source_path) {
    int width, height, channels;
    unsigned char *data = NULL;
 
    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        fprintf(stderr, "Erreur : lecture de l'image echouee.\n");
        return;
    }
 
    int size = width * height * channels;
    for (int i = 0; i < size; i += channels) {
        unsigned char r = data[i];
        unsigned char g = data[i + 1];
        unsigned char b = data[i + 2];
 
        unsigned char min_val = r < g ? (r < b ? r : b) : (g < b ? g : b);
        unsigned char max_val = r > g ? (r > b ? r : b) : (g > b ? g : b);
        unsigned char desaturated = (min_val + max_val) / 2;
 
        data[i]     = desaturated;
        data[i + 1] = desaturated;
        data[i + 2] = desaturated;
    }
 
    if (write_image_data("image_out.bmp", data, width, height) != 0) {
        fprintf(stderr, "Erreur : ecriture de l'image echouee.\n");
    }
 
    free(data);
}
void scale_crop(char *source_path, int center_x, int center_y, int width, int height) {
    int original_width, original_height, channel_count;
    unsigned char *data;
 
    read_image_data(source_path, &data, &original_width, &original_height, &channel_count);
 
    int x_start = center_x - width / 2;
    int y_start = center_y - height / 2;
 
    if (x_start < 0) {
        x_start = 0;
    } else if (x_start + width > original_width) {
        x_start = original_width - width;
    }
 
    if (y_start < 0) {
        y_start = 0;
    } else if (y_start + height > original_height) {
        y_start = original_height - height;
    }
 
    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int new_x = x_start + x;
            int new_y = y_start + y;
 
            pixelRGB *pixel = get_pixel(data, original_width, original_height, channel_count, new_x, new_y);
            unsigned char R = pixel->R;
            unsigned char G = pixel->G;
            unsigned char B = pixel->B;
 
            new_data[(y * width + x) * channel_count] = R;
            new_data[(y * width + x) * channel_count + 1] = G;
            new_data[(y * width + x) * channel_count + 2] = B;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}
 