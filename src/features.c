#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"
#include <stdlib.h>

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
    printf("Image chargée : %d x %d, %d canaux\n", width, height, channel_count);
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];
    printf("Couleur du premier pixel :\n");
    printf("R = %d\n", r);
    printf("G = %d\n", g);
    printf("B = %d\n", b);
    }
    else {
     printf("erreur: ");
    }  
}
void print_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int resultat2 = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (!resultat2) {
        printf("Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    printf("Image chargée : %d x %d, %d canaux\n", width, height, channel_count);
    int x, y;
    printf("Entrez les coordonnées du pixel (x y) : ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Erreur : saisie invalide\n");
        return;
    }
    if (x < 0 || x >= width || y < 0 || y >= height) {
        fprintf(stderr, "Erreur : position (%d, %d) hors de l'image (%d x %d)\n", x, y, width, height);
        return;
    }
    int index = (y * width + x) * channel_count;
    unsigned char r = data[index];
    unsigned char g = data[index + 1];
    unsigned char b = data[index + 2];

    printf("Couleur du pixel à (%d, %d) :\n", x, y);
    printf("R = %d\n", r);
    printf("G = %d\n", g);
    printf("B = %d\n", b);

    if (channel_count == 4) {
        unsigned char a = data[index + 3];
        printf("A = %d\n", a);
    }
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

    int min_sum = 256*3;
    int min_x = 0, min_y = 0;
    pixelRGB min_pixel = {255, 255, 255};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (pixel == NULL) continue;

            int sum = pixel->R + pixel->G + pixel->B;

            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_pixel = *pixel;
            }

            free(pixel); 
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);

    free(data); 
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