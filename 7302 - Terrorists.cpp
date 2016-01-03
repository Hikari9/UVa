/**
	Live Archive 7302 - Terrorists
	https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=690&page=show_problem&problem=5314
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
using namespace std;
const int N = 50055;

int t, n, m, q, tc, eu[N], ev[N], ew[N], small[N], big[N], nn;
int tour[N], h[N*2], id[N*2], st[18][N*2], lg[N*2], ID;
long long W[N], D[55][55], dist[55];
inline int other(int u, int i) {return eu[i]==u?ev[i]:eu[i];}
vector<int> tree[N];

void dfs(int u, int p=-1, int dep=0) {
	tour[u] = ID;
	h[u] = dep;
	id[ID] = u;
	ID++;
	// cout << string(dep, ' ') << u << endl;
	for (int i = 0; i < tree[u].size(); ++i) {
		int e = tree[u][i];
		int v = other(u, e);
		if (v != p) {
			W[v] = W[u] + ew[e];
			dfs(v, u, dep + 1);
			// cout << e << ": " << u << ' ' << v << ' ' << ew[e] << ' ' << W[v] << endl;
			id[ID] = u;
			ID++;
		}
	}
}

void build_lca() {
	ID = 0;
	W[1] = 0;
	dfs(1);
	for (int i = 0; i < ID; ++i)
		st[0][i] = id[i];
	for (int j = 0; (2 << j) <= ID; ++j) {
		for (int i = 0; i + (2 << j) <= ID; ++i) {
			int k = i + (1 << j);
			st[j+1][i] = (h[st[j][i]] < h[st[j][k]] ? st[j][i] : st[j][k]);
		}
	}
}

int lca(int a, int b) {
	a = tour[a];
	b = tour[b];
	if (a > b) swap(a, b);
	int k = lg[b - a + 1];
	int ab = b - (1 << k) + 1;
	return h[st[k][a]] < h[st[k][ab]] ? st[k][a] : st[k][ab];
}

long long path(int a, int b) {
	long long p = W[a] + W[b] - 2 * W[lca(a, b)];
	return p;
}

int f[N];
struct cmp{bool operator()(int i, int j) const {return ew[i] > ew[j];}};
bool used[N];
int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}

void mcst() {
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 1; i <= n; ++i) f[i] = i, tree[i].clear();
	for (int i = 0; i < m; ++i) pq.push(i), used[i] = false;
	while (!pq.empty()) {
		int e = pq.top(); pq.pop();
		int a = find(eu[e]);
		int b = find(ev[e]);
		if (a != b) {
			used[e] = true;
			tree[eu[e]].push_back(e);
			tree[ev[e]].push_back(e);
			f[a] = b;
		}
	}
	nn = 0;
	for (int i = 0; i < 55; ++i)
		for (int j = 0; j < 55; ++j)
			D[i][j] = i==j?0:INF;
	for (int i = 0; i < m; ++i) {
		if (!used[i]) {
			int u = eu[i], v = ev[i];
			int& su = small[u];
			int& sv = small[v];
			if (!su) su = nn++;
			if (!sv) sv = nn++;
			big[su] = u;
			big[sv] = v;
			D[su][sv] = D[sv][su] = min(D[su][sv], 0LL+ew[i]);
		}
	}
}

void floyd_warshall() {
	for (int i = 0; i < nn; ++i)
		for (int j = 0; j < nn; ++j)
				D[i][j] = min(D[i][j], path(big[i], big[j]));
	for (int k = 0; k < nn; ++k)
		for (int i = 0; i < nn; ++i)
			for (int j = 0; j < nn; ++j)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

long long dijkstra(int a, int b) {
	D[nn][nn] = D[nn+1][nn+1] = 0;
	D[nn+1][nn] = D[nn][nn+1] = path(a, b);
	for (int i = 0; i < nn; ++i) {
		D[i][nn] = D[nn][i] = path(a, big[i]);
		D[i][nn+1] = D[nn+1][i] = path(b, big[i]);
		dist[i] = INF;
	}
	dist[nn+1] = INF;
	dist[nn] = 0;
	priority_queue<pair<long long, int> > pq;
	pq.push(make_pair(0, nn));
	while (!pq.empty()) {
		long long w = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (dist[u] != w) continue;
		if (u == nn+1) return w;
		for (int v = 0; v <= nn+1; ++v) {
			if (w + D[u][v] < dist[v]) {
				dist[v] = w + D[u][v];
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
}

int main() {
	for (int i = 2; i < N*2; ++i)
		lg[i] = lg[i >> 1] + 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
		}
		mcst();
		build_lca();
		floyd_warshall();
		printf("Case %d:\n", ++tc);
		while (q--) {
			int a, b; scanf("%d%d", &a, &b);
			printf("%lld\n", dijkstra(a, b));
		}
	}
}