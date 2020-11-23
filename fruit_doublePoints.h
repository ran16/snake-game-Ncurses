#ifndef FRUIT_DOUBLEPOINTS_H
#define FRUIT_DOUBLEPOINTS_H

#include "fruit.h"


//child class 2: fruit_doublePoints. Effect: makes snake grow by 1 unit, make player's score increase by 1, make speed increase to 10
class fruit_doublePoints : public fruit{

public:

	fruit_doublePoints(snake* snake);
	virtual void takeEffect(player* nplayer, snake* nsnake);
	char drawFruit();

	~fruit_doublePoints();
};

#endif
