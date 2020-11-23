#ifndef FRUIT_SPEED_H
#define FRUIT_SPEED_H

#include "fruit.h"


//child class 2: fruit_seed. Effect: makes snake grow by 1 unit, make player's score increase by 1, make speed increase to 10
class fruit_speed : public fruit{

public:

	fruit_speed(snake* snake);
	virtual void takeEffect(player* nplayer, snake* nsnake);
	char drawFruit();

	~fruit_speed();
};

#endif
