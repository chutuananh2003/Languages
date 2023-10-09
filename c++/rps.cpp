#include <array>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void welcom();
char getPlayerChoice();
char getComputerChoice();
void chooseWinner(char player, char computer);

int main() {
	
	char player, computer;

	welcom();

	player = getPlayerChoice();
	computer = getComputerChoice();

	chooseWinner(player, computer);

	return 0;
}

void welcom() {
	cout << "Rock - Paper - Scissors Game!" << endl;
	cout << "*****************************" << endl;
	cout << "R - Rock" << endl;
	cout << "P - Paper" << endl;
	cout << "S - Scissors" << endl;
}


char getPlayerChoice() {
	char player;

	cout << "Enter your choice (R - P - S): ";
	cin >> player;

	switch (player) {
		case 'R':
		case 'r':
			player = 'R';
			cout << "Your choice is Rock!" << endl; break;
		case 'P':
		case 'p':
			player = 'P';
			cout << "Your choice is Paper!" << endl; break;
		case 'S':
		case 's':
			player = 'S';
			cout << "Your choice is Scissors!" << endl; break;
		default:
			cout << "Your choice INVALID!" << endl;
	}

	return player;
}

char getComputerChoice() {

	char computer;
	
	srand(time(NULL));

	int num = rand() % 3 + 1;

	switch (num) {
		case 1:
			computer = 'R';
			cout << "Computer's choice is Rock!" << endl; break;
		case 2:
			computer = 'P';
			cout << "Computer's choice is Paper!" << endl; break;
		case 3:
			computer = 'S';
			cout << "Computer's choice is Scissors!" << endl; break;
		default:
			cout << "Program has some error!" << endl;
	}

	return computer;
}

void chooseWinner(char player, char computer) {
	switch (player) {
		case 'R':
			cout << (computer == 'R' ? "Get along" : (computer == 'P' ? "You LOSS!" : "You WIN!")) << endl; break;
		case 'P':
			cout << (computer == 'P' ? "Get along" : (computer == 'S' ? "You LOSS!" : "You WIN!")) << endl; break;		
		case 'S':
			cout << (computer == 'S' ? "Get along" : (computer == 'R' ? "You LOSS!" : "You WIN!")) << endl; break;
		default:
			cout << "Program has some error!" << endl;
	}
}


