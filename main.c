#include "header.h"

int main()
{
    int hauteur_fenetre = 900,
        largeur_fenetre = 1440;
        
     
    int I;
	int o;

	SDL_Surface *ecran = NULL;
	intro(&ecran);

 
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("HOMELAND",NULL);
    //afficher le menu
    int menu=-1;

    do
    {
	    menu=afficher_menu(screen);
     switch (menu)
	   {
		case 1:
            affiche_pic(screen,&menu);				
		break;

		case 2:
			afficher_option(screen,&menu);
		break;

        case 3:
            afficher_credit(screen,&menu);
        break;
            
        case 4:
 			quitter(screen,&menu);
        break;

	}

    }
    while (menu!=0);

    SDL_Quit();

    return 0;
}
