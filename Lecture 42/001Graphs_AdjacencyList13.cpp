// recording : https://drive.google.com/file/d/1EhXjAe4HO7TM0jSM7bf_3bXr3DlicFnO/view?usp=sharing

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m; // n is no. of nodes in the graph, m is no. of edges in the graph

	vector<set<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u); // comment this line of code if given graph is directed
	}

	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		set<int> ngblist = adj[i];
		for (int ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;
}