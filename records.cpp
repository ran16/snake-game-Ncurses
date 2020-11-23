#include "records.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> // for function getRanking()
#include <algorithm> // for std::sort()

records::records(){
	number_of_records = 0;
	players = NULL;
}

void records::setNumberOfRecords(){
	std::ifstream number_of_records_txt("./records/number_of_records.txt");
  	if (number_of_records_txt.is_open()){
    	number_of_records_txt >> number_of_records;
    	number_of_records_txt.close();
		//std::cout << "number of records = " << number_of_records << std::endl;
  	}else{
		std::cout << "Unable to open file";
	}
}

void records::readPlayersInfo(){
	players = new player[number_of_records + 1]; // add one for a possible new player

	//read in names
	std::ifstream names_txt("./records/names.txt");
	std::string new_name;
	int i=0;
	if (names_txt.is_open()){
		while(getline(names_txt,new_name)){
			players[i].setName(new_name);
			i++;
		}
		names_txt.close();
	}else{
		std::cout << "Unable to open file";
	}

	//read in scores
	std::ifstream scores_txt("./records/scores.txt");
	int new_highest_score;
	i=0; // reset index
	if (scores_txt.is_open()){
		while(scores_txt >> new_highest_score){
			players[i].setHighestScore(new_highest_score);
			i++;
		}
		scores_txt.close();
	}else{
		std::cout << "Unable to open file";
	}

}

void records::loadRecords(){
	setNumberOfRecords();
	readPlayersInfo();
}

player* records::addPlayer(std::string nname){
	players[number_of_records].setName(nname);
	number_of_records++;
	return &(players[number_of_records-1]);
}

bool records::playerExist(std::string nname){
	for(int i=0; i<number_of_records;i++){
		if(players[i].getName() == nname){
			return true;
		}
	}

	return false;
}

player* records::searchPlayer(std::string nname){
	for(int i=0; i<number_of_records;i++){
		if(players[i].getName() == nname){
			return &(players[i]);
		}
	}
	return &(players[number_of_records]); // return the last player(name:unknow, highest_score:0) if there is no match. This should not be returned, as long as the main program check and make sure that the player does exist first.
}

void records::writeScores(){
	std::ofstream scores_txt("./records/scores.txt");
 	if (scores_txt.is_open()){
   		for(int i=0; i<number_of_records; i++){
			scores_txt << players[i].getHighestScore() << "\n";
		}
   		scores_txt.close();
 	}
 	else std::cout << "Unable to open file" <<std::endl;
}

void records::writeNames(){
	std::ofstream names_txt("./records/names.txt");
 	if (names_txt.is_open()){
   		for(int i=0; i<number_of_records; i++){
			names_txt << players[i].getName() << "\n";
		}
   		names_txt.close();
 	}
 	else std::cout << "Unable to open file" <<std::endl;

	//also update the number of records
	std::ofstream number_of_records_txt("./records/number_of_records.txt");
 	if (number_of_records_txt.is_open()){
		number_of_records_txt << number_of_records << "\n";
   		number_of_records_txt.close();
 	}else{
 		std::cout << "Unable to open file" <<std::endl;
	}
}

//get ranking
int records::getRanking(int score){
	//store everyone's highest score in a vector
	std::vector<int> all_scores;
	for(int i=0; i<number_of_records; i++){
		all_scores.push_back(players[i].getHighestScore());
	}

	//add the new score
	all_scores.push_back(score);

	//sort vector in descending order
	std::sort(all_scores.begin(),all_scores.end());
	std::reverse(all_scores.begin(),all_scores.end());

	//find ranking
	for(int i=0; i < all_scores.size();i++){
		//std::cout << ".."<<all_scores[i] <<std::endl;
		if(score == all_scores[i]){
			return i+1;
		}
	}

	return 0; //return 0 when there is error
}

records::~records(){
	delete [] players;
}
