#include <iostream>
using namespace std;


#define endl "\n"

int main() {
	int num; 
	int result;
	int i = 0;
	while (cin >> num && num != 0) {
		i++;
		result = num / 2;
		cout << "Case " << i << ": " << result << "\n";
	}
	return 0;
}