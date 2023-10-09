#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// A struct to store the username and password of an account
struct Account {
    string username;
    string password;
};

// A function to check if an account exists in a file
bool accountExists(const string& filename, const Account& account) {
    ifstream fin(filename); // Open the file for reading
    if (fin.fail()) return false; // If the file cannot be opened, return false
    Account temp; // A temporary account to store the data from the file
    while (fin >> temp.username >> temp.password) { // Read the username and password from the file
        if (temp.username == account.username && temp.password == account.password) { // If they match the given account, return true
            fin.close(); // Close the file
            return true;
        }
    }
    fin.close(); // Close the file
    return false; // If no match is found, return false
}

// A function to add an account to a file
void addAccount(const string& filename, const Account& account) {
    ofstream fout(filename, ios::app); // Open the file for appending
    if (fout.fail()) return; // If the file cannot be opened, return
    fout << account.username << " " << account.password << "\n"; // Write the username and password to the file
    fout.close(); // Close the file
}

// A function to create an account and save it to a file
void signUp(const string& filename) {
    Account account; // An account to store the user input
    string rePassword; // A string to store the repeated password
    cout << "Enter username: ";
    getline(cin, account.username);
    cout << "Enter password: ";
    getline(cin, account.password);
    cout << "Enter password again: ";
    getline(cin, rePassword);

    if (account.password == rePassword) { // If the passwords match, try to add the account to the file
        if (accountExists(filename, account)) { // If the account already exists, print a message
            cout << "This account already exists.\n";
        }
        else { // If not, add the account and print a message
            addAccount(filename, account);
            cout << "Create C++ Account success!\n";
        }
    }
    else { // If the passwords do not match, print a message
        cout << "Passwords do not match.\n";
    }
}

// A function to sign in with an existing account from a file
void signIn(const string& filename) {
    Account account; // An account to store the user input
    cout << "Enter username: ";
    getline(cin, account.username);
    cout << "Enter password: ";
    getline(cin, account.password);

    if (accountExists(filename, account)) { // If the account exists in the file, print a message
        cout << "Sign in success!\n";
    }
    else { // If not, print a message
        cout << "Invalid username or password.\n";
    }
}

// A function to display the menu and get the user choice
string getChoice() {
    string choice; // A string to store the user choice

    cout << "*******************\n";
		cout << "C++ Account Program\n";
		cout << "*******************\n\n";

		cout << "------Options------\n";
		cout << "1. Sign up\n" << "2. Sign in\n" << "3. Exit\n";
		cout << "Input your choice: "; 
		getline(cin, choice);

	return choice;
}

int main() {

	string filename = "accountList.txt"; // The name of the file to store the accounts
	string choice; // The user choice

	do {
		choice = getChoice(); // Get the user choice

		if (choice == "1") { // If the user chooses to sign up, call the signUp function
			signUp(filename);
		}
		else if (choice == "2") { // If the user chooses to sign in, call the signIn function
			signIn(filename);
		}
		else if (choice == "3") { // If the user chooses to exit, print a message and break the loop
			cout << "Thank you for using C++ Account Program. Goodbye!\n";
			break;
		}
		else { // If the user enters an invalid choice, print a message and continue the loop
			cout << "Invalid choice. Please try again.\n";
		}
	} while (true);

	return 0;
}
