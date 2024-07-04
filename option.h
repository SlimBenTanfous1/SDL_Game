#ifndef option_H_INCLUDED
#define option_H_INCLUDED

void save_volume(int volume);
int get_volume();
void save_volume_game(int volume);
int get_volume_game();
int afficher_option(SDL_Surface *screen, int *menu);
 

#endif
