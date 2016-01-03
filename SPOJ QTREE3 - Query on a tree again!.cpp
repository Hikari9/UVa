// SPOJ QTREE3 - Query on a tree again!
// http://www.spoj.com/problems/QTREE3/

#include <bits/stdc++.h>
using namespace std;
const int N = 100001;

int n, q, a, b;
int heavy[N], par[N], weight[N], pos[N], chain[N], head[N], chains, ID;
int color[N], arr[N];

vector<int> adj[N];
set<int> tree[N];

void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v != par[u]) {
			par[v] = u;
			dfsHeavy(v);
			if (heavy[u] == -1 || weight[heavy[u]] < weight[v])
				heavy[u] = v;
			weight[u] += weight[v];
		}
	}
}

void dfsLight(int u) {
	if (head[chains] == -1) {
		tree[chains].clear();
		head[chains] = u;
	}
	pos[u]   = ID;
	chain[u] = chains;
	arr[ID++] = u;
	if (heavy[u] != -1)
		dfsLight(heavy[u]);
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v != par[u] && v != heavy[u]) {
			chains++;
			dfsLight(v);
		}
	}
}

void heavyLight(int root) {
	for (int i = 0; i < n; ++i) 
		par[i] = head[i] = -1;
	chains = ID = 0;
	dfsHeavy(root);
	dfsLight(root);
	chains++;
}

int queryUp(int u) {
	int ans = -1;
	while (u != -1) {
		if (!tree[chain[u]].empty() && *tree[chain[u]].begin() <= pos[u])
			ans = arr[*tree[chain[u]].begin()] + 1;
		u = par[head[chain[u]]];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	heavyLight(0);
	while (q--) {
		cin >> a >> b;
		--b;
		if (a)
			cout << queryUp(b) << '\n';
		else {
			if (color[b] ^= 1)
				tree[chain[b]].insert(pos[b]);
			else
				tree[chain[b]].erase(pos[b]);
		}
	}
	cout << flush;
}