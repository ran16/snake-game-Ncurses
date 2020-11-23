#include "records.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	//load records
	records game_records = records();
	game_records.loadRecords();
	player* player_tester;

	//---------------------------------------------------------------------------------test to write name in the data name.txt
	string name;
	cin >> name;
	player_tester = game_records.addPlayer(name);
	game_records.writeNames();

	//---------------------------------------------------------------------------------test to write and obtain score in the scores.txt
	int score;
	int highestScore;
	
	cin>>score;
	player_tester->setHighestScore(score);
	game_records.writeScores();
	
	ifstream tester;
	tester.open("./records/scores.txt");
	tester >> highestScore;
	tester.close();
	cout<<"Player's highest score is: "<<highestScore<<endl;


	//---------------------------------------------------------------------------------test for number of records using number of player registered
	int NumOfPlayers=0;
	int NumOfRecords=0;
	string names;

	//test1
	tester.open("./records/names.txt");

	while(!tester.eof()) {
		getline(tester, names);
		NumOfPlayers++;
	}
	tester.close();


	tester.open("./records/number_of_records.txt");
	tester >> NumOfRecords;
	tester.close();
	
	
	//cout<<NumOfPlayers<<" "<<NumOfRecords<<endl;
	
	if (NumOfPlayers-1 == NumOfRecords)
	{
		cout<<"Y"<<endl;
	}
	else
	{
		cout<<"N"<<endl;
	}

	//-----------------------------------------------------------------------------------test for existing player
	cin >> name;
	if(game_records.playerExist(name) == true)
	{
	std::cout <<"Player existed"<<endl;
	}

	//-----------------------------------------------------------------------------------

	return 0;

}