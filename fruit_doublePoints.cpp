#include "fruit_doublePoints.h"
#include <ncurses.h>

fruit_doublePoints::fruit_doublePoints(snake* snake): fruit(snake){}

void fruit_doublePoints::takeEffect(player* nplayer, snake* nsnake){
	nsnake -> grow(); //increase snake length by 1
	nplayer -> setScore(2); //increase score by 2
	nsnake ->setSpeed(5); //5 is a normal speed. 1-slowest, 10 -fastest
}

char fruit_doublePoints::drawFruit(){
	mvaddch(getPos().y,getPos().x,'*');
	return '*';
}

fruit_doublePoints:: ~fruit_doublePoints(){}
