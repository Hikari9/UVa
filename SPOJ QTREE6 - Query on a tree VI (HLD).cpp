// Heavy-Light Decomposition + RSQ
// http://www.spoj.com/status/ns=14410963

#include <bits/stdc++.h>

using namespace std;
const int N = 100001;


int chain[N], chains, n, q, a, b;
int id[N], pos[N], par[N], blackarr[N], whitearr[N], ptr;
int weight[N], head[N], heavy[N], c[N];
vector<int> adj[N];
set<int, greater<int> > tree[2][N];
set<int, greater<int> >::iterator it;

struct SegmentTree {
	#define M ((L + R) >> 1)
	#define P (p << 1)
	int st[N << 2], lazy[N << 2];
	void push(int p, int L, int R) {
		if (lazy[p] != 0) {
			st[p] += lazy[p];
			if (L != R) {
				lazy[P] += lazy[p];
				lazy[P + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
	}
	void pull(int p) {
		st[p] = st[P] + st[P + 1];
	}
	void build(int arr[], int p = 1, int L = 0, int R = n - 1) {
		lazy[p] = 0;
		if (L == R) {
			st[p] = arr[L];
			return;
		}
		build(arr, P, L, M);
		build(arr, P + 1, M + 1, R);
		pull(p);
	}
	// update black count
	void update(int a, int b, int v, int p = 1, int L = 0, int R = n - 1) {
		if (b < a) swap(a, b);
		push(p, L, R);
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy[p] += v;
			push(p, L, R);
			return;
		}
		update(a, b, v, P, L, M);
		update(a, b, v, P + 1, M + 1, R);
		pull(p);
	}
	int query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
		if (b < a) swap(a, b);
		push(p, L, R);
		if (b < L || R < a)
			return 0;
		if (a <= L && R <= b)
			return st[p];
		int q = query(a, b, P, L, M) + query(a, b, P + 1, M + 1, R);
		pull(p); return q;
	}
	void updateUp(int u, int an, int v) {
		while (chain[u] != chain[an]) {
			update(pos[head[chain[u]]], pos[u], v);
			u = par[head[chain[u]]];
		}
		update(pos[an], pos[u], v);
	}
} black, white;

void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (par[u] == v) continue;
		par[v] = u;
		dfsHeavy(v);
		weight[u] += weight[v];
		if (heavy[u] == -1 || weight[heavy[u]] < weight[v])
			heavy[u] = v;
	}
}

void dfsLight(int u) {
	if (head[chains] == -1) {
		tree[0][chains].clear();
		tree[1][chains].clear();
		head[chains] = u;
	}
	chain[u] = chains;
	pos  [u] = ptr;
	id [ptr] = u;
	blackarr[ptr] = weight[u];
	whitearr[ptr] = 0;
	tree[0][chains].insert(ptr);
	ptr++;
	if (heavy[u] != -1)
		dfsLight(heavy[u]);
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == par[u] || v == heavy[u])
			continue;
		chains++;
		dfsLight(v);
	}
}

void heavyLight(int root) {
	for (int i = 0; i < n; ++i)
		head[i] = par[i] = -1;
	chains = ptr = 0;
	dfsHeavy(root); dfsLight(root);
	black.build(blackarr);
	white.build(whitearr);
	chains++;
}

int ancestor(int u) {
	while (u != -1) {
		it = tree[!c[u]][chain[u]].lower_bound(pos[u]);
		if (it != tree[!c[u]][chain[u]].end())
			return id[*it + 1];
		int h = head[chain[u]];
		if (par[h] == -1 || c[h] != c[par[h]])
			return h;
		u = par[head[chain[u]]];
	}
	return id[0];
}

void toggle(int u) {
	SegmentTree& prev = (c[u] ? white : black);
	SegmentTree& next = (c[u] ? black : white);

	tree[c[u]][chain[u]].erase(pos[u]);
	int an = ancestor(u), q = prev.query(pos[u], pos[u]);
	if (par[an] != -1) an = par[an];
	prev.update(pos[u], pos[u], -1);
	if (par[u] != -1)
		prev.updateUp(par[u], an, -q);
	c[u] ^= 1;
	tree[c[u]][chain[u]].insert(pos[u]);
	an = ancestor(u), q = next.query(pos[u], pos[u]);
	if (par[an] != -1) an = par[an];
	next.update(pos[u], pos[u], 1);
	if (par[u] != -1)
		next.updateUp(par[u], an, q + 1);
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
	while (q-- > 0) {
		cin >> a >> b;
		--b;
		if (a)
			toggle(b);
		else {
			int an = ancestor(b);
			int qq = (c[b] ? white : black).query(pos[an], pos[an]);
			cout << qq << "\n";
		}
	}
	cout << flush;
}