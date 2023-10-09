#include <iostream>
#include <vector>

using namespace std;

void printNumber(int n) {
    if (n >= 1 && n <= 9) {
        // Print English representation of numbers 1 to 9
        string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        cout << numbers[n - 1] << endl;
    } else if (n > 9 && n % 2 == 0) {
        // Print "even" for even numbers
        cout << "even" << endl;
    } else if (n > 9 && n % 2 == 1) {
        // Print "odd" for odd numbers
        cout << "odd" << endl;
    }
}

int main() {

	int a, b;
	cin >> a >> b;

	for (int n = a; n <= b; n++) {
		printNumber(n);
	}

	return 0;
}
