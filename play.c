#include "header.h"

void affiche_pic(SDL_Surface *screen,int *menu)
   {

   
SDL_Surface *image = NULL;

	SDL_Rect pos;
	SDL_Event event;
	int continuer = 1;
	int i;


 
	image = IMG_Load("resources/image/play_background.png");

    pos.x = 0;
    pos.y = 0;

    while(continuer)
    {

    	if(SDL_PollEvent(&event))
    	{
    		switch(event.type)
    		{
    			case SDL_QUIT:
                continuer = 0;
                *menu = -1;
                break;
                case SDL_KEYDOWN:   //keyboard buttons
                switch (event.key.keysym.sym) 
                {
                	
                	case SDLK_ESCAPE:
                        continuer = 0;
                        *menu = -1;
                	break;

                    case SDLK_F4:
                        continuer = 0;
                        *menu = -1;
                	break;

                	
                }
            

    		}
    	}

    	SDL_BlitSurface(image,NULL,screen,&pos);
    	SDL_Flip(screen);

    }
  
    SDL_FreeSurface(image);
    
}