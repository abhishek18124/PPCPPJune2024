#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, int> rankMap; // to store a mapping b/w vertices & their ranks

public :

	void createSet(T x) {
		parentMap[x] = x;
		rankMap[x] = 1;
	}

	T findSet(T x) {
		if (parentMap[x] == x) {
			return x;
		}

		return parentMap[x] = findSet(parentMap[x]); // path compression
	}

	void unionSet(T x, T y) {
		T lx = findSet(x);
		T ly = findSet(y);

		if (lx != ly) {

			int rx = rankMap[lx];
			int ry = rankMap[ly];

			if (rx > ry) { // union-by-rank

				parentMap[ly] = lx;
				rankMap[lx] += rankMap[ly];

			} else {

				parentMap[lx] = ly;
				rankMap[ly] += rankMap[lx];

			}

		}
	}

};

int main() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	disjointSet<int> ds;

	for (int i = 0; i < n; i++) { // for each vertex, we create a set
		ds.createSet(i);
	}

	bool flag = false; // assume no cycle is present

	for (int i = 0; i < edges.size(); i++) { // time : O(E)

		int u = edges[i].first;
		int v = edges[i].second;

		if (ds.findSet(u) != ds.findSet(v)) {

			// u and v are part of different set, do a union

			ds.unionSet(u, v);

		} else {

			// u and v are part of the same set / component

			// that means there already exists a path b/w u and v

			// and now we've found an edge b/w them

			// so we can say there is a cycle in the graph

			flag = true;
			break;

		}

	}

	flag ? cout << "cycle found" << endl : cout << "cycle not found" << endl;


	return 0;
}
