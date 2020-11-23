#include "snake.h"
#include <iostream>

using namespace std;

int main(){

	snake* test = NULL;
	int steps =0;
	int AddSize =0;
	int AddSpeed =0;
	//----------------------------------------------- SNAKE MOVEMENT TEST

	//test1 test move left
	test = new snake(); //default coordinate:(12,40)
	cin >> steps;
	for(int i=0; i<steps; i++){
		test->moveLeft();
	}
	cout<< "y = " << test ->getHeadPos().y << ", "<< "x = "<< test->getHeadPos().x<<endl;
	delete test;

	//test2 test move right
	test = new snake(); //default coordinate:(12,40)
	cin >> steps;
	for(int i=0; i<steps; i++){
		test->moveRight();
	}
	cout<< "y = " << test ->getHeadPos().y << ", "<< "x = "<< test->getHeadPos().x<<endl;
	delete test;

	//test3 test move up
	test = new snake(); //default coordinate:(12,40)
	cin >> steps;
	for(int i=0; i<steps; i++){
		test->moveUp();
	}
	cout<< "y = " << test ->getHeadPos().y << ", "<< "x = "<< test->getHeadPos().x<<endl;
	delete test;

	//test4 test move down
	test = new snake(); //default coordinate:(12,40)
	cin >> steps;
	for(int i=0; i<steps; i++){
		test->moveDown();
	}
	cout<< "y = " << test ->getHeadPos().y << ", "<< "x = "<< test->getHeadPos().x<<endl;
	delete test;

	//----------------------------------------------- GROW TEST



	//test 5 test grow by 6
	test = new snake(); //default length is 4
	cin >> AddSize;
	for (int i =0; i<AddSize; i++){
		test->grow();
	}
	cout<<"Snake new length = "<< test ->getSnakeLength()<<endl;
	delete test;

	//test 6 test grow by 10
	test = new snake(); //default length is 4
	cin >> AddSize;
	for (int i =0; i<AddSize; i++){
		test->grow();
	}
	cout<<"Snake new length = "<< test ->getSnakeLength()<<endl;
	delete test;

	//------------------------------------------------ SNAKE SPEED TEST


	//test 7 speed test
	test = new snake(); //default speed is 5
	cin >> AddSpeed;
	test->setSpeed(5 + AddSpeed);
	cout<< "Snake new speed = "<<test-> getSpeed()<<endl;
	delete test;


	//------------------------------------------------ SNAKE COLLIDE TEST

	//test 8 collide wall test
	test = new snake();
	cin>>test->body[0].y;
	cin>>test->body[0].x;
	cout<<"Snake collide : "<<boolalpha<< test->collide()<<endl;
	delete test;


	return 0;
}