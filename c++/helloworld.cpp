#include <iostream>
#include <string>

using namespace std;

struct ConNguoi {
	string name;
	int age;
	double weight, height;
	char gpa;
	bool con_zin;
};

int main() {
	
	// Biến : Kiểu dữ liệu
	// Cấu trúc - Struct
	
	ConNguoi anh;
	anh.name = "Tuan Anh";
	anh.age = 20;
	anh.weight = 54;
	anh.height = 1.72;
	anh.gpa = 'B';
	anh.con_zin = true;

	cout << anh.name;

	return 0;
}
