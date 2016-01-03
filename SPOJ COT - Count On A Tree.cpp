// SPOJ COT - Count on a Tree
// LCA + Segment Tree + RMQ + Binary Search

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
const int N = 100001;

int n, m, u, v, k;
map<int, int> mapper;
int remapper[N], map_size;

// sparse table for LCA-RMQ
namespace sparse {
	int log2[N*2], table[N*2][21];
	int *arr;
	void build(int a[]) {
		arr = a;
		int nn = n * 2;
		table[1][0] = 1;
		for (int i = 2; i < nn; ++i) {
			log2[i] = log2[i >> 1] + 1;
			table[i][0] = i;
		}
		for (int j = 0; (2 << j) <= nn; ++j) {
			for (int i = 0; i + (2 << j) <= nn; ++i) {
				int k = i + (1 << j);
				if (arr[table[k][j]] <= arr[table[i][j]])
					table[i][j + 1] = table[k][j];
				else
					table[i][j + 1] = table[i][j];
			}
		}
	}
	int query(int a, int b) {
		if (a > b) swap(a, b);
		int k = log2[b - a + 1];
		int ab = b - (1 << k) + 1;
		if (arr[table[a][k]] < arr[table[ab][k]])
			return table[a][k];
		else
			return table[ab][k];
	}
}

// persistent segment tree for kth minimum query
namespace tree {
	struct node {
		int count;
		node *left, *right;
		node(node *l = NULL, node *r = NULL): count(0), left(l), right(r) {}
	};
	int count(node *p) { return p ? p->count : 0; }
	void pull(node *p) { if (p) p->count = count(p->left) + count(p->right); }
	node *empty = new node();
	node* update(node *p, int cost, int L = 0, int R = map_size - 1) {
		if (!p) p = empty;
		if (L == R) {
			int c = p->count + 1;
			p = new node(p->left, p->right);
			p->count = c;
			return p;
		}
		int M = (L + R) / 2;
		if (cost <= M) p = new node(update(p->left, cost, L, M), p->right);
		else           p = new node(p->left, update(p->right, cost, M + 1, R));
		pull(p); return p;
	}
	int binarySearch(node *left, node *right, node *mid, node *up, int k, int L = 0, int R = map_size - 1) {
		if (L == R) return L;
		if (!left) left = empty;
		if (!right) right = empty;
		if (!mid) mid = empty;
		if (!up) up = empty;
		int total = count(left->left) + count(right->left) - count(mid->left) - count(up->left);
		int M = (L + R) / 2;
		if (k <= total)
			return binarySearch(left->left, right->left, mid->left, up->left, k, L, M);
		else
			return binarySearch(left->right, right->right, mid->right, up->right, k - total, M + 1, R);
	}
}

namespace graph {
	int u[N], v[N], par[N], root;
	int cost[N], *adj[N], degree[N], edge[N];
	int dfs[N], pos[N], dep[N], id[N*2], rmq[N*2];
	tree::node *node[N];
	// lowest common ancestor
	int lca(int a, int b) {
		return id[sparse::query(pos[a], pos[b])];
	}
	void build() {
		memset(edge, 0, sizeof edge);
		int top = 0, ptr = 0;
		dfs[top++] = root;
		par[root] = -1;
		// build lca
		while (top > 0) {
			int u = dfs[--top];
			if (edge[u] == 0) {
				pos[u] = ptr;
				rmq[ptr] = dep[u];
				id[ptr++] = u;
				node[u] = (par[u] == -1 ? tree::empty : node[par[u]]);
				node[u] = tree::update(node[u], cost[u]);
			}
			if (edge[u] < degree[u]) {
				dfs[top++] = u;
				int v = adj[u][edge[u]++];
				if (v != par[u]) {
					par[v] = u;
					dep[v] = dep[u] + 1;
					dfs[top++] = v;
				}
			}
			else if (par[u] != -1) {
				int p = par[u];
				rmq[ptr] = dep[p];
				id[ptr++] = p;
			}
		}
		// cout << "Done with dfs" << endl;
		sparse::build(rmq);
	}
	int kth_minimum(int u, int v, int k) {
		int L = lca(u, v);
		tree::node *parent = (par[L] == -1 ? tree::empty : node[par[L]]);
		int total = tree::binarySearch(node[u], node[v], node[L], parent, k);
		return remapper[total];
	}
}

namespace graph {
	void input() {
		for (int i = 0; i < n; ++i) {
			cin >> cost[i];
			mapper[cost[i]];
		}
		// compress costs
		map_size = 0;
		for (map<int, int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
			it->second = map_size;
			remapper[map_size++] = it->first;
		}
		for (int i = 0; i < n; ++i) {
			cost[i] = mapper[cost[i]];
		}
		for (int i = 1; i < n; ++i) {
			cin >> u[i] >> v[i];
			--u[i], --v[i];
			++degree[u[i]];
			++degree[v[i]];
		}
		for (int i = 0; i < n; ++i) {
			adj[i] = new int[degree[i]];
		}
		for (int i = 1; i < n; ++i) {
			adj[u[i]][edge[u[i]]++] = v[i];
			adj[v[i]][edge[v[i]]++] = u[i];
		}
	}
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	graph::root = rand() % n;
	graph::input();
	graph::build();
	while (m--) {
		cin >> u >> v >> k; --u, --v;
		cout << graph::kth_minimum(u, v, k) << '\n';
	}
	cout << flush;
}

