#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".'
 */

void helloWorld() {
    printf("Hello World !");
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
    int width, height, channels;
    unsigned char *data ;

    int resultat1 = read_image_data (source_path, &data, &width, &height, &channels);
    if (resultat1) { 
    printf("Image chargée : %d x %d, %d canaux\n", width, height, channels);
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

void second_line(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second_line: %d, %d, %d", data[3 * width], data[3 * width + 1],  data[3 * width + 2]);
}