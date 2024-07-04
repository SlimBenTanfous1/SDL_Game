#ifndef ENIGMEPIC_H_INCLUDED
#define ENIGMEPIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>

typedef struct{
	SDL_Surface *background;
    SDL_Surface *question_img;
	SDL_Surface *time[52];
    SDL_Surface *button[3];//repons

	int pos_selected;
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2;
	SDL_Rect pos_reponse3;

	int num_question;
	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;

	int vrai_reponse;
	int positionVraiReponse;
	Mix_Chunk *sound;
}enigme;

void initenigme(enigme *e);
void afficher_enigme(enigme *e,SDL_Surface *escreen);
void animer(enigme *e);

#endif
