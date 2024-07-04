#include "header.h"


int s_anFrame2 = 0;
//Coordonnées polaires -> coordonnées cartésiennes
void PolarCoords(int rad, int angle, s16 *x, s16 *y)
{
    *x = rad * cos((angle * M_PI) / 180) + 430;//530
    *y = rad * (-sin((angle * M_PI) / 180));//180
    *y=*y+400;//up and down
}

void remplir_animation_cloud(SDL_Rect *poscloud1,SDL_Rect *poscloud2,SDL_Rect *poscloud3, SDL_Surface **cloud1,SDL_Surface **cloud2,SDL_Surface **cloud3)
{
	(*cloud1)=IMG_Load("resources/image/cloud1.png");
	(*cloud2)=IMG_Load("resources/image/cloud2.png");
	(*cloud3)=IMG_Load("resources/image/cloud3.png");
	
	poscloud1->x=10;
    poscloud1->y=0;
    poscloud2->x=500;
    poscloud2->y=200;
    poscloud3->x=700;
    poscloud3->y=120;
}

void positioncloud(SDL_Rect *poscloud1,SDL_Rect *poscloud2,SDL_Rect *poscloud3, int *direction,int *direction2,int *direction3)
{
    poscloud1->x=poscloud1->x+(*direction);
    if(poscloud1->x==500 || poscloud1->x==10)//500 10
        (*direction)=-(*direction);
    poscloud2->x=poscloud2->x+(*direction2);
    if(poscloud2->x==500 || poscloud2->x==700)//500 700
        (*direction2)=-(*direction2);
    poscloud3->x=poscloud3->x+(*direction3);
    if(poscloud3->x==700 || poscloud3->x==1250)//700 1250
        (*direction3)=-(*direction3);
}
//affiche copyright
void afficher_copyright(SDL_Surface *screen,TTF_Font *police)
{
     char copyr[40];
     SDL_Surface *copytxt=NULL;
     SDL_Rect pos={1050,15};

    SDL_Color coleurwhite = {250, 250, 250};
    
    sprintf(copyr,"Copyright all rights reserved.");//tthe thing to print in screen

    copytxt = TTF_RenderText_Blended(police,copyr,coleurwhite);

    SDL_BlitSurface(copytxt, NULL, screen, &pos); /* Blit du texte */

}

