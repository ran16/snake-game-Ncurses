#include "fruit_speed.h"
#include <ncurses.h>

fruit_speed::fruit_speed(snake* snake) : fruit(snake){}

void fruit_speed::takeEffect(player* nplayer, snake* nsnake){
	nsnake -> grow(); //increase snake length by 1
	nplayer -> setScore(1); //increase score by 1
	nsnake ->setSpeed(10); //5 is a normal speed. 1-slowest, 10 -fastest
}

char fruit_speed::drawFruit(){
	mvaddch(getPos().y,getPos().x,'s');
	return 's';
}

fruit_speed:: ~fruit_speed(){}
