#include "header.h"



void intro (SDL_Surface **ecran)
{
	*ecran = SDL_SetVideoMode (1366,768,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("HOMELAND", NULL);

	SDL_Surface *logo=NULL, *embleme=NULL,*loading=NULL;
	SDL_Rect poslogo,posload;
	SDL_Event event;
	int i=0;


	logo=IMG_Load ("resources/image/logo.png");
	poslogo.x=350;
	poslogo.y=0;
	embleme=IMG_Load ("resources/image/embleme.png");
	loading=IMG_Load("resources/image/Loading.png");
	posload.x=1150;
	posload.y=700;

	//SDL_FillRect(*ecran, NULL, SDL_MapRGB((*ecran)->format, 0, 0, 0));

	
	while (i!=125)
	{
		//SDL_SetAlpha (logo, SDL_SRCALPHA, i);
		SDL_BlitSurface(logo, NULL, (*ecran), &poslogo);
		SDL_Flip(*ecran);
		i++;
	while (SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 			case '\r':
						i=125;
					break;
					case SDLK_ESCAPE:
						i=125;
					break;
		 	}
		 }
	}
	int x;
	poslogo.x=0;
	i=0;
		while (i!=125)
		{
			//SDL_SetAlpha (embleme, SDL_SRCALPHA, i);
			SDL_BlitSurface(embleme, NULL,(*ecran), &poslogo);
			if(i%40 ==0)
				{
					x=0;
					while(x!=250)
						{
							SDL_BlitSurface(loading, NULL,(*ecran), &posload);
							x++;
							SDL_Flip(*ecran);
						}
				}
			SDL_Delay(20);
			SDL_Flip(*ecran);
			i++;
			while (SDL_PollEvent(&event))
			switch(event.type)
			{
				case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case '\r':
					i=125;
					break;
					case SDLK_ESCAPE:
					i=125;
					break;
				}
			}
		}

	SDL_FreeSurface(logo);
	SDL_FreeSurface(embleme);
	SDL_FreeSurface(loading);
}
