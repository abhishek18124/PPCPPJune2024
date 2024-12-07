#include<iostream>

using namespace std;

#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, int> rankMap;   // to store a mapping b/w vertices & their ranks i.e. sizes

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
		T l_x = findSet(x);
		T l_y = findSet(y);
		if (l_x != l_y) {
			if (rankMap[l_x] > rankMap[l_y]) { // union by rank (size)
				parentMap[l_y] = l_x;
				rankMap[l_x] += rankMap[l_y];
			} else {
				parentMap[l_x] = l_y;
				rankMap[l_y] += rankMap[l_x];
			}
		}
	}

};

class edge {
public:
	int u;
	int v;
	int w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

// return true if you want a to be ordered before b otherwise false

bool edgeCmp(edge a, edge b) {

	if (a.w < b.w) {
		// we want a to come before b since we are sorting edgeList based on weights in the inc. order
		return true;
	}

	return false;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edgeList;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edgeList.push_back(edge(u, v, w));
	}

	// vector<vector<int>> edgeList;
	// for (int i = 0; i < m; i++) {
	// 	int u, v, w;
	// 	cin >> u >> v >> w;
	// 	edgeList.push_back({w, u, v});
	// }

	// time : O(ElogE)
	// space: O(V) due to disjointSet

	sort(edgeList.begin(), edgeList.end(), edgeCmp); // ElogE

	disjointSet<int> ds;
	for (int i = 0; i < n; i++) { // V
		ds.createSet(i);
	}

	int total = 0;
	vector<edge> mst;

	for (edge e : edgeList) { // E.const

		// check if e is a safe edge or not

		if (ds.findSet(e.u) != ds.findSet(e.v)) {

			// edge e is a safe edge, so it will be part of MST
			mst.push_back(e);
			total += e.w;
			ds.unionSet(e.u, e.v);

			if (mst.size() == n - 1) {
				break;
			}

		}

	}

	for (int i = 0; i < mst.size(); i++) {
		edge e = mst[i];
		cout << e.u << " " << e.v << endl;
	}

	cout << total << endl;


	return 0;
}