// UVa 10938 - Flea circus
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1879

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>

using namespace std;
const int N = 50005;

int n, m, a, b, dfs[N], edge[N], h[N];
vector<int> adj[N], par[N];

void build(int root) {
	h[root] = 0;
	memset(edge, 0, sizeof edge);
	int top = 0;
	dfs[top++] = root;
	while (top) {
		int u = dfs[--top];
		if (edge[u] == 0) {
			par[u].clear();
			for (int i = 1; i <= top; i <<= 1)
				par[u].push_back(dfs[top - i]);
		}
		if (edge[u] < adj[u].size()) {
			dfs[top++] = u;
			int v = adj[u][edge[u]++];
			if (u == root || v != par[u][0]) {
				h[v] = h[u] + 1;
				dfs[top++] = v;
			}
		}
	}
}

int lca(int a, int b) {
	if (h[a] < h[b]) swap(a, b);
	for (int i = 0; h[a] != h[b]; ++i) {
		if (i >= par[a].size() || h[par[a][i]] < h[b]) {
			// parent is i - 1
			a = par[a][i - 1];
			i = -1;
		}
	}
	for (int i = 1; a != b && h[a] > 0; ++i) {
		if (i >= par[a].size() || par[a][i] == par[b][i]) {
			a = par[a][i - 1];
			b = par[b][i - 1];
			i = 0;
		}
	}
	return a == b ? a : -1;
}

int climb(int u, int k) {
	for (int i = 0; k > 0; k -= (1 << i)) {
		for (i = 0; (1 << i) <= k; ++i);
		u = par[u][--i];
		// cout << "Ki: " << k << " " << i << " " << (1 << i) << endl;
	}
	return u + 1;
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			par[i].clear();
			adj[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			cin >> a >> b;
			--a, --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		build(rand() % n);
		cin >> m;
		while (m-- > 0) {
			cin >> a >> b;
			--a, --b;
			int L = lca(a, b);
			assert(L >= 0);
			int D = h[a] + h[b] - 2 * h[L];
			int Da = h[a] - h[L];
			int Db = h[b] - h[L];
			int D2 = D / 2;
			if (D & 1) {
				int first, second;
				// cout << h[a] << " " << h[b] << " " << D2 << endl;
				if (Da > Db) {
					first = climb(a, D2);
					second = climb(first - 1, 1);
				}
				else {
					first = climb(b, D2);
					second = climb(first - 1, 1);
				}
				if (second < first)
					swap(first, second);
				assert(first != second);
				cout << "The fleas jump forever between " << first << " and " << second << ".\n";
			}
			else {
				int meet;
				if (Da >= Db) meet = climb(a, D2);
				else meet = climb(b, D2);
				cout << "The fleas meet at " << meet << ".\n";
			}

		}
	}
	cout << flush;
}