// Heavy-Light Decomposition with LCA and RMQ
// SPOJ QTREE - Query on a tree
// http://www.spoj.com/problems/QTREE/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 100005;

int chain[N], pos[N], par[N], dep[N], weight[N];
int heavy[N], hw[N], arr[N], head[N], chains, ptr;
int eu[N], ev[N], ew[N], tree[N << 1], n;
vector<int> adj[N];

// assign heavy edges
// O(n)
void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int e = adj[u][i];
		int v = (u == eu[e] ? ev[e] : eu[e]);
		int w = ew[e];
		if (v != par[u]) {
			dep[v] = dep[u] + 1;
			par[v] = u;
			dfsHeavy(v);
			weight[u] += weight[v];
			if (heavy[u] == -1 || weight[v] > weight[heavy[u]])
				heavy[u] = v;
		}
	}
}

// assign chain positions
// O(n)
void dfsLight(int u, int cost) {
	if (head[chains] == -1)
		head[chains] = u;
	chain[u]     = chains;
	pos  [u]     = ptr;
	arr  [ptr++] = cost; // or edge cost
	if (heavy[u] != -1)
	for (int i = 0; i < adj[u].size(); ++i) {
		int e = adj[u][i];
		int v = (u == eu[e] ? ev[e] : eu[e]);
		int w = ew[e];
		if (v == heavy[u]) {
			dfsLight(v, w);
			break;
		}
	}
	for (int i = 0; i < adj[u].size(); ++i) {
		int e = adj[u][i];
		int v = (u == eu[e] ? ev[e] : eu[e]);
		int w = ew[e];
		if (v != par[u] && v != heavy[u]) {
			chains++;
			dfsLight(v, w);
		}
	}
}

// decompose heavy and light edges
// O(n)
void heavyLight(int root) {
	for (int i = 0; i < n; ++i)
		par[i] = head[i] = -1;
	dep[root] = ptr = chains = 0;
	dfsHeavy(root);
	dfsLight(root, 0);
	++chains;
}

// build dynamic RMQ segment tree
// O(n)
void build() {
	heavyLight(rand() % n);
	// RMQ tree 1 to n
	for (int i = 0; i < n; ++i)
		tree[i + n] = arr[i];
	for (int i = n * 2 - 1; i > 0; i -= 2)
		tree[i >> 1] = max(tree[i], tree[i^1]);
}

// get RMQ from a chain
// O(log n)
int query(int a, int b) {
	if (b < a) swap(a, b);
	int ans = 0;
	for (a += n, b += n + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1)
			ans = max(ans, tree[a++]);
		if (b & 1)
			ans = max(ans, tree[--b]);
	}
	return ans;
}

// RMQ point update
// O(log n)
void update(int i, int x) {
	arr[i] = x;
	for (tree[i += n] = x; i > 0; i >>= 1)
		tree[i >> 1] = max(tree[i], tree[i^1]);
}

// skip the lower chain head and proceed to parent
// O(log n)
int lca(int a, int b) {
	while (chain[a] != chain[b]) {
		if (dep[head[chain[a]]] >= dep[head[chain[b]]])
			a = par[head[chain[a]]];
		else
			b = par[head[chain[b]]];
	}
	return dep[a] < dep[b] ? a : b;
}

int pathQuery(int a, int b) {
	int ans = 0;
	while (chain[a] != chain[b]) {
		int ha = head[chain[a]];
		int hb = head[chain[b]];
		if (dep[ha] >= dep[hb]) {
			ans = max(ans, query(pos[ha], pos[a]));
			a = par[ha];
		}
		else {
			ans = max(ans, query(pos[hb], pos[b]));
			b = par[hb];
		}
	}
	if (a == b) return ans;
	return max(ans, query(min(pos[a], pos[b]) + 1, max(pos[a], pos[b])));
}

int t, a, b, c;
char Q[10];

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i) {
			cin >> a >> b >> c;
			--a, --b;
			adj[a].push_back(i);
			adj[b].push_back(i);
			eu[i] = a;
			ev[i] = b;
			ew[i] = c;
		}
		build();
		while (cin >> Q, Q[0] != 'D') {
			cin >> a >> b;
			if (Q[0] == 'Q')
				cout << pathQuery(--a, --b) << '\n';
			else {
				int id = pos[par[eu[a]] == ev[a] ? eu[a] : ev[a]];
				update(id, b);
			}
		}
		if (t) cout << '\n';
	}
	cout << flush;
}