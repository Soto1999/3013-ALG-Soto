#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector<int> vi;     // vector of integers
typedef pair<int, int> ii;  // pair of integers
typedef vector<ii> vii;     // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;            // container to keep track of who get visited
vector<vii> AdjList;        // AdjList stores our edge lists

/**
 * Depth First Search
 *
 * Params:
 *  int u - starting node id
 *
 */
void dfs(int u) {
	// In DFS we use a stack structure to keep track of who to visit next.
	// Recursive acts just like a stack so we dont need to declare any 
	// structure to keep track for us, we let the recursive calls do it for us

	been_visited[u] = VISITED;  // mark u as visited

	// Loop overadjacency list looking for connections
	for (int j = 0; j < (int)AdjList[u].size(); j++) {

		// v is a pair representing a neighbor and the 
		// weight of the edge from u->v
		ii v = AdjList[u][j];

		// check to see if our neighbor was visited
		if (been_visited[v.first] == UNVISITED) {
			dfs(v.first);
		}
	}
}

int main(int argc, char** argv) {
	int n;
	string max;
	int size;
	int cases;

	string pair;
	int first;
	int second; 

	cin >> n;

	for (int i = 0; i < n; i++) {
		cases = 0;
		cin >> max; 
		size = (int)max.at(0) - 'A' + 1;
		pair = "";

		if (i != 0) {
			cout << endl;
		}

		AdjList.resize(size + 1);
		been_visited.resize(size + 1, UNVISITED);

		getline(cin, pair);
		getline(cin, pair);

		while (pair != "") {
			first = (int)pair.at(0) - 'A' + 1;
			second = (int)pair.at(1) - 'A' + 1;

			AdjList[first].push_back(make_pair(second, 10));
			AdjList[second].push_back(make_pair(first, 10));

			getline(cin, pair);
		}

		for (int i = 1; i < (int)been_visited.size(); i++) {
			if (been_visited[i] == UNVISITED) {
				dfs(i);
				cases++;
			}
		}

		cout << cases << endl;

		been_visited.clear();
		fill(been_visited.begin(), been_visited.end(), UNVISITED);
		for (int i = 0; i < (int)AdjList.size(); i++) {
			AdjList.clear();
		}
	}
	return 0;
}