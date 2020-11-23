#ifndef RECORDS_H
#define RECORDS_H

#include "player.h"


class records{
public:
	int number_of_records;
	player* players;

	//constructor
	records();

	//set number of records from a txt file
	void setNumberOfRecords();

	//set up players with names and highest scores
	void readPlayersInfo();

	//load records
	void loadRecords();

	//add one player
	player* addPlayer(std::string nname);

	//check if a player exist in the records
	bool playerExist(std::string nname);


	//search for a player by name, if found, the function will return a pointer to the player object
	player* searchPlayer(std::string nname);

	//write scores on to a txt file
	void writeScores();

	//write names on to a txt file
	void writeNames();

	//get ranking
	int getRanking(int score);

	//destructor
	~records();

};



#endif
