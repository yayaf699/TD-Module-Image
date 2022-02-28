#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image{

 private :

  Pixel * tab;     // le tableau 1D de pixel
        // les dimensions de l'image

  // Toutes les variables que nous aurons besoin pour inclure SDL2
  // au module
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_Rect rect{0, 0};
  SDL_Texture * texture;
  SDL_Surface * surface;

  // Initialise une fenetre SDL2 en recuperant l'image
  void afficherInit();

  // boucle infinie permettant de mettre continuellement
  // a jour la fenetre
  void afficherBoucle();

  // "destructeur" : desalloue les variables SDL2 utilisees
  void afficherDetruit();


 public :

    unsigned int dimx, dimy; 

   // Constructeur par défaut de la classe: initialise dimx et dimy à 0
   // ce constructeur n'alloue pas de pixel
   Image ();

   // Constructeur de la classe: initialise dimx et dimy (après vérification)
   // puis alloue le tableau de pixel dans le tas (image noire)
   Image (unsigned int dimensionX, unsigned int dimensionY);

   // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
   // et mise à jour des champs dimx et dimy à 0
   ~Image ();

   // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
   // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
  Pixel &getPix (unsigned int x, unsigned int y) const;

   // Mutateur : modifie le pixel de coordonnées (x,y)
  void setPix (unsigned x, unsigned y, const Pixel &couleur);

   // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
  void dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel &couleur);

   // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
  void effacer (const Pixel &couleur);

   // Effectue une série de tests vérifiant que le module fonctionne et
   // que les données membres de l'objet sont conformes
  void testRegression ();

  void sauver(const std::string & filename) const;

  void ouvrir(const std::string & filename);

  void afficherConsole();

  // Fait appel aux 3 fonctions membres private de la classe, affiche
  // la fenetre SDL2
  void afficher();

};

#endif