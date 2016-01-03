#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <algorithm>
#include <bitset>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100001;

struct node {
	int pre, suf, sum, res, lazy;
	bool flag;
	node(int x = 0) { assign(x); }
	void assign(int x) {
		sum = x;
		pre = suf = res = max(0, x);
	}
	node(const node& a, const node& b) {
		pull(a, b);
	}
	void pull(const node& a, const node& b) {
		pre = max(0, max(a.pre, a.sum + b.pre));
		suf = max(0, max(a.suf + b.sum, b.suf));
		res = max(0, max(max(a.res, b.res), a.suf + b.pre));
		sum = a.sum + b.sum;
	}
	friend ostream& operator << (ostream& out, const node& a) {
		return out << "pre=" << a.pre << " suf=" << a.suf << " sum=" << a.sum << " res=" << a.res;
	}
};

int n, m, heavy[N], weight[N], par[N], size[N], a, b, cmd;
int head[N], headp[N], chain[N], pos[N], dep[N], ch, ptr;
bool flag[N << 2];
int arr[N], cost[N], lazy[N << 2], x;
node tree[N << 2], *st;
int *adj[N];

// segment tree stuff

void pull(int p) {
	st[p].pull(st[P], st[P + 1]);
}
void push(int p, int L, int R) {
	if (flag[p]) {
		st[p].assign(lazy[p] * (R - L + 1));
		if (L != R) {
			lazy[P]     = lazy[p];
			lazy[P + 1] = lazy[p];
			flag[P] = flag[P + 1] = true;
		}
		lazy[p] = 0;
		flag[p] = false;
	}
}

void build(int p, int L, int R) {
	lazy[p] = 0;
	flag[p] = false;
	if (L == R) {
		st[p].assign(arr[L]);
		return;
	}
	build(P, L, M);
	build(P + 1, M + 1, R);
	pull(p);
}

void update(int p, int L, int R) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p] = x;
		flag[p] = true;
		push(p, L, R);
		return;
	}
	update(P, L, M);
	update(P + 1, M + 1, R);
	pull(p);
}

void update(int a, int b) {
	assert(chain[a] == chain[b]);
	int trail = chain[a];
	st = tree + (headp[trail] << 2);
	a = pos[a], b = pos[b];
	if (a > b) swap(a, b);
	::a = a;
	::b = b;
	update(1, headp[trail], headp[trail + 1] - 1);
}

node *merge(node *a, node *b) {
	node *m = new node(*a, *b);
	delete a, b; return m;
}

node *query(int p, int L, int R) {
	push(p, L, R);
	if (b < L || R < a) return new node();
	if (a <= L && R <= b) return new node(st[p]);
	node *left = query(P, L, M);
	node *right = query(P + 1, M + 1, R);
	pull(p); return merge(left, right);
}

node *query(int a, int b) {
	assert(chain[a] == chain[b]);
	int trail = chain[a];
	st = tree + (headp[trail] << 2);
	a = pos[a], b = pos[b];
	if (a > b) swap(a, b);
	::a = a;
	::b = b;
	return query(1, headp[trail], headp[trail + 1] - 1);
}

void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	for (int i = 0; i < size[u]; ++i) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			dep[v] = dep[u] + 1;
			dfsHeavy(v);
			weight[u] += weight[v];
			if (heavy[u] == -1 || weight[heavy[u]] < weight[v])
				heavy[u] = v;
		}
	}
}

void dfsLight(int u) {
	if (head[ch] == -1) {
		head[ch] = u;
		headp[ch] = ptr;
	}
	chain[u] = ch;
	pos[u]   = ptr;
	// id[ptr]  = u;
	arr[ptr] = cost[u];
	ptr++;
	if (heavy[u] != -1) dfsLight(heavy[u]);
	for (int i = 0; i < size[u]; ++i) {
		int v = adj[u][i];
		if (par[u] != v && heavy[u] != v) {
			ch++;
			dfsLight(v);
		}
	}
}

void heavyLight(int root) {
	for (int i = 0; i < n; ++i)
		head[i] = par[i] = -1;
	dep[root] = ptr = ch = 0;
	dfsHeavy(root); dfsLight(root);
	headp[++ch] = n;
	for (int i = 0; i < ch; ++i) {
		st = tree + (headp[i] << 2);
		build(1, headp[i], headp[i + 1] - 1);
	}
}

void updateUp(int a, int b) {
	while (chain[a] != chain[b]) {
		int ha = head[chain[a]];
		int hb = head[chain[b]];
		if (dep[ha] < dep[hb]) {
			update(hb, b);
			b = par[hb];
		}
		else {
			update(ha, a);
			a = par[ha];
		}
	}
	update(a, b);
}


int queryUp(int a, int b) {
	node *lnode = new node();
	node *rnode = new node();
	while (chain[a] != chain[b]) {
		int ha = head[chain[a]];
		int hb = head[chain[b]];
		if (dep[ha] > dep[hb]) {
			node *q = query(ha, a);
			lnode = merge(q, lnode);
			a = par[ha];
		}
		else {
			node *q = query(hb, b);
			rnode = merge(q, rnode);
			b = par[hb];
		}
	}
	node *q = query(a, b);
	if (dep[a] > dep[b]) lnode = merge(q, lnode);
	else                 rnode = merge(q, rnode);
	if (lnode) swap(lnode->pre, lnode->suf);
	return merge(lnode, rnode)->res;
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	for (int i = 1; i < n; ++i) {
		cin >> a >> b; --a, --b;
		++size[a]; ++size[b];
		head[i] = a; par[i] = b;
	}
	for (int i = 0; i < n; ++i)
		adj[i] = new int[size[i]];
	for (int i = 1; i < n; ++i) {
		a = head[i]; b = par[i];
		adj[a][heavy[a]++] = b;
		adj[b][heavy[b]++] = a;
	}
	heavyLight(rand() % n);
	cin >> m;
	while (m--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b; --a, --b;
			cout << queryUp(a, b) << '\n';
		}
		else if (cmd == 2) {
			cin >> a >> b >> x; --a, --b;
			updateUp(a, b);
		}
	}
	cout << flush;
}