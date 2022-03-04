/**
 * @file Image.cpp
 * @author Yanisse FERHAOUI | Jounaid BOUDEFAR
 * @brief Implémentation de la classe Image.
 * 
 * @date 2022-03-03
 * 
 * 
 * 
 */

#include "Image.h"
#include <assert.h>
#include <iostream>
#include <fstream>


Image::Image (){

    dimx = 0; dimy = 0; tab = nullptr; } // on n'alloue pas de pixel => tab pointe sur rien du tout pour l'instant


Image::Image (unsigned int dimensionX, unsigned int dimensionY) {
	assert(dimensionX > 0); // on verifie la condition que les dimensions en parametres sont strictement
	assert(dimensionY > 0); // sont strictement superieurs a 0
	dimx = dimensionX; 
	dimy = dimensionY;
	tab = new Pixel[dimx*dimy];
}


Image::~Image (){ if(tab != nullptr && dimx != 0 && dimy != 0) delete [] tab; tab = NULL; dimx = dimy = 0; }


Pixel &Image::getPix (unsigned int x, unsigned int y) const{
	if(tab != nullptr && dimx != 0 && dimy != 0){
		assert(x < dimx);
		assert(x >= 0); 
		assert(y < dimy); 
		assert(y >= 0);
		return tab[y*dimx+x];
	}
	return tab[0];
}


void Image::setPix (unsigned int x, unsigned y, const Pixel &couleur){
	if(tab != nullptr && dimx != 0 && dimy != 0){
		assert(x < dimx);
		assert(y < dimy);
		tab[y*dimx+x].setRouge(couleur.getRouge());
		tab[y*dimx+x].setVert(couleur.getVert());
		tab[y*dimx+x].setBleu(couleur.getBleu());
	}
	else{
		Pixel pix(couleur.getRouge(), couleur.getVert(), couleur.getBleu());
		tab = &pix;
	}
}



void Image::dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel &couleur){
	if(tab != nullptr && dimx != 0 && dimy != 0){
		assert(Xmax < dimx);
		assert(Ymax < dimy);
		for(unsigned int j = Ymin; j <= Ymax; j++){
			for(unsigned int i = Xmin; i <= Xmax; i++){
			
				setPix(i, j, couleur);
			}
		}
	}
	else setPix(0, 0, couleur);
}


void Image::effacer (const Pixel &couleur){
	if(tab != nullptr && dimx != 0 && dimy != 0){
		dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
	}
	else{
		Pixel pix(couleur.getRouge(), couleur.getVert(), couleur.getBleu());
		tab = &pix;
	}
}


void Image::testRegression (){

	//Déclarations de couleurs pour les tests
	Pixel beige (244, 240, 172);
	Pixel vert (8, 212, 2);

	//Les assert de l'image déclarée dans le main
	assert(dimx == 0);
	assert(dimy == 0);
	assert(tab == nullptr);

	//Déclarations + asserts d'une image de dimensions > 0
	Image im(100, 150);
	assert(im.tab != nullptr);
	assert(im.dimx == 100);
	assert(im.dimy == 150);



	//Tests dessinerRectangle
	im.dessinerRectangle(5, 2, 54, 98, beige);
	for(unsigned int j = 2; j <= 98; ++j){
		for(unsigned i = 5; i <= 54; ++i){
			assert(im.getPix(i, j).getRouge() == beige.getRouge());
			assert(im.getPix(i, j).getVert() == beige.getVert());
			assert(im.getPix(i, j).getBleu() == beige.getBleu());
		}
	}

	dessinerRectangle(0, 0, 0, 0, vert);
	assert(tab->getRouge() == vert.getRouge());
	assert(tab->getVert() == vert.getVert());
	assert(tab->getBleu() == vert.getBleu());

	//Tests getPix
	assert(im.getPix(5, 10).getRouge() == im.tab[10*im.dimx+5].getRouge());
	assert(im.getPix(5, 10).getVert() == im.tab[10*im.dimx+5].getVert());
	assert(im.getPix(5, 10).getBleu() == im.tab[10*im.dimx+5].getBleu());
	assert(getPix(0, 0).getRouge() == tab->getRouge());
	assert(getPix(0, 0).getVert() == tab->getVert());
	assert(getPix(0, 0).getBleu() == tab->getBleu());

	//Tests setPix
	im.setPix(25, 10, vert);
	assert(im.getPix(25, 10).getRouge() == vert.getRouge());
	assert(im.getPix(25, 10).getVert() == vert.getVert());
	assert(im.getPix(25, 10).getBleu() == vert.getBleu());
	setPix(0, 0, beige);
	assert(tab->getRouge() == beige.getRouge());
	assert(tab->getVert() == beige.getVert());
	assert(tab->getBleu() == beige.getBleu());


	//Tests effacer
	im.effacer(vert);
	for(unsigned int j = 0; j < im.dimy; ++j){
		for(unsigned i = 0; i < im.dimx; ++i){
			assert(im.getPix(i, j).getRouge() == vert.getRouge());
			assert(im.getPix(i, j).getVert() == vert.getVert());
			assert(im.getPix(i, j).getBleu() == vert.getBleu());
		}
	}

	effacer(beige);
	assert(tab->getRouge() == beige.getRouge());
	assert(tab->getVert() == beige.getVert());
	assert(tab->getBleu() == beige.getBleu());
}


