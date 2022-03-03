/**
 * @file Pixel.cpp
 * @author Yanisse FERHAOUI | Jounaid BOUDEFAR
 * @brief Implémentation de la classe Pixel.
 * 
 * @date 2022-03-03
 * 
 * 
 * 
 */

#include "Pixel.h"

Pixel::Pixel (){ r = g = b = 0; }

Pixel::Pixel (const unsigned char &nr, const unsigned char &ng, const unsigned char &nb){ r = nr; g = ng; b = nb; }

const unsigned char& Pixel::getRouge()const{ return r; }

const unsigned char& Pixel::getVert ()const{ return g; }

const unsigned char& Pixel::getBleu ()const{ return b; }

void Pixel::setRouge(unsigned char nr){ r = nr; }

void Pixel::setVert (unsigned char ng){ g = ng; }

void Pixel::setBleu (unsigned char nb){ b = nb; }