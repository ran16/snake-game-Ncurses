#ifndef SNAKE_H
#define SNAKE_H

#include "position.h"


class snake{

	int snake_length;
	int speed; //5 is default speed. 1-slowest, 10 -fastest
public:
	position* body;

public:
	//constructor
	snake();

	//draw snake
	void drawSnake();

	//move
	void moveLeft();
	void moveUp();
	void moveRight();
	void moveDown();

	//get the position of head
	position getHeadPos();

	void grow();

	//check if collide
	bool collide();

	//eat fruit
	bool eatFruit(position npos);

	//get snake snake_length
	int getSnakeLength();

	//set speed
	void setSpeed(int num);

	//get speed
	int getSpeed();




	//destructor
	~snake();

};


#endif
