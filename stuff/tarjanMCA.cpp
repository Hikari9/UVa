// https://cw.fel.cvut.cz/wiki/_media/courses/a4m33pal/cviceni/tarjan-finding-optimum-branchings.pdf

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct edge {
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
	bool operator < (const edge& e) const {
		return w < e.w;
	}
};

set<int> roots, rset;
set<edge> H;
priority_queue<edge> adj[N]; // adj matrix

int S[N], W[N], mn[N];
edge enter[N];
int find(int f[], int x) { return f[x] == x ? x : (f[x] = find(f, f[x])); }
void merge(int f[], int x, int y) {
	x = find(x);
	y = find(y);
	f[x] = y;
}

void branch() {
	roots.clear();
	for (int i = 0; i < n; ++i) {
		S[i] = W[i] = i;
		enter[i] = edge(0, 0);
		mn[i] = i;
		if (!adj[i].empty())
			roots.insert(i);
	}
	H.clear();
	rset.clear();
	while (!roots.empty()) {
		int k = *roots.begin();
		roots.erase(roots.begin());
		edge e = adj[k].top(); adj[k].pop();
		int i = e.u, j = e.v;
		if (cost(e) <= 0)
			rset.insert(k);
		else if (find(S, i) == k)
			roots.insert(k);
		else {
			H.insert(e);
			if (find(W, i) != find(W, j)) {
				merge(W, i, j);
				enter[k] = e;
			}
			else {
				int val = INF;
				int xy = e, vertex;
				#define x xy.u
				#define y xy.v
				while (x != 0 && y != 0) {
					if (cost(xy) < val) {
						val = cost(xy);
						vertex = find(S, y);
					}
					xy = enter[find(S, x)];
				}
				int toAdd = val - cost(e);
				add[k] += toAdd;
				mn[k] = mn[vertex];
				xy = enter[find(S, i)];
				while (x != 0 && y != 0) {
					toAdd = val - cost(e);
					add[find(S, y)] += toAdd;
					while (!adj[find(S, y)].empty()) {
						adj[k].push(adj[find(S, y)].top());
						adj[find(S, y)].pop();
					}
					merge(k, find(S, y));
					xy = enter[find(S, x)];
				}
				roots.insert(k);
			}
		}
	}
}

int main() {
	
}