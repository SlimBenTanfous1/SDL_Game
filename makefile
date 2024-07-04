prog : main.o fonction.o intro.o quitter.o option.o play.o credits.o
	gcc -o prog main.o option.o fonction.o intro.o play.o quitter.o credits.o -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o : main.c
	gcc -o main.o -c main.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
fonction.o : fonction.c
	gcc -o fonction.o -c fonction.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
intro.o : intro.c
	gcc -o intro.o -c intro.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
quitter.o : quitter.c
	gcc -o quitter.o -c quitter.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
option.o : option.c
	gcc -o option.o -c option.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
play.o: play.c
	gcc -o play.o -c play.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
credits.o: credits.c
	gcc -o credits.o -c credits.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g


