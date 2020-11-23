#include "game.h"
#include "player.h"
#include <iostream>
#include <ctime> // srand()

using namespace std;




int main(){
	game* test = NULL;
	int direction = 'w';

	//test1-8 test method kbhit(&direction) test no input
	test = new game();
	int key_pressed = test -> kbhit(&direction);
	delete test;
	if(key_pressed != 0 || direction != 'w'){
		cout << "Failed test1-8!" << endl;
	}

	return 0;
}
