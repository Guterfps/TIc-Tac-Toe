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
	char spaces[9] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	char playr = 'o';
	char computer = 'x';
	bool running = true;

	drawBord(spaces);

	
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

}

void computerMove(char *spaces, char computer) {

}

bool checkWinner(char *spaces, char player, char computer) {
	return 0;
}

bool checkTie(char *spaces) {
	return 0;
}
