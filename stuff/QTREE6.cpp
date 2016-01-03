#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 100005;

int n, q, a, b, r, chain[N], head[N], pos[N], chains, ptr;
int weight[N], par[N], id[N], heavy[N], arr[4][N], color[N];
int tree[4][N << 2], lazy[4][N << 2];
vector<int> adj[N];

void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	for (int v : adj[u]) {
		if (v != par[u]) {
			par[v] = u;
			dfsHeavy(v);
			weight[u] += weight[v];
			if (heavy[u] == -1 || weight[heavy[u]] < weight[v])
				heavy[u] = v;
		}
	}
}

void dfsLight(int u) {
	if (head[chains] == -1) {
		head[chains] = u;
	}
	chain[u] = chains;
	pos[u] = ptr;
	id[ptr] = u;
	arr[0][ptr] = weight[u]; // black
	arr[1][ptr] = 0;         // white
	arr[2][ptr] = 1;		 // count black
	arr[3][ptr] = 0;		 // count white
	ptr++;
	if (heavy[u] != -1)
		dfsLight(heavy[u]);
	for (int v : adj[u]) {
		if (v != par[u] && v != heavy[u]) {
			chains++;
			dfsLight(v);
		}
	}
}

#define P (p << 1)
#define M ((L + R) >> 1)

void push(int c, int p, int L, int R) {
	if (lazy[c][p]) {
		tree[c][p] += lazy[c][p];
		if (L != R) {
			lazy[c][P]   += lazy[c][p];
			lazy[c][P+1] += lazy[c][p];
		}
		lazy[c][p] = 0;
	}
}

void pull(int c, int p) {
	tree[c][p] = tree[c][P] + tree[c][P+1];
}

void build(int c, int p = 1, int L = 0, int R = n - 1) {
	lazy[c][p] = 0;
	if (L == R) {
		tree[c][p] = arr[c][L];
		return;
	}
	build(c, P, L, M);
	build(c, P+1, M+1, R);
	pull(c, p);
}

void update(int c, int a, int b, int v, int p = 1, int L = 0, int R = n - 1) {
	if (a > b) swap(a, b);
	push(c, p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[c][p] += v;
		push(c, p, L, R);
		return;
	}
	update(c, a, b, v, P, L, M);
	update(c, a, b, v, P+1, M+1, R);
	pull(c, p);
}

void updateUp(int c, int u, int A, int v) {
	while (chain[u] != chain[A]) {
		update(c, pos[head[chain[u]]], pos[u], v);
		u = par[head[chain[u]]];
	}
	update(c, pos[A], pos[u], v);
}

int query(int c, int a, int b, int p = 1, int L = 0, int R = n - 1) {
	if (a > b) swap(a, b);
	push(c, p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return tree[c][p];
	int q = query(c, a, b, P, L, M) + query(c, a, b, P+1, M+1, R);
	pull(c, p); return q;
}

void heavyLight(int root) {
	r = root;
	for (int i = 0; i < n; ++i)
		head[i] = par[i] = -1;
	chains = ptr = 0;
	dfsHeavy(root); dfsLight(root);
	build(0); build(1); build(2); build(3);
}

int ancestor(int u) {
	int c = color[u];
	/*
	cout << "Ancestors: ";
	for (int v = u; v != -1; v = par[v]) {
		cout << v << "(" << color[v] << ") ";
	}
	cout << endl;
	*/
	while (u != -1) {
		int h = head[chain[u]];
		int L = pos[h];
		int R = pos[u];
		if (L > R) swap(L, R);
		if (query(!c + 2, L, R) == 0) {
			if (par[h] == -1 || color[par[h]] != c)
				return h;
			u = par[h];
		}
		else {
			int rr = pos[u];
			while (L < R) {
				if (query(!c + 2, M, pos[u]) != 0)
					L = M + 1;
				else
					R = M;
			}
			L = id[L];
			// cout << "Answer: " << L << "(" << color[L] << ") => " << par[L] << "(" << color[par[L]] << ")" << endl;
			assert(color[par[L]] != color[L]);
			return L;
		}
	}
	return r;
}

void toggle(int u) {
	// cout << "Toggling: " << u << endl;
	int A = ancestor(u);
	int& c = color[u];
	updateUp(c, u, A, -query(c, pos[u], pos[u]));
	update(c + 2, pos[u], pos[u], -1);
	c ^= 1;
	A = ancestor(u);
	updateUp(c, u, A, 1 + query(c, pos[u], pos[u]));
	update(c + 2, pos[u], pos[u], 1);
	/*
	cout << "   ";
	for (int j = 0; j < n; ++j) {
		if (id[j] == head[chain[id[j]]]) cout << "   ";
		cout << id[j] << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; ++i) {
		cout << i << ": ";
		for (int j = 0; j < n; ++j) {
			if (id[j] == head[chain[id[j]]]) cout << " | ";
			cout << query(i, j, j) << " ";
		}
		cout << endl;
	}
	*/
}

int queryUp(int u) {
	int A = ancestor(u);
	return query(color[u], pos[A], pos[A]);
}

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
	heavyLight(rand() % n);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (a) toggle(--b);
		else cout << queryUp(--b) << '\n';
	}
	cout << flush;
}