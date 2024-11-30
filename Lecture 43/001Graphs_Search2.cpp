#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// time : O(V+2E) // O(n + 2m)
// space: V for visited[] + V due to fn-call stk (e.g. graph is like a chain) ~ O(V)

void dfsHelper(int cur,
               const vector<vector<int>> adj,
               vector<bool>& visited) {

	// mark 'cur' as visited
	visited[cur] = true; // worst-case O(1)
	cout << cur << " ";

	vector<int> ngblist = adj[cur];
	for (int ngb : ngblist) {
		if (!visited[ngb]) {
			dfsHelper(ngb, adj, visited);
		}
	}

}

// time : O(V + 2E)
// space: V for visited[] + V-1 for queue (e.g. graph is like a star) ~ O(V)

void bfsHelper(int s, int n, const vector<vector<int>>& adj) {

	vector<bool> visited(n, false);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {

		int front = q.front();
		q.pop();

		cout << front << " ";
		vector<int> ngblist = adj[front];
		for (int ngb : ngblist) {
			if (!visited[ngb]) {
				visited[ngb] = true;
				q.push(ngb);
			}
		}

	}

	cout << endl;

}

int main() {

	int n, m;
	cin >> n >> m;

	// n : # vertices
	// m : # edges

	// graph internally uses adjacency list as it represention

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u--; v--; // uncomment this if vertices are labelled 1 to n and not 0 to n-1
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if given graph is directed
	}

	vector<bool> visited(n, false);

	dfsHelper(0, adj, visited); cout << endl;

	// fill(visited.begin(), visited.end(), false); // to reset visited[]

	bfsHelper(0, n, adj);

	return 0;
}