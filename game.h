#ifndef GAME_H
#define GAME_H

//#include "snake.h"
#include "player.h"
#include "fruit.h"
#include "position.h"
#include <ncurses.h>

class game{


	//window for the game
	WINDOW* wnd;

public:
	player* new_player;
	fruit* new_fruit;
	snake* my_snake;

public:
	//constructor
	game();

	game(player* player);

	//run the game
	void run();

	//generate fruit
	int generateFruit();


	//check if keyboard has been pressed and also validate input
	int kbhit(int* direction);

	//destructor
	~game();
};


#endif
