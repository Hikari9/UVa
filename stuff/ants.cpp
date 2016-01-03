#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
const int N = 100001;

int n, a, b, q, ev[N], ew[N];
vector<int> adj[N];

int h[N], H[N], id[N << 1], L[N << 1], tree[N << 2], ID;
long long d[N];

void dfs(int u, int prev = -1) {
	H[u] = ID;
	id[ID] = u;
	L[ID++] = h[u];
	for (int i = 0; i < adj[u].size(); ++i) {
		int e = adj[u][i];
		int v = (u == e ? ev[e] : e);
		int w = ew[e];
		if (v == prev) continue;
		h[v] = h[u] + 1;
		d[v] = d[u] + w;
		dfs(v, u);
		id[ID] = u;
		L[ID++] = h[u];
	}
}

void build(int root) {
	ID = 0;
	h[root] = 0;
	d[root] = 0;
	dfs(root);
	for (int i = 0; i < ID; ++i) 
		tree[ID + i] = i;
	for (int i = ID * 2 - 1; i > 0; --i)
		tree[i >> 1] = (L[tree[i]] <= L[tree[i ^ 1]] ? tree[i] : tree[i ^ 1]);
}

int query(int a, int b) {
	if (a > b) swap(a, b);
	int ans = a;
	for (a += ID, b += ID + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1) {
			ans = (L[ans] <= L[tree[a]] ? ans : tree[a]);
			a++;
		}
		if (b & 1) {
			--b;
			ans = (L[ans] <= L[tree[b]] ? ans : tree[b]);
		}
	}
	return ans;
}

int lca(int a, int b) {
	return id[query(H[a], H[b])];
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n, n) {
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i) {
			cin >> a >> b;
			adj[i].push_back(i);
			adj[a].push_back(i);
			ev[i] = a;
			ew[i] = b;
		}
		build(rand() % n);
		cin >> q;
		while (q--) {
			cin >> a >> b;
			cout << d[a] + d[b] - 2 * d[lca(a, b)];
			if (q) cout << ' ';
			else cout << '\n';
		}
	}
	cout << flush;
}