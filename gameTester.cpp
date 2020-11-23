#include "game.h"
#include "player.h"
#include <iostream>
#include <ctime> // srand()

using namespace std;




int main(){
	srand(time(NULL));
	game* test = NULL;
	int direction = 'w';

	//test1-1 test method kbhit(&direction) test input: a
	test = new game();
	int key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'a'){
		cout << "Failed test1-1!" << endl;
	}

	//test1-2 test method kbhit(&direction) test boundry case: change from going up('w') to down('s'), such instruction will be ignored
	test = new game();
	direction = 'w';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'w'){
		cout << "Failed test1-2!"<< endl;
	}

	//test1-3 test method kbhit(&direction) test boundry case: change from going left('a') to right('d'), such instruction will be ignored
	test = new game();
	direction = 'a';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'a'){
		cout << "Failed test1-3!"<<  endl;
	}

	//test1-4 test method kbhit(&direction) test boundry case: space
	test = new game();
	direction = 's';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 's'){
		cout << "Failed test1-4!"<<  endl;
	}

	//test1-5 test method kbhit(&direction) test boundry case: input other than a,s,w,d
	test = new game();
	direction = 'd';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'd'){
		cout << "Failed test1-5!"<<  endl;
	}

	//test1-6 test method kbhit(&direction) test boundry case: a number
	test = new game();
	direction = 'd';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'd'){
		cout << "Failed test1-6!"<<  endl;
	}

	//test1-7 test method kbhit(&direction) test boundry case: more than 1 charctor:apple
	test = new game();
	direction = 'w';
	key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 1 || direction != 'a'){
		cout << "Failed test1-7!"<<  endl;
	}

	//test2-1 test method generateFruit()
	for(int i=0; i< 10000; i++){
		test = new game();
		int dice = test->generateFruit();
		if(dice < 1 || dice >4){
			cout << "Failed test2-1!" << endl;
		}
		delete test;
	}

	//test2-2 test method generateFruit()
	int plus_count =0;
	int speed_count =0;
	int double_count =0;
	for(int i=0; i< 10000; i++){
		test = new game();
		test->generateFruit();
		switch (test->new_fruit->drawFruit()) {
			case '+':
				plus_count++;
				break;
			case 's':
				speed_count++;
				break;
			case '*':
				double_count++;
				break;
		}
		delete test;
	}
	//check if any type of fruit is less than 1/4 of the sum, that may indicate problem with random
	if(plus_count <2500 || speed_count < 2500 || double_count < 2500){
		cout << "Test2-2 may have failed! Fruits not evenly distributed." << endl;
	}

/*
	//test3 method run()
	//this method is tested by a script
	1. test left/right/up/down arrow key, and check if the snake moves accordingly.
	2. test a/s/d/w key, and check if the snake moves accordingly.
	3. test eat fruit +, and check if the snake grows longer and score increase by 1
	4. test eat fruit *, and check if the snake grows longer and score increase by 2
	5. test eat fruit s, and check if the snake grows longer and score increase by 1, and the snake moves at double normal speed
	6. check if the score gets shown properly and correctly
	7. crash snake into all 4 edges, and see if game finishes as expected.
	8. crash snake into itself, and see if game finishes as expected.

	player* tplayer = new player;
	test = new game(tplayer);
	test -> run();
	delete test;
*/

	return 0;
}
