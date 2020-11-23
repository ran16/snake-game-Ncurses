#include "fruit_plus.h"
#include <ncurses.h>

fruit_plus::fruit_plus(snake* snake) : fruit(snake){}

void fruit_plus::takeEffect(player* nplayer, snake* nsnake){
	nsnake -> grow(); //increase snake length by 1
	nplayer -> setScore(1); //increase score by 1
	nsnake ->setSpeed(5); //5 is a normal speed. 1-slowest, 10 -fastest
}

char fruit_plus::drawFruit(){
	mvaddch(getPos().y,getPos().x,'+');
	return '+';
}

fruit_plus:: ~fruit_plus(){}
