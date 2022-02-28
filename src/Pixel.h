#ifndef _PIXEL
#define _PIXEL


class Pixel{

 private :

   unsigned char r,g,b; // les composantes du pixel, unsigned char en C++

 public :

   // Constructeur par défaut de la classe: initialise le pixel à la couleur noire
  Pixel ();

   // Constructeur de la classe: initialise r,g,b avec les paramètres
  Pixel (const unsigned char &nr, const unsigned char &ng, const unsigned char &nb);

   // Accesseur : récupère la composante rouge du pixel
  unsigned char getRouge()const;

   // Accesseur : récupère la composante verte du pixel
  const unsigned char &getVert ()const;

   // Accesseur : récupère la composante bleue du pixel
  const unsigned char &getBleu ()const;

   // Mutateur : modifie la composante rouge du pixel
  void setRouge(unsigned char nr);

   // Mutateur : modifie la composante verte du pixel
  void setVert (unsigned char ng);

   // Mutateur : modifie la composante bleue du pixel
  void setBleu (unsigned char nb);

};

#endif