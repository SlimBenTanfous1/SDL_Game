#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
        SDL_Surface *image;
        SDL_Rect poscam,poscam2,pos,pos2;
        Mix_Music *music;
    }backgroundm;

void initBack(backgroundm *b);
void afficherBack(backgroundm b, SDL_Surface * screen);
void scrolling(backgroundm * b, int direction);
void animerBackground( backgroundm* e);
int collisionPP(personne p, SDL_Surface * Masque);


#endif
