// TIc-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

void drawBord(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);



int main()
{
	char spaces[9] = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	char player = 'O';
	char computer = 'X';
	bool running = true;

	drawBord(spaces);

	while (running) {
		playerMove(spaces, player);
		drawBord(spaces);
		if (checkWinner(spaces,player,computer) ){
			running = false;
			break;

		}
		else if (checkTie(spaces)) {
			running = false;
			break;
		}

		computerMove(spaces, computer);
		drawBord(spaces);
		if (checkWinner(spaces, player, computer)) {
			running = false;
			break;

		}
		else if (checkTie(spaces)) {
			running = false;
			break;
		}
	}
	cout << "Thanks for playing! \n";

	
	return 0;

}

void drawBord(char *spaces) {
	cout << "\n";
	for (int i = 0; i < 9; i += 3) {
		cout << "     |     |     " << '\n';
		cout << "  " << spaces[i] << "  |  " << spaces[i + 1] << "  |  " << spaces[i + 2] << "  \n";
		if (i < 6) {
			cout << "_____|_____|_____" << '\n';
		}
		else {
			cout << "     |     |     " << '\n';
		}
	}
	cout << "\n";
}

void playerMove(char *spaces, char player) {
	int number;
	do {
		cout << "Enter a spot to place amarker (1-9): ";
		cin >> number;
		number--;
		if (spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}
		
	} while (number < 0 || number > 8 || spaces[number] != player || spaces[number] == player);
}

void computerMove(char *spaces, char computer) {
	int number;
	srand(time(0));
	
	while (true) {
		number = rand() % 9;
		if (spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}
}

bool checkWinner(char *spaces, char player, char computer) {
	
	if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
		spaces[0] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
		spaces[3] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
		spaces[6] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
		spaces[0] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
		spaces[1] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
		spaces[2] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if (spaces[4] != ' ' && spaces[4] == spaces[0] && spaces[4] == spaces[8]) {
		spaces[4] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else if (spaces[4] != ' ' && spaces[4] == spaces[2] && spaces[4] == spaces[6]) {
		spaces[4] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE! \n";

	}
	else {
		return false;
	}

	return true;
}

bool checkTie(char *spaces) {
	
	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	cout << "IT'S A TIE\n";
	return true;

}
