#include "player.h"
#include "snake.h"
#include "game.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {
    int testsRun = 0;
    int testsPassed = 0;

    // getName test

    { // letters
        testsRun++;
        player player1("Bob");
        if (player1.getName() != "Bob") {
            std::cout << "Test name failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }

    { // symbols
        testsRun++;
        player player2("&*");
        if (player2.getName() != "&*") {
            std::cout << "Test symbols name failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }

    { // numbers
        testsRun++;
        player player3("123");
        if (player3.getName() != "123") {
            std::cout << "Test number name failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    // getScore test

    { // constructor test
        testsRun++;
        player player1("Bob");
        if (player1.getScore() != 0) {
            std::cout << "Constructor Test Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    { // Positive number test
        testsRun++;
        player player1("Bob");
        player1.setScore(1);
        if (player1.getScore() != 1) {
            std::cout << "Test Positive Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    
    //getHighestScore test
    
    { //constructor test
        testsRun++;
        player player1("Bob");
        if (player1.getHighestScore() != 0) {
            std::cout << "Constructor Test Highest Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    { //positive test
        testsRun++;
        player player1("Bob");
        player1.setHighestScore(2);
        if (player1.getHighestScore() != 2) {
            std::cout << "Positive Test Highest Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    { // Negative number test
        testsRun++;
        player player1("Bob");
        player1.setHighestScore(-2);
        if (player1.getHighestScore() != -2) {
            std::cout << "Test Negative Highest Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    { // Big number test
        testsRun++;
        player player1("Bob");
        player1.setHighestScore(100);
        if (player1.getHighestScore() != 100) {
            std::cout << "Test Big Highest Score failed!" << std::endl;
        } else {
            testsPassed++;
        }
    }
    
    if (testsPassed < testsRun) {
        std::cout << "Tests in PlayerTester.cpp failed! (" << testsPassed << "/" << testsRun << ")" << std::endl;
    }
}