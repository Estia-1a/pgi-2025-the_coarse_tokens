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

void min_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_sum = 256*3;
    int min_x = 0, max_y = 0;
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

            free(pixel); // libère chaque pixel alloué
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);

    free(data); // libère l'image complète

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

}