#ifndef PLAYER_H
#define PLAYER_H

#include <string>


class player{
	std::string name;
	int score;
	int highest_score;

public:
	//constructor
	player();
	player(std::string nname);

	//getname
	std::string getName();

	//setname
	void setName(std::string nname);

	//setscore
	void setScore(int nscore);

	//get score
	int getScore();

	//get high score
	int getHighestScore();

	//set highest score
	void setHighestScore(int nhighestscore);

	~player();
};

#endif
