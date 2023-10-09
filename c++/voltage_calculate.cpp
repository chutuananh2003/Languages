#include <iostream>

using namespace std;

int n;

void inputNumberOfCurrent();
double* inputCurrent();
double* inputResistance();
double* outputVoltage(double* current, double* resistance);
void showResult(double* current, double*resistance, double* voltage);


int main() {
	
	double* current;
	double* resistance;
	double* voltage;

	inputNumberOfCurrent();

	current = inputCurrent();
	resistance = inputResistance();
	voltage = outputVoltage(current, resistance);
	
	showResult(current, resistance, voltage);

	return 0;
}


/* functions */
void inputNumberOfCurrent() {
	cout << "Enter the number of Current: ";
	cin >> n;
}

double* inputCurrent() {
	cout << endl;
	double* array = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter current i[" << i + 1 << "]: "; cin >> array[i];
	}
	return array;
}

double* inputResistance() {
	cout << endl;
	double* array = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter Resistance R[" << i + 1 << "]: "; cin >> array[i];
	}
	return array;
}

double* outputVoltage(double* current, double* resistance) {
	double* array = new double[n];
	for (int i = 0; i < n; i++) {
		array[i] = current[i] * resistance[i];
	}
	return array;
}

void showResult(double* current, double*resistance, double* voltage) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "i[" << i + 1 << "] = " << current[i] << ", r[" << i + 1 << "] = " << resistance[i];
		cout << "   -->  u[" << i + 1 << "] = " << voltage[i] << endl;
	}
	cout << endl;
}
