/**
 * @file Image.h
 * @author Yanisse FERHAOUI | Jounaid BOUDEFAR
 * @brief Déclaration de la classe Image, ainsi que ses variables et ses fonctions membres.
 * 
 * @date 2022-03-03
 * 
 * 
 */

#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @brief Classe Image
*/
class Image{

 private :

  Pixel * tab;   // le tableau 1D de pixel
  unsigned int dimx, dimy;  // les dimensions de l'image

  /**
   * @brief Toutes les variables que nous aurons besoin pour inclure SDL2 au module 
  */
  SDL_Window * window = nullptr;
  SDL_Renderer * renderer = nullptr;
  SDL_Rect rect = {0, 0, 0, 0};
  SDL_Texture * texture = nullptr;
  SDL_Surface * surface = nullptr;

 /**
 * @brief Fonction affichage de la fenêtre SDL2: initialise la fenêtre.
 */
  void afficherInit();

 /**
 * @brief Fonction affichage de la fenêtre SDL2: crée la boucle infinie dans laquelle les évènements se modifieront (exemple: Zoom).
 */
  void afficherBoucle();

  /**
 * @brief Fonction affichage de la fenêtre SDL2: Détruit les variables de type pointeur ainsi que l'image créée.
 */
  void afficherDetruit();


 public :

/**
 * @brief Constructeur par défaut de la classe: initialise dimx et dimy à 0, ce constructeur n'alloue pas de pixel.
*/
  Image ();

  /**
 * @brief Constructeur de la classe: initialise dimx et dimy (après vérification) puis alloue le tableau de pixel dans le tas (image noire).
 */
  Image (unsigned int dimensionX, unsigned int dimensionY);

  /**
 * @brief Destructeur de la classe: déallocation de la mémoire du tableau de pixels  et mise à jour des champs dimx et dimy à 0.
 */
  ~Image ();

  /**
   * @brief Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité.
   * 
   * @param[in] x Coordonnée x du pixel à récupérer.
   * @param[in] y Coordonnée x du pixel à récupérer.
   * @return Pixel& 
   */
  Pixel &getPix (unsigned int x, unsigned int y) const;

  /**
   * @brief Mutateur : modifie le pixel de coordonnées (x,y).
   * 
   * @param x Coordonnée x du pixel à modifier.
   * @param y Coordonnée y du pixel à modifier.
   * @param couleur Couleur du pixel à modifier.
   */
  void setPix (unsigned x, unsigned y, const Pixel &couleur);

  /**
   * @brief Dessine un rectangle plein de la couleur dans l'image.
   * 
   * @param[in] Xmin Plus petite coordonnée de x.
   * @param[in] Ymin Plus petite coordonnée de y.
   * @param[in] Xmax Plus grande coordonnée de x.
   * @param[in] Ymax Plus grande coordonnée de y.
   * @param[in] couleur Couleur que le rectangle va avoir. 
   */
  void dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel &couleur);

  /**
   * @brief Efface l'image en la remplissant de la couleur en paramètre.
   * 
   * @param couleur Couleur qui recouvrera l'image.
   */
  void effacer (const Pixel &couleur);

  /**
   * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes.
  */
  void testRegression ();

  /**
   * @brief Sauvegarde une image dans un fichier saisi en paramètres.
   * 
   * @param filename Lien vers l'image à sauvegarder.
   */
  void sauver(const std::string & filename) const;

  /**
   * @brief Ouvre une image dont le lien du ficher est en paramètre.
   * 
   * @param filename Lien vers l'image à ouvrir.
   */
  void ouvrir(const std::string & filename);

  /**
   * @brief Affiche une image en format texte sur la console.
   * 
   */
  void afficherConsole();

  /**
   * @brief Fait appel aux 3 fonctions affichage: Affiche la fenêtre SDL2.
   * 
   */
  void afficher();

};

#endif