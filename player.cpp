#include "player.h"
#include <iostream>

player::player(){
	name = "unknown";
	score = 0;
	highest_score = 0;

}
player::player(std::string nname){
	name = nname;
	score = 0;
	highest_score = 0;

}

//get name
std::string player::getName(){
	return name;
}

//setname
void player::setName(std::string nname) {
	name = nname;
	//std::cout << "loading player: "<< name << std::endl;
}

//setscore
void player::setScore(int nscore){
	switch (nscore) {
		case 1:
			score++; //score increa by 1
			break;
		case 2:
			score += 2; //score increase by 2
			break;
	}
}

int player::getScore(){
	return score;
}

//get high score
int player::getHighestScore(){
	return highest_score;
}

//set highest score
void player::setHighestScore(int nhighestscore){
	highest_score = nhighestscore;
	//std::cout << "new highest score: " << highest_score << std::endl;
}


player::~player(){
	
}
