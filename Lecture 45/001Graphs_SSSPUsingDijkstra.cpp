/*

Computing SSSP using the Dijkstra's algorithm in a weighted graph.

i/p : n : no. of nodes (nodes range from 0 to n-1)
      m : no. of edges
      next m lines contain edge info.
      u v w

e.g.

	i/p :

	5 7
	0 1 10
	0 2 5
	1 2 3
	1 3 1
	2 3 9
	2 4 2
	3 4 8

	o/p :

	0 - 0
	1 - 8
	2 - 5
	3 - 9
	4 - 7

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << i << " : ";

	// 	// for (auto [ngb, wt] : adj[i]) {
	// 	// 	cout << "(" << ngb << ", " << wt << ") ";
	// 	// }

	// 	for (pair<int, int> p : adj[i]) {
	// 		int ngb = p.first;
	// 		int wt = p.second;
	// 		cout << "(" << ngb << ", " << wt << ") ";
	// 	}

	// 	cout << endl;
	// }

	vector<int> distMap(n, INF);
	distMap[0] = 0; // we are assuming 0 is the source vertex

	vector<bool> explored(n, false); // explored[i] stores if node i is explored or not

	set<pair<int, int>> minHeap;
	for (int i = 0; i < n; i++) {
		minHeap.insert({distMap[i], i});
	}

	// while (!minHeap.empty()) {

	// 	pair<int, int> node = *minHeap.begin();
	// 	minHeap.erase(minHeap.begin());

	// 	int du = node.first;
	// 	int u = node.second;
	// 	cout << u << " " << du << endl;

	// }

	// time : O(VlogV + ElogV) : O((V+E)logV)
	// space: O(V) due to minHeap and exploredSet

	while (!minHeap.empty()) {

		pair<int, int> node = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		int du = node.first; // 0
		int u = node.second; // 0

		for (auto [v, wuv] : adj[u]) {
			// check if the edge b/w u and v is tensed or not
			if (!explored[v] and distMap[v] > du + wuv) {
				// edge b/w u and v is tensed, relax it
				auto it = minHeap.find({distMap[v], v});
				minHeap.erase(it);
				distMap[v] = du + wuv;
				minHeap.insert({distMap[v], v});
			}
		}

		explored[u] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << i << " : " << distMap[i] << endl;
	}

	return 0;
}