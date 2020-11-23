#include "fruit.h"
#include <stdlib.h> //rand()
#include <unistd.h> //usleep
#include <iostream>
#include <time.h>
#include <ncurses.h>
//#include <ncurses.h>

fruit::fruit(){
	//rand() % (max_number + 1 - minimum_number) + minimum_number
	fruit_pos.x = rand()%74+2; //range: [2,75]
	fruit_pos.y = rand()%17+5; //range: [5,21]
}

//second constructor, set up to prevent fruit from poping up on the snake
fruit::fruit(snake* snake){
	int count =0;

	//if the fruit overlaps with the snake body, then keep looping
	while(count != snake->getSnakeLength() ){
		count = 0;

	//rand() % (max_number + 1 - minimum_number) + minimum_number
		fruit_pos.x = rand()%74+2; //range: [2,75]
		fruit_pos.y = rand()%17+5; //range: [5,21]
		//check if it overlaps
		for(int i =0; i<(snake->getSnakeLength());i++){
			if(fruit_pos.x != snake->body[i].x || fruit_pos.y != snake->body[i].y){
				count++;
			}else{
				break;
			}
		}
	}
}


position fruit::getPos(){
	return fruit_pos;
}


fruit::~fruit(){};
