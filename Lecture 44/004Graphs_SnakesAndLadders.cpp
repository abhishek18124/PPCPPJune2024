/*

Snake and Ladders Game

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// insert a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

	void print() {
		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			list<T> neighbourList = vertex.second;
			cout << vertexLabel << " : ";
			for (T neighbour : neighbourList) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int bfs(T s, T d) {

		map<T, T> parentMap;
		parentMap[s] = s;

		map<T, int> distMap; // to store the mapping between vertices &
		// their shortest dist from the src vertex
		distMap[s] = 0;

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			list<T> ngblist = neighbourMap[front];
			for (T ngb : ngblist) {
				if (visited.find(ngb) == visited.end()) {
					// ngb is not yet visited so visit it
					visited.insert(ngb);
					q.push(ngb);

					// and because we are visiting the ngb because of front,
					// we can say 'front' is the parent of 'ngb' in the BFS tree
					distMap[ngb] = distMap[front] + 1;
					parentMap[ngb] = front;
				}
			}

		}

		// for (pair<T, int> p : distMap) {
		// 	T vertexLabel = p.first;
		// 	int dist = p.second;
		// 	cout << vertexLabel << " : " << dist << endl;
		// }

		// cout << endl;

		cout << "length of the shortest path from " << s << " to " << d << " = " << distMap[d] << endl << endl;

		// for (pair<T, T> p : parentMap) {
		// 	T vertexLabel = p.first;
		// 	T parentLabel = p.second;
		// 	cout << vertexLabel << " : " << parentLabel << endl;
		// }

		T temp = d;
		vector<T> path;
		while (parentMap[temp] != temp) {
			// cout << temp  << "<-";
			path.push_back(temp);
			temp = parentMap[temp];
		}

		// cout << temp << endl;
		path.push_back(temp);
		reverse(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}

		cout << endl;

		return distMap[d];

	}

};

int minDiceThrows(int n,
                  vector<pair<int, int>> snakes,
                  vector<pair<int, int>> ladders) {

	vector<int> wtMap(n + 1, 0);

	for (pair<int, int> ladderPos : ladders) {
		int startPos = ladderPos.first; // 2
		int endPos = ladderPos.second; // 15
		wtMap[startPos] = endPos - startPos; // wtMap[2] = 15 - 2 = 13
	}

	for (pair<int, int> snakePos : snakes) {
		int startPos = snakePos.first; // 17
		int endPos = snakePos.second; // 4
		wtMap[startPos] = endPos - startPos; // wtMap[17] = 4 - 17 = -13
	}

	graph<int> g;

	for (int u = 1; u < n; u++) {

		if (wtMap[u] != 0) continue; // if cell u has a snake or ladder, we will not roll the die on cell u

		for (int d = 1; d <= 6; d++) {

			int v = u + d;
			if (v <= n) { // to make sure you don't go outside the board
				int v_ = v + wtMap[v];
				g.addEdge(u, v_);
			}

		}

	}

	return g.bfs(1, n);

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}