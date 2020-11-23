#include "fruit.h"
#include "fruit_speed.h"
#include "snake.h"
#include "player.h"
#include <iostream>
#include <time.h> //for srand()

using namespace std;


int main(){

	srand(time(NULL));

	snake* tsnake = new snake();
	fruit_speed* test = NULL;
	player* tplayer = NULL;

	//test1 test random generated fruit position in the right range(x:[2,75], y:[5,21]). Test 10,000 times
	for(int i=0; i< 10000; i++){
		test = new fruit_speed(tsnake);
		//check if fruit is in range
		if(test->getPos().x < 2 || test->getPos().x >75 || test->getPos().y < 5 || test->getPos().y >21){
			cout << "Failed test1!" << endl;
			//print the coodinates that failed the test
			cout << test->getPos().x << " " << test->getPos().y << endl;
			return 0;
		}
		//check if fruit is not on top of snake
		for(int j=0; j<tsnake->getSnakeLength();j++){
			if(test->getPos().x == tsnake->body[j].x && test->getPos().y == tsnake->body[j].y){
				cout << "Failed!" << endl;
				//print the coodinates that failed the test
				cout << test->getPos().x << " " << test->getPos().y << endl;
				return 0;
			}
		}

		delete test;
	}
	delete tsnake;

	//test2 test method takeEffect(); test 10000 times
	tsnake = new snake();
	tplayer = new player();
	int i = 10000;
	while(i>-1){
		test = new fruit_speed(tsnake);
		int old_length = tsnake->getSnakeLength();
		int old_score = tplayer->getScore();
		test->takeEffect(tplayer,tsnake);
		int new_length = tsnake->getSnakeLength();
		int new_score = tplayer->getScore();
		int new_speed = tsnake->getSpeed();
		if(new_length - old_length != 1){
			cout << "Failed test2!" << endl;
			return 0;
		}
		if(new_score - old_score != 1){
			cout << "Failed test2!" << endl;
			return 0;
		}
		if(new_speed != 10){
			cout << "Failed test2!" <<endl;
			return 0;
		}
		delete test;
		i--;
	}
	delete tsnake;
	delete tplayer;

	//test3 test method drawFruit();
	tsnake = new snake();
	test = new fruit_speed(tsnake);
	if(test->drawFruit() != 's'){
		cout << "Failed test3!"<<endl;
	}


	return 0;

}
