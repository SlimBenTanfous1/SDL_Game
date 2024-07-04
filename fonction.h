#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
    
typedef struct {
    SDL_Surface *galaxy ; // puts in galaxy
    SDL_Rect galaxy_pos; // cursor pos on window
    SDL_Rect animation[8];
    int frame; // goes within all array0 cases
    int show;
}curseur ;

void init_tab_anim(SDL_Rect* clip); //fill animation array
void initialiser (curseur *p, int xmouse, int ymouse) ;
void afficher_curseur(curseur  * p , SDL_Surface *screen);
void animation(curseur  *p);
void mvt_curseur_x(curseur *p, int xmouse);
void mvt_curseur_y(curseur *p, int ymouse);
void remplir_animation_cloud(SDL_Rect *poscloud1,SDL_Rect *poscloud2,SDL_Rect *poscloud3, SDL_Surface **cloud1,SDL_Surface **cloud2,SDL_Surface **cloud3);
void positioncloud(SDL_Rect *poscloud1,SDL_Rect *poscloud2,SDL_Rect *poscloud3, int *direction,int *direction2,int *direction3);
int afficher_menu(SDL_Surface *screen);
int ecran_jeu (SDL_Surface *screen);
void afficher_copyright(SDL_Surface *screen,TTF_Font *police);

#endif //
