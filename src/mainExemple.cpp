/**
 * @file mainExemple.cpp
 * @author Yanisse FERHAOUI | Jounaid BOUDEFAR
 * @brief Programme principal qui fait appel aux fonctions "ouvrir" et "sauver" et qui va créer et remplir 2 images.
 * 
 * @date 2022-03-03
 * 
 * 
 * 
 */

#include "Image.h"
#include <iostream>
 
int main() {
 
    Pixel blanc (255, 255, 255);
    Pixel vert (4, 200, 10);
    Pixel bleu (0, 128, 255);
 
    Image image1 (64,48);
    image1.effacer(vert);
    image1.dessinerRectangle(10, 40, 20, 44, blanc);
    image1.setPix(2,9,bleu);
    image1.setPix(15,42,bleu);
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(4, 14, 20, 43, blanc);
    image2.dessinerRectangle(32, 4, 50, 8, bleu);
    image2.sauver("./data/image2.ppm");
 
    return 0;
}