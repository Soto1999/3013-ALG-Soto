#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


#define endl "\n"

int shortestpath(int cells, int exit, int time, vector <pair<int, int>> Graph[]){
	priority_queue <pair<int, int>> PQ;

	int Dist[101];

	for (int i = 1; i <= cells; i++) {
		Dist[i] = INT_MAX;
	}
	
	PQ.push(pair<int, int>(exit, 0));
	Dist[exit] = 0;
	int P, C, W, temp;
	
	while (!PQ.empty()) {
		P = PQ.top().first;
		W = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < Graph[P].size(); i++) {
			C = Graph[P][i].first;
			temp = Graph[P][i].second;
			if (Dist[P] + temp < Dist[C]) {
				Dist[C] = Dist[P] + temp;
				PQ.push(pair<int, int>(C, Dist[C]));
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= cells; i++) {
		if (Dist[i] <= time) {
			count++;
		}
	}
	return count;
}

// Driver program to test methods of graph class 
int main(){
	int num;
	int cells;
	int exit;
	int connection;
	int time;
	int p;
	int c;
	int w;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cells >> exit >> time >> connection;

		vector<pair<int, int>> G[101];
		for (int i = 0; i < connection; i++) {
			cin >> p >> c >> w;
			G[c].push_back(pair<int, int>(p, w));
		}
		cout << shortestpath(cells, exit, time, G);
		if (i == num - 1) {
			cout << "\n";
		}
		else {
			cout << "\n\n";
		}

		for (int i = 0; i <= cells; i++) {
			G[i].clear();
		}
	}
	return 0;
}