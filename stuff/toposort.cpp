// SPOJ TOPOSORT - Topological Sorting
// http://www.spoj.com/problems/TOPOSORT/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100001;

int color[N], topo[N], size, n;
bool hasCycle;
vector<int> adj[N];

void dfs(int u) {
	color[u] = 1;
	for (int v : adj[u]) {
		if (color[v] == 1) hasCycle = true;
		if (color[v] == 0) dfs(v);
	}
	color[u] = 2;
	topo[size++] = u;
}

bool toposort() { // true if no cycle
	memset(color, 0, sizeof color);
	size = 0; hasCycle = false;
	for (int i = n - 1; i >= 0; i--)
		if (color[i] == 0) dfs(i);
	reverse(topo, topo + size);
	return !hasCycle;
}

int m, u, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; ++i)
		sort(adj[u].begin(), adj[u].end(), greater<int>());
	if (!toposort())
		cout << "Sandro fails." << endl;
	else {
		for (int i = 0; i < size; ++i) {
			if (i) cout << " ";
			cout << topo[i] + 1;
		}
		cout << endl;
	}
}