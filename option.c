#include "header.h"


void save_volume(int volume)
{
    FILE *fichier = NULL;
    fichier = fopen("resources/file/volume.txt", "w");
    fprintf(fichier, "%d", volume);
    fclose(fichier);
}

void save_volume_game(int volume)
{
    FILE *fichier = NULL;
    fichier = fopen("resources/file/volumegame.txt", "w");
    fprintf(fichier, "%d", volume);
    fclose(fichier);
}

int get_volume()
{
    int volume;
    FILE *fichier = NULL;
    fichier = fopen("resources/file/volume.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", &volume);
    fclose(fichier);
    return volume;
}

int get_volume_game()
{
    int volume;
    FILE *fichier = NULL;
    fichier = fopen("resources/file/volumegame.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", &volume);
    fclose(fichier);
    return volume;
}

int afficher_option(SDL_Surface *screen, int *menu)
{
    int sng = 0, scr = 0, sex = 0, sop = 0, x, y,i;
    int volum = get_volume();
    int volumg = get_volume_game();

    int hb = 100, //Button Height100
        lb = 300, //Button Width300
        bs = 100,
        vol_width = 300;

    Mix_Chunk *music1;
    Mix_AllocateChannels(2);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");

    Mix_Music *music;
    music = Mix_LoadMUS("resources/sound/music.mp3");
    Mix_VolumeMusic(volum);
    Mix_PlayMusic(music, -1);//tasti lena

    //background creation
    SDL_Surface *background = NULL;
    background = IMG_Load("resources/image/optionback.png");
    SDL_Surface *option = NULL;
    option = IMG_Load("resources/image/OPTIONS.png");
    SDL_Surface *volumetxt[2];
    volumetxt[0] = IMG_Load("resources/image/menumusic.png");
    volumetxt[1] = IMG_Load("resources/image/menumusic1.png");
    SDL_Surface *volumetxt_game[2];
    volumetxt_game[0] = IMG_Load("resources/image/gamemusic.png");
    volumetxt_game[1] = IMG_Load("resources/image/gamemusic1.png");
    // get back pos
    SDL_Rect background_pos={0,0};
    SDL_Rect option_pos={100,50};

    //chargement de la nouvelle souris
    SDL_Surface *mouse2 = IMG_Load("resources/image/curseur3.png");
    SDL_Rect pos_mouse2;

    //volume button creation
    SDL_Surface *volume[6];
    SDL_Surface *volumegame[6];
    volume[0] = IMG_Load("resources/image/volume0.png");
    volume[1] = IMG_Load("resources/image/volume1.png");
    volume[2] = IMG_Load("resources/image/volume2.png");
    volume[3] = IMG_Load("resources/image/volume3.png");
    volume[4] = IMG_Load("resources/image/volume4.png");
    volume[5] = IMG_Load("resources/image/volume5.png");
    volumegame[0] = IMG_Load("resources/image/volume0.png");
    volumegame[1] = IMG_Load("resources/image/volume1.png");
    volumegame[2] = IMG_Load("resources/image/volume2.png");
    volumegame[3] = IMG_Load("resources/image/volume3.png");
    volumegame[4] = IMG_Load("resources/image/volume4.png");
    volumegame[5] = IMG_Load("resources/image/volume5.png");
    int vl = 0, v = 0;
    int vg = 0;
    int vl2=0;
    
    //volume button pos
    SDL_Rect volume_pos={300,180};//volume twil
    SDL_Rect volume_posgame ={300,268};//volume twil ta3 l game
    SDL_Rect volumetxt_pos={50,300};//voulme
    SDL_Rect volumetxt_posgame ={73,450};//gamevoulme

    //fullscreen button creation
    SDL_Surface *full[3];
    full[0] = IMG_Load("resources/image/button_full.png");
    full[1] = IMG_Load("resources/image/button_full2.png");
    full[2] = IMG_Load("resources/image/button_full1.png");
    int fl = 0;
    //fullscreen button pos
    SDL_Rect full_pos;
    full_pos.x = 550;
    full_pos.y = volume_posgame.y + 360;

    //back button creation
    SDL_Surface *back[3];
    back[0] = IMG_Load("resources/image/button_back.png");
    back[1] = IMG_Load("resources/image/button_back2.png");
    back[2] = IMG_Load("resources/image/button_back1.png");
    int ba = 0;
    //back button pos
    SDL_Rect back_pos;
    back_pos.x = 1000;
    back_pos.y = 100 ;

    SDL_Rect volumemenu_pos={100,250};
    int t = 0;
    SDL_Event event;
    int done = 1;
    while (done)
    {
        t = 0;


        SDL_GetMouseState(&x, &y);
        pos_mouse2.x = x;
        pos_mouse2.y = y;
        while (SDL_PollEvent(&event))
        {
            v=volum/25;
            vg=volumg/25;
            switch(event.type)
            {
            case SDL_QUIT:
                done = 0;
                break;
            

            //with keyboard
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    /*****************************************************************************************************/
                
                case SDLK_ESCAPE:
                    done = 0;
                    *menu=-1;
                break;

                case SDLK_F4:
                        done = 0;
                        *menu = -1;
                break;
                    
                case SDLK_UP: //upper arrow
                    if (vl == 0 && fl == 0 && ba == 0 && vl2==0)
                    {
                        ba = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (vl == 1 && t == 0)
                    {
                        ba = 1;
                        vl = 0;
                        fl = 0;
                        vl2= 0; 
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                        
                    }
                    else if (ba == 1 && t == 0)
                    {
                        fl = 1;
                        vl = 0;
                        ba = 0;
                        vl2 = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (fl == 1 && t == 0)
                    {
                        fl = 0;
                        vl = 0;
                        vl2 = 1;
                        ba = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (vl2 == 1 && t == 0)
                    {
                        fl = 0;
                        vl = 1;
                        vl2 = 0;
                        ba = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }

                    break;
                    /*****************************************************************************************************/
                case SDLK_DOWN: //lower arrow
                    if (vl == 0 && fl == 0 && ba == 0 && vl2==0)
                    {
                        vl = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (vl == 1 && t == 0)
                    {
                        ba = 0;
                        vl = 0;
                        vl2= 1;
                        fl = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (fl == 1 && t == 0)
                    {
                        fl = 0;
                        vl = 0;
                        vl2=0;
                        ba = 1;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (ba == 1 && t == 0)
                    {
                        ba = 0;
                        fl = 0;
                        vl = 1;
                        vl2= 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (vl2 == 1 && t == 0)
                    {
                        ba = 0;
                        fl = 1;
                        vl = 0;
                        vl2 = 0;
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }

                    break;

                    /*****************************************************************************************************/
                case SDLK_RETURN: //enter
                    if (fl == 1)
                    {
                        screen = SDL_SetVideoMode(1440, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                    }
                    else if (ba == 1)
                    {
                        done = 0;
                    }
                    break;
                    /*****************************************************************************************************/
                case SDLK_RIGHT: //raise volume
                    if (volum <= 125 && vl == 1)
                    {
                        volum += 25;
                        Mix_VolumeMusic(volum);
                    }
                    if (volumg <= 125 && vl2 == 1)
                    {
                        volumg += 25;
                        Mix_VolumeMusic(volum);
                    }
                    break;
                    /*****************************************************************************************************/
                case SDLK_LEFT: //lower volume
                    if (volum >= 0 && vl == 1)
                    {
                        volum -= 25;
                        if(volum==0)
                            volum=0;
                        Mix_VolumeMusic(volum);
                    }
                    if (volumg >= 0 && vl2 == 1)
                    {
                        volumg -= 25;
                        Mix_VolumeMusic(volum);
                    }
                    break;


                }

                /*****************************************************************************************************/


            } //fin switch event
        }     //fin pollevent

        //afficher
        //SDL_FillRect(screen, NULL, SDL_MapRGB((screen)->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, screen, &background_pos);
        SDL_BlitSurface(option, NULL, screen, &option_pos);
        SDL_BlitSurface(volume[v], NULL, screen, &volume_pos);
        SDL_BlitSurface(volumetxt[vl], NULL, screen, &volumetxt_pos);
        SDL_BlitSurface(volumetxt_game[vl2], NULL, screen, &volumetxt_posgame);
        SDL_BlitSurface(volumegame[vg], NULL, screen, &volume_posgame);
        SDL_BlitSurface(full[fl], NULL, screen, &full_pos);
        SDL_BlitSurface(back[ba], NULL, screen, &back_pos);
        SDL_BlitSurface(mouse2, NULL, screen, &pos_mouse2);
        SDL_Flip(screen);

    } //fin while done

    save_volume(volum);
    save_volume_game(volumg);
    Mix_FreeChunk(music1);
    Mix_FreeMusic(music);
    SDL_FreeSurface(background);
    SDL_FreeSurface(option);
    SDL_FreeSurface(mouse2);

    for(i=0;i<6;i++)
    {
        SDL_FreeSurface(volume[i]);
        SDL_FreeSurface(volumegame[i]);
    }
    for(i=0;i<3;i++)
    {
        SDL_FreeSurface(full[i]);
    }
    for(i=0;i<3;i++)
    {
        SDL_FreeSurface(back[i]);
    }
    for(i=0;i<2;i++)
    {
        SDL_FreeSurface(volumetxt[i]);
        SDL_FreeSurface(volumetxt_game[i]);
    }
    TTF_Quit();
} 