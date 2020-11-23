#include "snake.h"

#include <ncurses.h>

#define MAXWIDTH 78
#define MAXHEIGHT 23


//constructor
snake::snake(){
	speed = 5;
	snake_length = 4;
	body = new position[snake_length]; //the body is an array of position objects, each representing a x-y coordinate
	//use for loop to build up the snake
	for(int i=0; i<snake_length;i++){
		body[i] = position(12,40+i); //At the beginning of the game, the first part of the body is in (12,40) position(because default terminal window size is 24x80),and the rest of the body follows horizontally.
	}
}


void snake::drawSnake(){
	//draw head
	mvaddch(body[0].y, body[0].x-1, '<');
	for(int i=0; i<snake_length; i++){
		//printw("%d", getYpos());
		mvaddch(body[i].y, body[i].x, 'o');
	}
}




void snake::moveLeft(){
	//replace the tail with a ' '
	mvaddch(body[snake_length-1].y, body[snake_length-1].x, ' ');

	//move cursor to the left of the snake head, and draw a "o"
	mvaddch(body[0].y, body[0].x, 'o');

	//draw head
	mvaddch(body[0].y, body[0].x-1, '<');

	//update the coordinates:abandon last element, update the fist element, and shift all the elements in the middle to a higer index
	for(int i=snake_length-1; i>0; i--){
		body[i].y = body[i-1].y;
		body[i].x = body[i-1].x;
	}
	body[0].x = body[1].x - 1;
	body[0].y = body[1].y;
}

void snake::moveUp(){
	//replace the tail with a ' '
	mvaddch(body[snake_length-1].y, body[snake_length-1].x, ' ');

	//move cursor to the top of the snake head, and draw a "o"
	mvaddch(body[0].y, body[0].x, 'o');

	//draw head
	mvaddch(body[0].y-1, body[0].x, '^');

	//update the coordinates:abandon last element, update the fist element, and shift all the elements in the middle to a higer index
	for(int i=snake_length-1; i>0; i--){
		body[i].y = body[i-1].y;
		body[i].x = body[i-1].x;
	}
	body[0].y = body[1].y - 1;
	body[0].x = body[1].x;
}

void snake::moveRight(){
	//replace the tail with a ' '
	mvaddch(body[snake_length-1].y, body[snake_length-1].x, ' ');

	//move cursor to the right of the snake head, and draw a "o"
	mvaddch(body[0].y, body[0].x, 'o');

	//draw head
	mvaddch(body[0].y, body[0].x+1, '>');

	//update the coordinates:abandon last element, update the fist element, and shift all the elements in the middle to a higer index
	for(int i=snake_length-1; i>0; i--){
		body[i].y = body[i-1].y;
		body[i].x = body[i-1].x;
	}
	body[0].x = body[1].x + 1;
	body[0].y = body[1].y;
}

void snake::moveDown(){
	//replace the tail with a ' '
	mvaddch(body[snake_length-1].y, body[snake_length-1].x, ' ');

	//move cursor under snake head, and draw a "o"
	mvaddch(body[0].y, body[0].x, 'o');

	//draw head
	mvaddch(body[0].y+1, body[0].x, 'v');

	//update the coordinates:abandon last element, update the fist element, and shift all the elements in the middle to a higer index
	for(int i=snake_length-1; i>0; i--){
		body[i].y = body[i-1].y;
		body[i].x = body[i-1].x;
	}
	body[0].y = body[1].y+1;
	body[0].x = body[1].x;
}

//make snake body grow longer by 1 unit
void snake::grow(){

	snake_length++; //increase body length

	//make a new body
	position* new_body = new position[snake_length];
	//copy the old body to new body
	for(int i=0; i<snake_length-2; i++){
		new_body[i] = body[i];
	}
	//save the location of the tail as the last element of the new body
	new_body[snake_length-1] = position(body[snake_length-2].y, body[snake_length-2].x);

	//free old body
	delete [] body;

	//assign the address of new body to old body.
	body = new_body;
}

//get the position of head
position snake::getHeadPos(){
	position headPos = position(body[0].y, body[0].x);
	return headPos;
}

bool snake::collide(){

	if(getHeadPos().x <=1 || getHeadPos().x >= MAXWIDTH || getHeadPos().y <=3 || getHeadPos().y >= MAXHEIGHT){
		return true;
	}

	for(int i=1; i < snake_length; i++){
		if(getHeadPos().x == body[i].x && getHeadPos().y == body[i].y){
			return true;
		}
	}

	return false;

}

//eat fruit
bool snake::eatFruit(position npos){
	if(getHeadPos().y == npos.y && getHeadPos().x == npos.x){
		return true;
	}else{
		return false;
	}
}

int snake::getSnakeLength(){
	return snake_length;
}

//set speed
void snake::setSpeed(int num){
	speed = num;
}

//get speed
int snake::getSpeed(){
	return speed;
}

//destructor
snake::~snake(){
	delete [] body;
}
