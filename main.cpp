#include "records.h"
#include "player.h"
#include "game.h"
#include <ctime> // srand()

#include <iostream>
#include <fstream>
#include <string>


int main(){
	std::cout << std::endl;
	//load records
	records game_records = records();
	game_records.loadRecords();

	//intro
	std::cout << "This is a snake game. \nThe rule is simple: EAT FRUITS AND DON'T CRASH. \nAre you a new player? [yes/no]: ";

	//check if is new player
	std::string yes_or_no;
	std::cin >> yes_or_no ;
	while(yes_or_no != "yes" && yes_or_no != "no"){
		std::cerr<< '\a' << "Error! Please enter yes if your are a new player, enter no if your are not. [yes/no]: " ;// '\a' for a beep sound
		std::cin >> yes_or_no;
	}

	//create a player object
	player* current_player;
	//get player name
	std::string name;
	std::cout << std::endl;
	std::cout << "Please enter your name: ";
	std::cin >> name;

	//if it's a new player, add new player to records
	if(yes_or_no == "yes"){

		//check if the name has already been taken.If yes, reprompt
		while(game_records.playerExist(name) == true){
			std::cout << std::endl;
			std::cout << "This name has already been taken. Please enter try another name: ";
			std::cin >> name;
		}

		//add new player to records
		current_player = game_records.addPlayer(name);
		std::cout << std::endl;
		std::cout << "adding new player to records.... done." << std::endl;

	}else{
		//if not a new player, find player's record
		//check if player exist in records. If not, prompt to re-enter
		while(game_records.playerExist(name) == false){
			std::cout << std::endl;
			std::cout << "Searching..." << std::endl;
			std::cout << "Can't find any records under your name. Please enter your name again: ";
			std::cin >> name;
		}
		current_player = game_records.searchPlayer(name);
		std::cout << std::endl;
		std::cout << "Searching.... Found it. Your highest score is " << current_player->getHighestScore() << std::endl;
	}

	/*------------------Enter Ncurses mode and start the game --------*/

	//create a pointer to game object
	game* new_game = new game(current_player);

	//seed rand()
	srand(time(NULL));

	//run the game
	new_game->run();


	//clean up
	delete new_game;
	//delete current_player; -- deleted in records destructor



	/*-------------------After game--------------------------------*/
	//update new highest_score
	if(current_player ->getHighestScore() < current_player ->getScore()){
		current_player->setHighestScore(current_player->getScore());
	}

	//update records
	//if it's not new player, only update score
	if(yes_or_no == "no"){
		game_records.writeScores();
	}else{
		game_records.writeNames();
		game_records.writeScores();
	}

	//display current score,highest score and ranking
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Thank you for playing! \nYour score is: " << current_player -> getScore() << "\n" << "Your highest record is: " << current_player -> getHighestScore() <<"\n" << "Your best ranking is: " << game_records.getRanking(current_player -> getHighestScore()) <<std::endl;

	return 0;

}
