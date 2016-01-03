// SPOJ QTREE6 - Query on a tree 6
// http://www.spoj.com/problems/QTREE6/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 100005;
const int SN = 320;

int n, sn;
int basefreq[2][SN][N << 2];
int *freq[2][SN];
int offset[2][SN], tree[2][N], group[N];
int L[N], R[N], dfs[N], edge[N];
vector<int> par[N], adj[N];

inline void add(int p, int i, int v) {
	--freq[p][group[i]][tree[p][i]];
	++freq[p][group[i]][tree[p][i] += v];
}

inline int get(int p, int i) {
	return tree[p][i] + offset[p][group[i]];
}

inline int getFrequency(int p, int g, int v) {
	return freq[p][g][v - offset[p][g]];
}

inline void push(int p, int g) {
	for (int i = g * sn; i < n && group[i] == g; ++i)
		add(p, i, offset[p][g]);
	offset[p][g] = 0;
}

inline int query(int p, int a, int b, int v) {
	int ans = 0;
	if (group[a] == group[b]) {
		push(p, group[a]);
		for (int i = a; i <= b; ++i)
			if (get(p, i) == v)
				ans++;
		return ans;
	}
	push(p, group[a]);
	push(p, group[b]);
	for (int i = a; i < n && group[i] == group[a]; ++i)
		if (get(p, i) == v)
			ans++;
	for (int i = b; i >= 0 && group[i] == group[b]; --i)
		if (get(p, i) == v)
			ans++;
	for (int g = group[a] + 1; g < group[b]; ++g)
		ans += getFrequency(p, g, v);
	return ans;
}

inline void update(int p, int a, int b, int v) {
	if (group[a] == group[b]) {
		push(p, group[a]);
		for (int i = a; i <= b; ++i)
			add(p, i, v);
		return;
	}
	push(p, group[a]);
	push(p, group[b]);
	for (int i = a; i < n && group[i] == group[a]; ++i)
		add(p, i, v);
	for (int i = b; i >= 0 && group[i] == group[b]; --i)
		add(p, i, v);
	for (int g = group[a] + 1; g < group[b]; ++g)
		offset[p][g] += v;
}

inline int lca(int p, int u) {
	int value = get(p, L[u]);
	for (int i = 0;; ++i) {
		// cout << "LCA(" << u << ") " << value << endl;
		if (i >= par[u].size() || get(p, L[par[u][i]]) < value) {
			if (i == 0) break;
			u = par[u][i - 1];
			i = -1;
		}
	}
	return u;
}

void build(int root) {
	// build LCA and euler tour
	int top = 0, ID = 0;
	dfs[top++] = root;
	while (top) {
		int u = dfs[--top];
		if (!edge[u]) {
			L[u] = ID++;
			par[u].clear();
			for (int i = 1; i <= top; i <<= 1) {
				par[u].push_back(dfs[top - i]);
			}
		}
		if (edge[u] < adj[u].size()) {
			dfs[top++] = u;
			int v = adj[u][edge[u]++];
			if (u == root || v != par[u][0]) {
				// h[v] = h[u] + 1;
				dfs[top++] = v;
			}
		}
		else {
			R[u] = ID - 1;
		}
	}
	// build sqrt decomposition trees
	sn = ceil(sqrt(n));
	for (int i = 0; i < n; ++i) {
		group[i] = i / sn;
		for (int j = 0; j < 2; ++j) {
			if (i % sn == 0)
				freq[j][group[i]] = basefreq[j][group[i]] + (N << 1);
			freq[j][group[i]][0]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		update(1, L[i], R[i], 2);
		update(1, L[i], L[i], -1);
	}
}

int m, a, b, color[N];

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(rand() % n);
	// build(0);
	cin >> m;
	while (m--) {
		cin >> a >> b;
		--b;
		if (a) {
			color[b] ^= 1;
			update(!color[b], L[b], R[b], 2);
			update(!color[b], L[b], L[b], -1);
			update(color[b], L[b], L[b], 1);
			update(color[b], L[b], R[b], -2);
		}
		else {
			int c = color[b];
			int an = lca(c, b);
			// cout << "Query: " << (c==1?"WHITE":"BLACK") << " " << b << " " << an << endl;
			cout << query(c, L[an], R[an], get(c, L[b])) << '\n';
		}
	}
	cout << flush;
}