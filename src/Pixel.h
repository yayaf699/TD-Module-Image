/**
 * @file Pixel.h
 * @author Yanisse FERHAOUI | Jounaid BOUDEFAR
 * @brief Déclaration de la classe Pixel, ainsi que ses variables et ses fonctions membres.
 * @date 2022-03-03
 * 
 * 
 */

#ifndef _PIXEL
#define _PIXEL

/**
 * @brief Classe Pixel
 * 
 */
class Pixel{

 private :

   unsigned char r,g,b; // les composantes du pixel, unsigned char en C++

 public :

  /**
   * @brief Constructeur par défaut de la classe: initialise le pixel à la couleur noire
  */
  Pixel ();

  /**
   * @brief Constructeur de la classe: initialise r,g,b avec les paramètres
   * 
   * @param[in] nr Couleur rouge du pixel
   * @param[in] ng Couleur verte du pixel
   * @param[in] nb Couleur bleue du pixel
   */
  Pixel (const unsigned char &nr, const unsigned char &ng, const unsigned char &nb);

  /**
   * @brief Accesseur : récupère la composante rouge du pixel
   * 
   * @return const unsigned char& 
   */
  const unsigned char &getRouge()const;

  /**
   * @brief Accesseur : récupère la composante verte du pixel
   * 
   * @return const unsigned char& 
   */
  const unsigned char &getVert ()const;

  /**
   * @brief Accesseur : récupère la composante bleue du pixel
   * 
   * @return const unsigned char& 
   */
  const unsigned char &getBleu ()const;

  /**
   * @brief Mutateur : modifie la composante rouge du pixel
   * 
   * @param[in] nr Couleur rouge du pixel à récupérer
   */
  void setRouge(unsigned char nr);

  /**
   * @brief Mutateur : modifie la composante verte du pixel
   * 
   * @param[in] ng Couleur verte du pixel à récupérer
   */
  void setVert (unsigned char ng);

  /**
   * @brief Mutateur : modifie la composante bleue du pixel
   * 
   * @param[in] nb Couleur bleue du pixel à récupérer
   */
  void setBleu (unsigned char nb);

};

#endif