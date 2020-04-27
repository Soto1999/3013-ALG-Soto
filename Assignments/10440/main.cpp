///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Label:            10440
// Title:            Ferry Loading II
// Course:           3013
// Semester:         2020 Spring
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int cases, n, t, m, position, answer;
	answer = 0;
	int T[1440];

	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> n >> t >> m;

		for (int j = 0; j < m; j++) {
			cin >> T[j];
		}
		sort(T, T + m);

		answer = position = 0;

		if (m % n == 0) {
			answer = T[n - 1] + 2 * t;
			position = n;
		}
		else {
			answer = T[m % n - 1] + 2 * t;
			position = m % n;
		}
		for (position; position < m; position += n) {
			if (answer >= T[position + n - 1]) {
				answer = answer + 2 * t;
			}
			else {
				answer = T[position + n - 1] + 2 * t;
			}

		}
		answer -= t;

		cout << answer << " " << (m + n - 1) / n << endl;
	}
	return 0;
}