int  afficher_menu(SDL_Surface *screen)
{
	int direction=1, direction2=1, direction3=1;
    SDL_Surface *cloud1=NULL, *cloud2=NULL, *cloud3=NULL;
    SDL_Rect poscloud1, poscloud2, poscloud3;
 
    int volume = get_volume();
    int hb = 40, //Button height 30
        lb = 160, //Button length 
        bs = 50;  //Button Space
    int fps = 0;
    int f = 0;
    int tmp = 0, m = 0;
    //copyright
    TTF_Init();

    TTF_Font *police = NULL;
    police = TTF_OpenFont("resources/SFPRODISPLAYMEDIUM.ttf", 20);
    

    //mouse click sound
    Mix_Chunk *music1, *music2;
    Mix_AllocateChannels(1);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
    music2 = Mix_LoadWAV("resources/sound/ClicDeSouris2.wav");

    //init back music
    Mix_Music *music;
    music = Mix_LoadMUS("resources/sound/music.mp3");
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music, -1);

    //titre creation
    static SDL_Surface *titre = NULL;
    titre = IMG_Load("resources/image/title.png");
    //titre pos
    SDL_Rect pos_titre;
    pos_titre.x = 450;
    pos_titre.y = 370;
    //chargement de la nouvelle souris
    SDL_Surface *mouse2 = IMG_Load("resources/image/curseur3.png");
    SDL_Rect pos_mouse2;

    //background creation
    SDL_Surface *background = NULL;
    background = IMG_Load("resources/image/menuback.png");
    //background pos determin
    SDL_Rect background_pos;
    background_pos.x = 0;
    background_pos.y = 0;

    //start button creation
    SDL_Surface *start[2];
    start[0] = IMG_Load("resources/image/button_start.png");
    start[1] = IMG_Load("resources/image/button_start2.png");
    int ng = 0;
    //start button position
    SDL_Rect start_pos;
    start_pos.x = 250;
    start_pos.y = 650;
   
    //option button creation
    SDL_Surface *setting[2];
    setting[0] = IMG_Load("resources/image/button_settings.png");
    setting[1] = IMG_Load("resources/image/button_settings2.png");
    int op = 0;
    //option button position
    SDL_Rect setting_pos;
    setting_pos.x = 500;
    setting_pos.y = 650;

    //credits button creation
    SDL_Surface *credit[2];
    credit[0] = IMG_Load("resources/image/bonus nonenfonce.png");
    credit[1] = IMG_Load("resources/image/bonus enfonce.png");
    int cr = 0;
    //credits button position
    SDL_Rect credit_pos;
    credit_pos.x = 750;
    credit_pos.y = 650;
    

    //quit button creation
    SDL_Surface *quit[2];
    quit[0] = IMG_Load("resources/image/button_quit.png");
    quit[1] = IMG_Load("resources/image/button_quit2.png");
    int ex = 0;
    //quit button position
    SDL_Rect quit_pos;
    quit_pos.x = 1000;
    quit_pos.y = 650;

    int xmouse = 700, ymouse = 500;
    int sng = 0, scr = 0, sex = 0, sop = 0;
    //cursor creation
    curseur c;
    initialiser(&c, xmouse, ymouse);

    int t1 = 0, t2 = 0, r = 0;

    int t = 0;
    SDL_Event event;
    int done = 1;
    remplir_animation_cloud(&poscloud1,&poscloud2,&poscloud3, &cloud1,&cloud2,&cloud3);
    while (done)

    {
		positioncloud(&poscloud1,&poscloud2,&poscloud3,&direction,&direction2,&direction3);
        t = 0;
        SDL_ShowCursor(0);
        SDL_GetMouseState(&xmouse, &ymouse);
        pos_mouse2.x = xmouse;
        pos_mouse2.y = ymouse;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            /*****************************************************************************************************/
            case SDL_QUIT:
                done = 0;
		    return 4;
                break;
            /*****************************************************************************************************/
            case SDL_KEYDOWN: //keyboard buttons
                c.show = 0;
                switch (event.key.keysym.sym)
                {
                    /*****************************************************************************************************/
                case SDLK_F4: //f4
                    done = 0;
			return 4;
            case SDLK_ESCAPE: //f4
                    done = 0;
			return 4;

                    break;
                    /*****************************************************************************************************/
                case SDLK_LEFT: //left 

                    if (ng == 0 && op == 0 && cr == 0 && ex == 0)
                    {
                        ex = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (ng == 1 && t == 0)
                    {
                        ex = 1;
                        ng = 0;
                        op = 0;
                        cr = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }

                    else if (op == 1 && t == 0)
                    {
                        ng = 1;
                        op = 0;
                        cr = 0;
                        ex = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (cr == 1 && t == 0)
                    {
                        op = 1;
                        ng = 0;
                        cr = 0;
                        ex = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (ex == 1 && t == 0)
                    {
                        cr = 1;
                        op = 0;
                        ex = 0;
                        ng = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
                    /*****************************************************************************************************/
                case SDLK_RIGHT: //right
                    if (ng == 0 && op == 0 && cr == 0 && ex == 0)
                    {
                        ng = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (ng == 1 && t == 0)
                    {
                        ex = 0;
                        ng = 0;
                        op = 1;
                        cr = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }

                    else if (op == 1 && t == 0)
                    {
                        ng = 0;
                        op = 0;
                        cr = 1;
                        ex = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (cr == 1 && t == 0)
                    {
                        ng = 0;
                        op = 0;
                        cr = 0;
                        ex = 1;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (ex == 1 && t == 0)
                    {
                        ng = 1;
                        op = 0;
                        cr = 0;
                        ex = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
                    /*****************************************************************************************************/
                case SDLK_RETURN: //enter
                    if (ng == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(100);
                        return 1;
                    }

                    else if (op == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(100);
                        return 2;
                    }
                    else if (cr == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(100);
                        return 3;
                    }
                    else if (ex == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(100);
                        return 4;
                    }
                    break;
                    /*****************************************************************************************************/
                case SDLK_F12: //raise volume
                    if (volume < 99)
                    {
                        volume += 33;
                        Mix_VolumeMusic(volume);
                        save_volume(volume);
                    }
                    break;
                    SDL_Flip(screen);
                    /*****************************************************************************************************/
                case SDLK_F11: //lower volume
                    if (volume > 0)
                    {
                        volume -= 33;
                        Mix_VolumeMusic(volume);
                        save_volume(volume);
                    }
                    break;
                    SDL_Flip(screen);
                    /*****************************************************************************************************/
                case SDLK_F10: //deafen
                    if (m == 0)
                    {
                        tmp = volume;
                        volume = 0;
                        m = 1;
                    }
                    else if (m == 1)
                    {
                        volume = tmp;
                        m = 0;
                    }
                    Mix_VolumeMusic(volume);
                    save_volume(volume);
                    break;
                    SDL_Flip(screen);
                    /*****************************************************************************************************/
                case SDLK_F8: //full screen
                    if (f == 0)
                    {
                        screen = SDL_SetVideoMode(1440, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        f = 1;
                        //badel full screen 9ad kober l ecran
                    }
                    else if (f == 1)
                    {
                        screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        f = 0;
                        //badel windowed
                    }
                    break;
                }
                break;
            /*****************************************************************************************************/
            
            
            case SDL_MOUSEMOTION: //with mouse
                c.show = 1;
                ex = 0;
                ng = 0;
                op = 0;
                cr = 0;

                if (event.motion.x > start_pos.x && event.motion.y > start_pos.y && event.motion.x < start_pos.x + lb && event.motion.y < start_pos.y + hb)
                {

                    ng = 1;
                    sng++;
                    if (sng == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sop = 0;
                    scr = 0;
                    sex = 0;
                }

                if (event.motion.x > setting_pos.x && event.motion.y > setting_pos.y && event.motion.x < setting_pos.x + lb && event.motion.y < setting_pos.y + hb)
                {
                    op = 1;
                    sop++;
                    if (sop == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sng = 0;
                    scr = 0;
                    sex = 0;
                }

                if (event.motion.x > credit_pos.x && event.motion.y > credit_pos.y && event.motion.x < credit_pos.x + lb && event.motion.y < credit_pos.y + hb)
                {
                    cr = 1;
                    scr++;
                    if (scr == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sng = 0;
                    sop = 0;
                    sex = 0;
                }

                if (event.motion.x > quit_pos.x && event.motion.y > quit_pos.y && event.motion.x < quit_pos.x + lb && event.motion.y < quit_pos.y + hb)
                {
                    ex = 1;
                    sex++;
                    if (sex == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sng = 0;
                    sop = 0;
                    scr = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (ng == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(500);
                        return 1;
                    }

                    else if (op == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(500);
                        return 2;
                    }
                    else if (cr == 1)
                    {

                        Mix_PlayChannel(-1, music2, 0);
                        SDL_Delay(500);
                        return 3;
                    }
                    else if (ex == 1)
                    {
                        Mix_PlayChannel(-1, music2, 0);
                        //SDL_Delay(600);
                        return 4;
                    }
                }
                break;

            } //switch event end
        }     //pollevent end

        //show background
        SDL_BlitSurface(background, NULL, screen, &background_pos);
        SDL_BlitSurface(quit[ex], NULL, screen, &quit_pos);
        SDL_BlitSurface(start[ng], NULL, screen, &start_pos);
        SDL_BlitSurface(setting[op], NULL, screen, &setting_pos);
        SDL_BlitSurface(credit[cr], NULL, screen, &credit_pos);
        SDL_BlitSurface(cloud1, NULL, screen, &poscloud1);

    SDL_BlitSurface(cloud2, NULL, screen, &poscloud2);
	SDL_BlitSurface(cloud3, NULL, screen, &poscloud3);

        afficher_copyright(screen,police);

        //cursor
        //ziwziw 3asfour fou9 chajra :) 
        mvt_curseur_x(&c, xmouse);
        mvt_curseur_y(&c, ymouse);

        //Animation du titre

        PolarCoords(24, s_anFrame2, &pos_titre.x, &pos_titre.y);
        SDL_BlitSurface(titre, NULL, screen, &pos_titre);

        s_anFrame2 = (s_anFrame2 + 10) % 360;

        if (c.show)
            afficher_curseur(&c, screen);
        SDL_BlitSurface(mouse2, NULL, screen, &pos_mouse2);

        SDL_Flip(screen);

    } //while end

    Mix_FreeChunk(music1);
    Mix_FreeChunk(music2);
    SDL_FreeSurface(background);
    SDL_FreeSurface(start[0]);
    SDL_FreeSurface(start[1]);
    SDL_FreeSurface(setting[0]);
    SDL_FreeSurface(setting[1]);
    SDL_FreeSurface(credit[0]);
    SDL_FreeSurface(credit[1]);
    SDL_FreeSurface(quit[0]);
    SDL_FreeSurface(quit[1]);
    SDL_FreeSurface(mouse2);
    SDL_FreeSurface(cloud1);
    SDL_FreeSurface(cloud2);
    SDL_FreeSurface(cloud3);

    TTF_CloseFont(police);
    TTF_Quit(); 
}

int nb_frames = 9;
void init_tab_anim(SDL_Rect *clip)
{

    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 60;
    clip[0].h = 65;
    int i = 1;
    for (i = 1; i < nb_frames; i++)
    {
        clip[i].w = 60;
        clip[i].h = 65;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }
}

void initialiser(curseur *p, int xmouse, int ymouse)
{
    p->galaxy = IMG_Load("resources/image/crow.png");
    p->galaxy_pos.x = xmouse;
    p->galaxy_pos.y = ymouse;
    p->galaxy_pos.w = 60;
    p->galaxy_pos.h = 65;
    p->show = 1;
    init_tab_anim(p->animation);
    p->frame = 0;
}
void afficher_curseur(curseur *p, SDL_Surface *screen)
{
    SDL_BlitSurface(p->galaxy, &p->animation[p->frame], screen, &p->galaxy_pos);
}
void animation(curseur *p)
{
    p->frame++; //advance to next frame
                //frame 0 -> 8
    if (p->frame < 0 || p->frame > nb_frames - 1)
        p->frame = 0;
}

void mvt_curseur_x(curseur *p, int xmouse)
{

    animation(p);
    if (p->galaxy_pos.x + p->galaxy_pos.w < xmouse)
        p->galaxy_pos.x += 5;
    if (p->galaxy_pos.x > xmouse)
        p->galaxy_pos.x -= 5;
}

void mvt_curseur_y(curseur *p, int ymouse)
{

    animation(p);

    if (p->galaxy_pos.y > ymouse)
        p->galaxy_pos.y -= 5;
    if (p->galaxy_pos.y + p->galaxy_pos.h < ymouse)
        p->galaxy_pos.y += 5;
}
