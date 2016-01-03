// Can you answer these queries
// http://www.spoj.com/problems/GSS7/

#include <bits/stdc++.h>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100001;

int n, q, cmd, A, B, C;

namespace graph {
	void input();
	void decompose(int);
	void updateUp(int, int, int);
	int queryUp(int, int);
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	graph::input();
	graph::decompose((rand() % n) + 1);
	cin >> q;
	while (q-- > 0) {
		cin >> cmd >> A >> B;
		if (cmd == 1) {
			cout << graph::queryUp(A, B) << '\n';
		}
		else {
			cin >> C;
			graph::updateUp(A, B, C);
		}
	}
	cout << flush;
}

struct node {
	int pre, suf, sum, res;
	node(const node& a) {
		pre = a.pre;
		suf = a.suf;
		sum = a.sum;
		res = a.res;
	}
	node(int x = 0) { assign(x); }
	void assign(int x) {
		sum = x;
		pre = suf = res = max(x, 0);
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
};

node *merge(node *a, node *b) {
	if (!a) return b;
	if (!b) return a;
	node *m = new node(*a, *b);
	delete a, b; return m;
}

const int SegmentSize = (N << 2);
bool _flag[SegmentSize];
int _lazy[SegmentSize];
node _st[SegmentSize];
int segment = 0;

struct SegmentTree {
	bool *flag; int n;
	int *arr, *lazy;
	node *st;
	SegmentTree(int *arr, int n): arr(arr), n(n) {
		assert(segment + (n << 2) < SegmentSize);
		st = _st + segment;
		lazy = _lazy + segment;
		flag = _flag + segment;
		segment += (n << 2);
		build(1, 0, n - 1);
	}
	void pull(int p) {
		st[p].pull(st[P], st[P + 1]);
	}
	void push(int p, int L, int R) {
		if (flag[p]) {
			int& Z = lazy[p];
			st[p].assign(Z * (R - L + 1));
			if (L != R) {
				flag[P] = flag[P + 1] = true;
				lazy[P] = lazy[P + 1] = Z;
			}
			Z = 0;
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
	int a, b; int x;
	void update(int a, int b, int x) {
		if (b < a) swap(a, b);
		this->a = a;
		this->b = b;
		this->x = x;
		_update(1, 0, n - 1);
	}
	void _update(int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy[p] = x;
			flag[p] = true;
			push(p, L, R);
			return;
		}
		_update(P, L, M);
		_update(P + 1, M + 1, R);
		pull(p);
	}
	node *query(int a, int b) {
		if (b < a) swap(a, b);
		this->a = a;
		this->b = b;
		return _query(1, 0, n - 1);
	}
	node *_query(int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return NULL;
		if (a <= L && R <= b) return new node(st[p]);
		node *left = _query(P, L, M);
		node *right = _query(P + 1, M + 1, R);
		pull(p); return merge(left, right);
	}
};

// graph properties
namespace graph {
	int *adj[N], degree[N];
	int cost[N];
}

// chains
namespace graph {
	int master[N];
	int pointer, pos[N];

	struct Chain;
	Chain *chain[N];

	struct Chain {
		int *arr;
		int size, head;
		SegmentTree *tree;
		Chain(int head): head(head), size(0), tree(NULL) {
			arr = master + pointer;
		}
		void add(int node) {
			chain[node] = this;
			pos[node] = size;
			arr[size++] = cost[node];
			pointer++; // for master array
		}
		void prepare() {
			if (tree) return;
			tree = new SegmentTree(arr, size);
		}
	};

}

// heavy light decomposition
namespace graph {
	int heavy[N], weight[N], par[N], dep[N];
	
	void dfsHeavy(int);
	void dfsLight(int, Chain*);
	void decompose(int root) {
		dfsHeavy(root);
		dfsLight(root, new Chain(root));
		// prepare chains
		for (int i = 1; i <= n; ++i) {
			chain[i]->prepare();
		}
	}
}

// upward update / queries
namespace graph {

	node *query(int u, int v) {
		assert(chain[u] == chain[v]);
		return chain[u]->tree->query(pos[u], pos[v]);
	}

	void update(int u, int v, int x) {
		assert(chain[u] == chain[v]);
		chain[u]->tree->update(pos[u], pos[v], x);
	}

	void updateUp(int u, int v, int x) {
		while (chain[u] != chain[v]) {
			// process lower node first
			if (dep[chain[u]->head] > dep[chain[v]->head]) {
				update(u, chain[u]->head, x);
				u = par[chain[u]->head];
			}
			else {
				update(v, chain[v]->head, x);
				v = par[chain[v]->head];
			}
		}
		update(u, v, x);
	}

	// get max contiguous sum from u to v
	int queryUp(int u, int v) {
		node *left = new node(); // u side up
		node *right = new node(); // v side up
		while (chain[u] != chain[v]) {
			// process lower node first
			if (dep[chain[u]->head] > dep[chain[v]->head]) {
				node *upper = query(u, chain[u]->head);
				left = merge(upper, left);
				u = par[chain[u]->head];
			}
			else {
				node *upper = query(v, chain[v]->head);
				right = merge(upper, right);
				v = par[chain[v]->head];
			}
		}
		node *upper = query(u, v);
		if (dep[u] > dep[v]) {
			// go up from u to v
			left = merge(upper, left);
		}
		else {
			// go up from v to u
			right = merge(upper, right);
		}
		// merge left nodes and right nodes
		if (left) swap(left->pre, left->suf);
		node *ans = merge(left, right);
		int value = ans->res;
		delete ans;
		return value;
	}
}

// heavy-light DFS stuff
namespace graph {
	void dfsLight(int u, Chain *chain) {
		chain->add(u);
		if (heavy[u])
			dfsLight(heavy[u], chain);
		for (int i = 0; i < degree[u]; ++i) {
			int v = adj[u][i];
			if (par[u] != v && heavy[u] != v) {
				dfsLight(v, new Chain(v));
			}
		}
	}
	void dfsHeavy(int u) {
		weight[u] = 1;
		for (int i = 0; i < degree[u]; ++i) {
			int v = adj[u][i];
			if (par[u] != v) {
				par[v] = u;
				dep[v] = dep[u] + 1;
				dfsHeavy(v);
				weight[u] += weight[v];
				if (!heavy[u] || weight[heavy[u]] < weight[v])
					heavy[u] = v;
			}
		}
	}
}

// graph input
namespace graph {
	int a[N], b[N], edge[N];
	void input() {
		for (int i = 1; i <= n; ++i)
			cin >> cost[i];
		for (int i = 1; i < n; ++i) {
			cin >> a[i] >> b[i];
			++degree[a[i]]; ++degree[b[i]];
		}
		for (int i = 1; i <= n; ++i) {
			adj[i] = new int[degree[i]];
			edge[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			int u = a[i];
			int v = b[i];
			adj[u][edge[u]++] = v;
			adj[v][edge[v]++] = u;
		}
	}
}