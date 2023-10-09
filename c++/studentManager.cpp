#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// A struct to store the information of a student
struct Student {
    string id; // The student's ID
    string name; // The student's name
    double gpa; // The student's grade point average
};

// A function to display the menu and get the user choice
int getChoice() {
    int choice; // An integer to store the user choice

    cout << "*******************\n";
	cout << "C++ Student Manager\n";
	cout << "*******************\n\n";

	cout << "------Options------\n";
	cout << "1. Add a student\n" << "2. Edit a student\n" << "3. Delete a student\n" << "4. Print the student list to a file\n" << "5. Show the student list on screen\n" << "6. Exit\n"; // Add option 5 to the menu
	cout << "Input your choice: "; 
	cin >> choice;

	return choice;
}

// A function to add a student to the list
void addStudent(vector<Student>& list) {
    Student student; // A student to store the user input
    cout << "Enter the student's ID: ";
    cin >> student.id;
    cout << "Enter the student's name: ";
    cin.ignore(); // Ignore the newline character from the previous input
    getline(cin, student.name); // Use getline to read the whole name
    cout << "Enter the student's GPA: ";
    cin >> student.gpa;

    list.push_back(student); // Add the student to the end of the list
    cout << "Student added successfully.\n";
}

// A function to edit a student in the list
void editStudent(vector<Student>& list) {
    string id; // A string to store the ID of the student to be edited
    cout << "Enter the ID of the student you want to edit: ";
    cin >> id;

    bool found = false; // A boolean flag to indicate if the student is found or not
    for (int i = 0; i < list.size(); i++) { // Loop through the list of students
        if (list[i].id == id) { // If the ID matches, edit the student's information
            found = true; // Set the flag to true
            cout << "Enter the new name of the student: ";
            cin.ignore(); // Ignore the newline character from the previous input
            getline(cin, list[i].name); // Use getline to read the whole name
            cout << "Enter the new GPA of the student: ";
            cin >> list[i].gpa;
            cout << "Student edited successfully.\n";
            break; // Break out of the loop
        }
    }

    if (!found) { // If the flag is still false, print a message
        cout << "No student with that ID was found.\n";
    }
}

// A function to delete a student from the list
void deleteStudent(vector<Student>& list) {
    string id; // A string to store the ID of the student to be deleted
    cout << "Enter the ID of the student you want to delete: ";
    cin >> id;

    bool found = false; // A boolean flag to indicate if the student is found or not
    for (int i = 0; i < list.size(); i++) { // Loop through the list of students
        if (list[i].id == id) { // If the ID matches, delete the student from the list
            found = true; // Set the flag to true
            list.erase(list.begin() + i); // Erase the element at index i from the vector
            cout << "Student deleted successfully.\n";
            break; // Break out of the loop
        }
    }

    if (!found) { // If the flag is still false, print a message
        cout << "No student with that ID was found.\n";
    }
}

// A function to print the list of students to a file
void printStudentListToFile(const vector<Student>& list) {
    string filename = "studentList.txt"; // The name of the file to store the student list
    ofstream fout(filename); // Open the file for writing
    if (fout.fail()) { // If the file cannot be opened, print a message and return
        cout << "Cannot open the file.\n";
        return;
    }

    fout << "ID\tName\tGPA\n"; // Write the header to the file
    for (const Student& student : list) { // Loop through the list of students
        fout << student.id << "\t" << student.name << "\t" << student.gpa << "\n"; // Write the student's information to the file
    }
    fout.close(); // Close the file

    cout << "Student list printed to " << filename << ".\n";
}

// A function to show the list of students on screen // Add this function
void showStudentList(const vector<Student>& list) {
    cout << "ID\tName\tGPA\n"; // Print the header on screen
    for (const Student& student : list) { // Loop through the list of students
        cout << student.id << "\t" << student.name << "\t" << fixed << setprecision(2) << student.gpa << "\n"; // Print the student's information on screen with two decimal places for GPA
    }
    cout << "Student list shown on screen.\n";
}

int main() {

	vector<Student> list; // A vector to store the list of students
	int choice; // The user choice

	do {
		choice = getChoice(); // Get the user choice

		if (choice == 1) { // If the user chooses to add a student, call the addStudent function
			addStudent(list);
		}
		else if (choice == 2) { // If the user chooses to edit a student, call the editStudent function
			editStudent(list);
		}
		else if (choice == 3) { // If the user chooses to delete a student, call the deleteStudent function
			deleteStudent(list);
		}
		else if (choice == 4) { // If the user chooses to print the student list to a file, call the printStudentListToFile function
			printStudentListToFile(list);
		}
        else if (choice == 5) { // If the user chooses to show the student list on screen, call the showStudentList function
            showStudentList(list);
        }
		else if (choice == 6) { // If the user chooses to exit, print a message and break the loop
			cout << "Thank you for using C++ Student Manager. Goodbye!\n";
			break;
		}
		else { // If the user enters an invalid choice, print a message and continue the loop
			cout << "Invalid choice. Please try again.\n";
		}
        cin.ignore(); // Ignore the newline character from the previous input
        cout << "Press enter to continue..."; 
        cin.get(); // Wait for the user to press enter
        system("cls"); // Clear the screen
	} while (true);

	return 0;
}
