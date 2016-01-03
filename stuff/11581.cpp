// UVa 11581 - Grid Successors
// 0.000s :D :D :D

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 512;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int transform(int mask) {
	int next = 0;
	for (int i = 0; i < 9; ++i) {
		int x = i / 3;
		int y = i % 3;
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
				int j = nx * 3 + ny;
				next ^= (mask & (1 << j)) ? (1 << i) : 0;
			}
		}
	}
	return next;
}

char ch;
int id[N], low[N], adj[N], t;
int stack[N], in[N], size[N], SCC[N], top, ID;

// tarjan
void dfs(int u) {
	id[u] = low[u] = ID++;
	in[u] = true;
	stack[top++] = u;
	int v = adj[u];
	if (u != v) {
		if (id[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in[v]) {
			low[u] = min(low[u], id[v]);
		}
	}
	if (id[u] == low[u]) {
		do {
			in[stack[--top]] = false;
			SCC[stack[top]] = u;
			size[u]++;
		} while (stack[top] != u);
	}
}

int dp[N] = {-1};
int nextCycle(int x) {
	if (dp[x] != -2)
		return dp[x];
	return dp[x] = nextCycle(adj[x]) + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < N; ++i) {
		adj[i] = transform(i);
	}
	memset(id, -1, sizeof id);
	for (int i = 0; i < N; ++i) {
		if (id[i] == -1) dfs(i);
	}
	for (int i = 0; i < N; ++i) {
		dp[i] = -2;
		if (size[SCC[i]] > 1 || adj[i] == i)
			dp[i] = -1;
	}
	dp[0] = -1;
	cin >> t;
	while (t--) {
		int mask = 0;
		for (int i = 0; i < 9; ++i) {
			cin >> ch;
			if (ch == '1')
				mask |= (1 << i);
		}
		cout << nextCycle(mask) << '\n';
	}
	cout << flush;
}