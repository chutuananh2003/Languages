#include <errno.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);


int main() {
	
	double balance = 0;
	int choice = 0;

	do {
		cout << endl << endl;
		cout << "*****************" << endl;
		cout << "Enter your choice" << endl;
		cout << "*****************" << endl;
		cout << "1. Show balance" << endl;
		cout << "2. Deposit Money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cin >> choice;
		cin.clear(); 
		cout << endl;
		fflush(stdin);

		switch (choice) {
			case 1: 
				showBalance(balance); 
				break;
			case 2:	
				balance += deposit();
				showBalance(balance);
				break;
			case 3:
				balance -= withdraw(balance);
				showBalance(balance);
				break;
			case 4:	cout << "Thank you for visited!"; break;
			default: cout << "INVALID CHOICE" << endl;
		}

	}	while (choice != 4);

	return 0;

}

void showBalance(double balance) {
	cout << "Your balance Money: $" << setprecision(2) << fixed << balance << endl;
}

double deposit() {
	double amount;
	cout << "Enter amount to be deposited: ";
	cin >> amount;

	while (amount <= 0) {
		cout << "amount INVALID, please try again!" << endl;
		cout << "Enter amount to be deposited: ";
		cin >> amount;
	}

	cout << "Deposit SUCCESS! ";

	return amount;
}

double withdraw(double balance) {
	double amount = 0;
	cout << "Enter amount to be withdrawed: ";
	cin >> amount;

	while (amount <= 0 || amount > balance) {
		if (amount <= 0) cout << "amount INVALID, please try again!" << endl;
		else cout << "amount rather than you balance, please try again!" << endl;
		cout << "Enter amount to be withdrawed: ";
		cin >> amount;
	}

	cout << "Withdraw SUCCESS! ";

	return amount;
}
