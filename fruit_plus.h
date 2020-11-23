#ifndef FRUIT_PLUS_H
#define FRUIT_PLUS_H

#include "fruit.h"


//child class 1: fruit_plus. Effect: makes snake grow by 1 unit
class fruit_plus : public fruit{

public:

	fruit_plus(snake* snake);

	virtual void takeEffect(player* nplayer, snake* nsnake);
	char drawFruit();

	~fruit_plus();
};

#endif
