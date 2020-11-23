#include "position.h"

#include <iostream>
using namespace std;

int main(){
	
	int testsRun = 0;
    int testsPassed = 0;
    
	//test constructor
	//test positive
	testsRun++;
	position pos1 = position(1,2);
	if(pos1.y != 1 || pos1.x != 2){
		cout << "Positive Position Test Failed!" <<endl;
	}else{
	} testsPassed++;

	//test negative
	testsRun++;
	position pos2 = position(-109,-3);
	if(pos2.y != -109 || pos2.x != -3){
		cout << "Negative Position Test Failed!" <<endl;
	}else{
	} testsPassed++;

    //test mix
    testsRun++;
	position pos3 = position(56,-10);
	if(pos3.y != 56 || pos3.x != -10){
		cout << "Mix Position +x -y Test failed!" <<endl;
	}else{
	} testsPassed++;

    //test mix
    testsRun++;
	position pos4 = position(-1,10);
	if(pos4.y != -1 || pos4.x != 10){
		cout << "Mix Position -x +y Test Failed!" <<endl;
	}else{
	} testsPassed++;
	
	if (testsPassed < testsRun) {
        std::cout << "Tests in PositionTester.cpp failed! (" << testsPassed << "/" << testsRun << ")" << std::endl;
    }

}
