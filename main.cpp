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
 * @fversion		1.0.4
 * @description 	
 * =============================================================================
 */
#include "info.h"
#define _PRINTINFO std::cout << '\n' << R_PROJNAME << " v" << R_PVERSION << " by " << R_AUTHOR << '\n' << R_COPYRIGHT << '\n' << R_COMMENTS << "\n\n\n" // Legal and Informational

#include <iostream>
#include <cstdlib>
#include <time.h>

#include ".\h\main.h"
#include ".\h\gameFunc.h"
#include ".\h\board.h"
#include ".\h\computerAI.h"

char userChar;
char compChar;
bool userTurn;

int main(int argc, char* argv[]) {
	_PRINTINFO;
	
	using std::cout;
	using std::cin;
	using std::endl;
	
	srand(time(NULL));
	
	userTurn = rand() % 2 == 0;
	
	setUpBoard();
	
	bool valid = false;
	do {
		cout << "Welcome to Tic Tac Toe, would you like to be \"X\" or \"O\"?" << endl
			 << ":: ";
		cin.get(userChar); // TODO: EXCEPTION HANDLING
		cin.clear();
		cin.ignore(1000, '\n');
		if(userChar == 'X' || userChar == 'O')
			valid = true;
		if(userChar == 'X')
			compChar = 'O';
		else
			compChar = 'X';
	} while(!valid);
	
	do {
		if(userTurn) {
			char choiceChar;
			int choice;
			displayBoard();
			cout << endl << endl << endl;
			cout << "Please choose a place on the board to mark" << endl
				 << ":: ";
			valid = false;
			do {
				cin.get(choiceChar); // TODO: EXCEPTION HANDLING
				cin.clear();
				cin.ignore(1000, '\n');
				choice = choiceChar - '0';
				if(choice >= 0 && choice < 10)
					valid = true;
			} while(!valid);
			updateBoard(choice);
		} else {
			int choice = computerTurn();
			cout << "The computer has choosen. This is the board." << endl;
			updateBoard(choice);
			displayBoard();
		}
		changeTurn();
		clearScreen();
	} while(!playerWin());
	
	cout << getWinner() << " has Won!" << endl;
	cin.get();
	return 0;
}