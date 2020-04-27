///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Label:            10901
// Title:            Ferry Loading III
// Course:           3013
// Semester:         2020 Spring
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;

int main() {
	vector<queue < pair<int, int> > > cars(2);
	

	string side = "";

	int capacity, lines, traveltime, cases, arrivaltime;

	bool onleft = true;

	cin >> cases;
	while (cases--) {
		cin >> capacity >> traveltime >> lines;
		vector<int> totaltime(lines);
		for (int i = 0; i < lines; i++) {
			cin >> arrivaltime;
			cin >> side;
			if (side == "left") {
				cars[LEFT].push(pair<int, int>(i, arrivaltime));
			}
			else {
				cars[RIGHT].push(pair<int, int>(i, arrivaltime));
			}
		}
		int time = 0;
		int index = LEFT;
		while (!cars[LEFT].empty() || !cars[RIGHT].empty()) {
			int earliestcar = INT_MAX;
			if (!cars[LEFT].empty()) {
				earliestcar = cars[LEFT].front().second;
			}
			if (!cars[RIGHT].empty()) {
				earliestcar = min(earliestcar, cars[RIGHT].front().second);
			}
			time = max(time, earliestcar);
			int carcount = 0;
			while (!cars[index].empty() && carcount < capacity && cars[index].front().second <= time) {
				totaltime[cars[index].front().first] = time + traveltime;
				cars[index].pop();
				carcount++;
			}
			time += traveltime;
			index ^= 1;
		}
		for (int i = 0; i < lines; i++) {
			cout << totaltime[i] << endl;
		}
	if (cases > 0) {
	cout << endl;
		}
	}
	return 0;
}