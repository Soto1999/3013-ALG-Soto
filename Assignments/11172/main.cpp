#include <iostream>
#include <fstream>
using namespace std;


#define endl "\n"

int main() {
	int loop;
	int num1, num2;
	cin >> loop;
	for (int i = 0; i < loop; i++) {
		cin >> num1 >> num2;
		if (num1 < num2) {
			cout << "<\n";
		}
		if (num1 > num2) {
			cout << ">\n";
		}
		if (num1 == num2) {
			cout << "=\n";
		}
	}
	system("pause");
	return 0;
}