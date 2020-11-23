#ifndef FRUIT_H
#define FRUIT_H

#include "position.h"
#include "snake.h"
#include "player.h"


class fruit{

	position fruit_pos;

public:
	fruit();
	fruit(snake* snake);

	virtual void takeEffect(player* nplayer, snake* nsnake) = 0;
	virtual char drawFruit() = 0;
	position getPos();

	virtual ~fruit();

};



#endif
