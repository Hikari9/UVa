// CodeForces 165D : Beard Graph
// Segment Tree
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#define MX 100001
#define BLACK 0
#define WHITE 1

using namespace std;

int e1[MX], e2[MX];

vector<int> adj[MX];
int n, m;
int * st[MX];
int group[MX], g_id, root;
int id[MX], size[MX];
int type, new_value, node;

void build(int * st, int p, int L, int R) {
	st[p] = BLACK;
	if (L == R)
		return;
	int P = (p << 1);
	int M = (L + R) >> 1;
	build(st, P, L, M);
	build(st, P+1, M+1, R);
}

void update(int * st, int p, int L, int R) {
	if (L > node || R < node)
		return;
	if (L == R) {
		st[p] = new_value;
		return;
	}
	int P = (p << 1);
	int M = (L + R) >> 1;
	update(st, P, L, M);
	update(st, P+1, M+1, R);
	st[p] = max(st[P], st[P+1]);
}

int query(int * st, int p, int L, int R, int l, int r) {
	if (L > r || R < l)
		return BLACK;
	if (l <= L && R <= r)
		return st[p];
	int P = (p << 1);
	int M = (L + R) >> 1;
	return max(query(st, P, L, M, l, r), query(st, P+1, M+1, R, l, r));
}

int toEdge(int a) {
	if (a == root)
		return 0;
	if (adj[a].size() == 1)
		return adj[a][0];
	int e1 = adj[a][0];
	int e2 = adj[a][1];
	return (id[e1] < id[e2] ? e1 : e2); 
}

void prepare();

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		e1[i] = u;
		e2[i] = v;
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	prepare();
	scanf("%d", &m);
	while (m-- > 0) {
		scanf("%d", &type);
		if (type < 3) {
			scanf("%d", &node);
			new_value = type - 1;
			int g = group[node];
			node = id[node];
			update(st[g], 1, 0, size[g] - 1);
			
		}
		else {
			int a, b, ans = -1;
			scanf("%d%d", &a, &b);
			if (a == b) {
				printf("0\n");
				continue;
			}
			a = toEdge(a-1);
			b = toEdge(b-1);
			if (group[a] == group[b]) {
				int g = group[a];
				a = id[a];
				b = id[b];
				if (b < a) swap(a, b);
				// cout << "\t" << a << " " << b << endl;
				int q = query(st[g], 1, 0, size[g] - 1, a+1, b);
				if (q == BLACK)
					ans = b - a;
			}
			else {
				int g1 = group[a];
				int g2 = group[b];
				a = id[a];
				b = id[b];
				int q1 = query(st[g1], 1, 0, size[g1] - 1, 0, a);
				int q2 = query(st[g2], 1, 0, size[g2] - 1, 0, b);
				if (max(q1, q2) == BLACK)
					ans = a + b;
			}
			printf("%d\n", ans);
		}
	}
}

void dfs(int edge, int u) {
	int id = 1;
	while (true) {
		group[edge] = g_id;
		::id[edge] = id++;
		int v = (e1[edge] == u ? e2[edge] : e1[edge]);
		if (adj[v].size() == 1) break;
		edge = adj[v][e1[adj[v][0]] == u || e2[adj[v][0]] == u];
		u = v;
	}
	size[g_id] = id;
}

void prepare() {
	root = -1;
	for (int i=0; i<n; ++i) {
		if (adj[i].size() > 2) {
			root = i;
			break;
		}
	}
	if (root == -1) {
		for (int i=0; i<n; ++i) {
			if (adj[i].size() == 1) {
				root = i;
				break;
			}
		}
	}
	size[0] = size[1] = size[2] = 1;
	for (int i=0; i<adj[root].size(); ++i) {
		g_id = i;
		dfs(adj[root][i], root);
		// cout << g_id << " " << size[g_id] << endl;
	}
	for (int i=0; i<adj[root].size(); ++i) {
		st[i] = new int[size[i] << 2];
		build(st[i], 1, 0, size[i] - 1);
	}
}
