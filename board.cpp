/* 
 * Copyright (c) 2017 The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		
 * @title 			
 * @date			(YYYY-MM-DD)
 * @fversion		1.2.0
 * @description 	
 * =============================================================================
 */
#include "info.h"
#include <iostream>
#include <vector>
using std::vector;

#include ".\h\main.h"

#define LOG(a) if(_DEBUG_) {std::cout << a << std::endl;} // will be removed if false and optimizations is turned on
#define _DEBUG_ true

vector<vector<char> > board;

void setUpBoard() {
	board.push_back(vector<char>(3, ' '));
	board.push_back(vector<char>(3, ' '));
	board.push_back(vector<char>(3, ' '));
}

void displayBoard() {
	/*
	for(int i = 0; i < 9; ++i) {
		std::cout << '-';
	}
	std::cout << std::endl;
	for(auto &i: board) {
		std::cout << '|';
		for(auto &j: i) {
			std::cout << j << '|';
		}
		std::cout << std::endl;		
		for(auto &j: i) {
			std::cout << '-' << '-';
		}
		std::cout << std::endl;
	}
	//*/
	for(auto &i: board) {
		for(auto &j: i) {
			std::cout << j << '|';
		}
		std::cout << std::endl;
	}
}

void updateBoard(int choice) {
	LOG(choice);
	if(userTurn) {
		board[choice / 3][choice % 3] = userChar;
	} else {
		board[choice / 3][choice % 3] = compChar;
	}
}

bool checkIfEmpty() {
	
}