void Image::sauver(const std::string & filename) const {
    std::ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << std::endl;
    fichier << dimx << " " << dimy << std::endl;
    fichier << "255" << std::endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel &pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    std::cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const std::string & filename) {
    std::ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	unsigned int r, g, b;
	std::string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
	Pixel pix;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            pix.setRouge(r);
            pix.setVert(g);
            pix.setBleu(b);
            setPix(x,y,pix);
        }
    fichier.close();
    std::cout << "Lecture de l'image " << filename << " ... OK\n";
}


void Image::afficherConsole(){
    std::cout << dimx << " " << dimy << std::endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel &pix = getPix(x,y);
            std::cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        std::cout << std::endl;
    }
}


void Image::afficherInit(){
	assert(SDL_Init(SDL_INIT_VIDEO) >= 0);
	window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl; SDL_Quit(); exit(1);
    } //on cree une fenetre centree sur l ecran et de dimensions 200x200, arret si la fenetre de s'est pas creee
    surface = SDL_GetWindowSurface(window);
    if(surface == NULL){
    	std::cout << "Erreur lors de l'obtention de la surface : " << SDL_GetError() << std::endl; SDL_Quit(); exit(1);
    }
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	sauver("./data/imageAfficher.ppm"); // on sauvegarde 
	SDL_Surface *tmp = IMG_Load("./data/imageAfficher.ppm");
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	rect.x = 200/2 - dimx/2; rect.y = 200/2 - dimy/2;
	rect.w = dimx; rect.h = dimy;
	
}


void Image::afficherBoucle(){
	SDL_Event events;
	bool stop = false;
	while(!stop){
		while (SDL_PollEvent(&events)) {
			SDL_SetRenderDrawColor(renderer, 206, 206, 206, 255);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texture, NULL, &rect);
			SDL_RenderPresent(renderer);
			if (events.type == SDL_QUIT) stop = true;
			else if (events.type == SDL_KEYDOWN){
			              // Si une touche est enfoncee
				switch (events.key.keysym.scancode){
                    case SDL_SCANCODE_G: rect.w-=10; rect.h-=10;
                    rect.x+=5; rect.y +=5;
                    	break;
                    case SDL_SCANCODE_T: rect.w+=10; rect.h+=10;
                    rect.x-=5; rect.y -=5;
                    	break;
                    case SDL_SCANCODE_ESCAPE:
                    case SDL_SCANCODE_Q:
                        stop = true;
                        break;
                    default: break;
				}
			}
		}
	}
}


void Image::afficherDetruit(){
	
	remove("./data/imageAfficher.ppm");
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void Image::afficher(){
	afficherInit();
	afficherBoucle();
	afficherDetruit();
}