#include "game.h"
#include "fruit_plus.h"
#include "fruit_speed.h"
#include "fruit_doublePoints.h"
#include <ncurses.h>
#include <stdlib.h> //for function: exit()
#include <unistd.h> //usleep()


//check if keyboard has been pressed and also validate input
int game::kbhit(int* direction)
{
	//get user input
	int temp_dir = getch();
	//check user input. When snake is moving up/down, it can only turn right/left. and vice versa
	if(*direction == KEY_UP || *direction == KEY_DOWN || *direction == 'w' || *direction == 's'){
		if(temp_dir == KEY_LEFT || temp_dir ==KEY_RIGHT || temp_dir =='a' || temp_dir == 'd'){
			*direction = temp_dir;
		}
	}
	if(*direction == KEY_LEFT || *direction == KEY_RIGHT || *direction =='a' || *direction == 'd'){
		if(temp_dir == KEY_UP || temp_dir ==KEY_DOWN ||temp_dir == 'w' || temp_dir == 's'){
			*direction = temp_dir;
		}
	}
	//if the user pressed a key, return 1
    if (temp_dir != ERR) {
        return 1;
    } else {
		//if the user didn't press any key, return 0
        return 0;
    }
}

//default constructor
game::game(){
	new_fruit = NULL;
	new_player = NULL;
	my_snake = new snake;

	//set up a window for the game
	wnd = initscr();
	cbreak();//don't stop the program while waiting for user input
	noecho();//don't print out user input
	keypad(wnd,true); //enables the reading of arrow keys
	nodelay(wnd,true); // user input are immediately available to the program
	curs_set(0); // make the cursor invisible
}

//preferred constructor
game::game(player* player){
	new_fruit = NULL;
	new_player = player;
	my_snake = new snake;

	//set up a window for the game
	wnd = initscr();
	cbreak();//don't stop the program while waiting for user input
	noecho();//don't print out user input
	keypad(wnd,true); //enables the reading of arrow keys
	nodelay(wnd,true); // user input are immediately available to the program
	curs_set(0); // make the cursor invisible

	//set up the colors of the game
	if(!has_colors()){
		endwin();
		printf("Error:theminal does not support color. \n");
		exit(1);
	}
	attron(A_BOLD);//activate an attribute for drawing(bold)
	//box(wnd, 0 ,0 ); //draw a box - it's not what I want, I don't know much about it yet and I have to work on it later.
	mvhline(3, 1, '.', 78);//top edge
	//4 parameters are: y-coordinate, x-coordinate, line style, length
	mvhline(23, 1, '.', 78);//bottom edge
	mvvline(3,1,'.',21); //left edge
	mvvline(3,78,'.',21); //right edge

	attroff(A_BOLD);//deactive attribuete(bold)
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_WHITE);
	wbkgd(wnd,COLOR_PAIR(1)); //black snake and green background


}

//generate fruit
int game::generateFruit(){
	//toss the dice
	//rand() % (max_number + 1 - minimum_number) + minimum_number
	int dice = rand()%3+1; //range:1,2,3
	switch (dice) {
		case 1:
			new_fruit = new fruit_plus(my_snake);
			break;
		case 2:
			new_fruit = new fruit_speed(my_snake);
			break;
		case 3:
			new_fruit = new fruit_doublePoints(my_snake);
			break;
	}

	return dice;
}

void game::run(){

//--------run game ----------------
	bool exit_requested = false;
	bool collided = false;

	//draw snake
	my_snake -> drawSnake();
	refresh();

	//set direction to left
	int dir = KEY_LEFT;
	//drop a fruit
	generateFruit();
	new_fruit -> drawFruit();
	refresh();

	//display score
	mvprintw(1,1,"%s","your score: 0");
	mvprintw(2,1,"%s","special fruit  s:double speed  *:double point");

	while(collided == false && exit_requested == false){

		switch (dir) {

			case KEY_LEFT: case 'a':
			while(kbhit(&dir) != 1){
				my_snake  -> moveLeft();
				refresh();

				//if snake has eaten a fruit
				if(my_snake->eatFruit(new_fruit->getPos()) == true){
					//use polymorphism to show different effets for diffrent fruits
					new_fruit -> takeEffect(new_player,my_snake);
					//update score display
					mvprintw(1,13,"%d",new_player->getScore());
					delete new_fruit;
					//generate another fruit
					generateFruit();
					new_fruit -> drawFruit();
					refresh();
				}

				//check if collided. if collided, game is over
				if(my_snake ->collide() == true){
					collided = true;
					break;
				}

				int current_speed = my_snake->getSpeed();
				usleep(500000/current_speed);
			}
			break;

			case KEY_UP: case 'w':
			while(kbhit(&dir) != 1){
				my_snake  -> moveUp();
				refresh();

				if(my_snake->eatFruit(new_fruit->getPos()) == true){
					new_fruit -> takeEffect(new_player,my_snake);
					//update score display
					mvprintw(1,13,"%d",new_player->getScore());
					delete new_fruit;
					generateFruit();
					new_fruit -> drawFruit();
					refresh();
				}

				//check if collided. if collided, game is over
				if(my_snake ->collide() == true){
					collided = true;
					break;
				}

				int current_speed = my_snake->getSpeed();
				usleep(500000/current_speed);
			}
			break;

			case KEY_RIGHT: case 'd':
			while(kbhit(&dir) != 1){
				my_snake  -> moveRight();
				refresh();

				if(my_snake->eatFruit(new_fruit->getPos()) == true){
					new_fruit -> takeEffect(new_player,my_snake);
					//update score display
					mvprintw(1,13,"%d",new_player->getScore());
					delete new_fruit;
					generateFruit();
					new_fruit -> drawFruit();
					refresh();
				}

				//check if collided. if collided, game is over
				if(my_snake ->collide() == true){
					collided = true;
					break;
				}
				int current_speed = my_snake->getSpeed();
				usleep(500000/current_speed);
			}
			break;

			case KEY_DOWN: case 's':
			while(kbhit(&dir) != 1){
				my_snake  -> moveDown();
				refresh();

				if(my_snake->eatFruit(new_fruit->getPos()) == true){
					new_fruit -> takeEffect(new_player,my_snake);
					//update score display
					mvprintw(1,13,"%d",new_player->getScore());
					delete new_fruit;
					generateFruit();
					new_fruit -> drawFruit();
					refresh();
				}

				//check if collided. if collided, game is over
				if(my_snake ->collide() == true){
					collided = true;
					break;
				}

				int current_speed = my_snake->getSpeed();
				usleep(500000/current_speed);
			}
			break;

			default:
			//exit_requested = true;
			while(kbhit(&dir) != 1){};//if user put in invalid input,do nothing


		}//finish swtich statment

	}

	//game over interface
	while(exit_requested == false){
		mvprintw(23/2,79/4,"Game Over! - Your score was: %d", new_player->getScore());
		mvprintw(23/2+1,79/4," press any key to exit");
	  	refresh();
		usleep(2000000); //display the game over message for a while before quit
		if(kbhit(&dir)){
			exit_requested = true;
		}

	}
}

game::~game(){
	delete new_fruit;
	delete my_snake;
	endwin(); // close the ncurses window and go back to normal terminal.
}
