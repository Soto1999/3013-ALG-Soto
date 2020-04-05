#include <iostream>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

typedef map<int, int> m;

int main() {
	m container;
	vector<int> count;

	int num;

	while (cin >> num) {
			if (container.find(num) == container.end()) {
				container.insert(pair<int, int>(num, 1));
				count.push_back(num);
			}
			else {
				container[num] += 1;
			}
	}

	for (int i = 0; i < count.size(); i++) {
		cout << count[i] << " " << container[count[i]] << "\n";
	}
	return 0;
}