#ifndef FONCTION_H
#define FNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 400
#define SCREEN_H 300
typedef struct
{SDL_Surface* miniature_img;
SDL_Rect pos_minimap;
SDL_Surface * img_bonhomme;
SDL_Rect pos_bonhomme;
} minimap;
typedef struct
{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Color textColor;
    char texte[50];
} Text;
void initText(Text *t);
void freeText(Text A);
void displayText(Text t, SDL_Surface *screen);
void sauvegarder( int score, char nomjoueur[], char nomfichier[])
void meilleur( char nomfichier[], int *score, char nomjoueur[]);
void init_minimap(minimap* m);
void MAJMinimap(perso p , minimap * m, SDL_Rect camera, int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
void Liberer (minimap * m);
#endif
