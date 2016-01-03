#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
typedef multiset<int, greater<int> > treeset;
enum    { BLACK = 0, WHITE };

int n;
int chain[N], heavy[N], weight[N], rmq[N << 1], chains;
int pos[N], id[N], par[N], arr[2][N], ptr;
int head[N], cost[N], color[N], tail[N], representative[N];
vector<int> adj[N];
treeset tree[2][N], light[N][2];

// RMQ start
inline void update(int i, int x) {
	for (rmq[i += n] = x; i > 0; i >>= 1)
		rmq[i >> 1] = max(rmq[i], rmq[i ^ 1]);
}

inline int query(int a, int b) {
	if (b < a) swap(a, b);
	int mx = INT_MIN;
	for (a += n, b += n + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1) mx = max(mx, rmq[a++]);
		if (b & 1) mx = max(mx, rmq[--b]);
	} return mx;
}
// RMQ end
// DIRECT ANCESTOR: get node farthest up the chain of the same color
inline int directAncestor(int u) {
	treeset& trail = tree[!color[u]][chain[u]];
	if (trail.empty() || *trail.rbegin() > pos[u])
		return head[chain[u]];
	if (*trail.begin() < pos[u])
		return id[*trail.begin() + 1]; // optimization
	return id[*trail.lower_bound(pos[u]) + 1];
}
// DIRECT ANCESTOR end
// DESCENDANT: get node farthest node down the chain of the same color
inline int descendant(int u) {
	treeset& trail = tree[!color[u]][chain[u]];
	if (trail.empty() || *trail.begin() < pos[u])
		return tail[chain[u]];
	if (*trail.rbegin() > pos[u]) 
		return id[*trail.rbegin() - 1]; // optimization
	return id[*--trail.lower_bound(pos[u]) - 1];
}
// DESCENDANT end
// ANCESTOR: get node fathest up the tree of the chain color
inline int ancestor(int u) {
	while (true) {
		int A = directAncestor(u);
		if (A != head[chain[A]] || (A == head[chain[A]] && (par[A] == -1 || color[A] != color[par[A]])))
			return A;
		u = par[A];
	}
}
// ANCESTOR end
// GREAT ANCESTOR: get node right above the ancestor, regardless of color.
inline int greatAncestor(int u) {
	int A = ancestor(u);
	return par[A] == -1 ? A : par[A];
}
// GREAT ANCESTOR end
// CHAIN QUERY: get representative of top part of chain
inline int chainQuery(int ch) {
	return query(pos[head[ch]], pos[descendant(head[ch])]);
}
// CHAIN QUERY end
// DFS HEAVY: assign heavy children and node weights
void dfsHeavy(int u) {
	weight[u] = 1;
	heavy[u] = -1;
	light[u][WHITE].clear();
	light[u][BLACK].clear();
	for (int i = 0, I = adj[u].size(); i < I; ++i) {
		int v = adj[u][i];
		if (v != par[u]) {
			par[v] = u;
			dfsHeavy(v);
			weight[u] += weight[v];
			if (heavy[u] == -1 || weight[heavy[u]] < weight[v])
				heavy[u] = v;
		}
	}
}
// DFS HEAVY end
// DFS LIGHT: assign chains to each node
void dfsLight(int u) {
	tail[chains] = u;
	if (head[chains] == -1) {
		head[chains] = u;
		tree[WHITE][chains].clear();
		tree[BLACK][chains].clear();
	}
	pos[u]      = ptr;
	chain[u]    = chains;
	id[ptr]     = u;
	tree[color[u]][chains].insert(pos[u]);
	light[u][color[u]].insert(cost[u]);
	light[u][!color[u]].insert(cost[u]);
	ptr++;
	if (heavy[u] != -1)
		dfsLight(heavy[u]); // continue chain
	for (int i = 0, I = adj[u].size(); i < I; ++i) {
		int v = adj[u][i];
		if (v != par[u] && v != heavy[u]) {
			chains++;
			dfsLight(v);
			// get representative of chain v
			light[u][color[v]].insert(representative[chain[v]]);
		}
	}
	// update subtree RMQ from light edges
	update(pos[u], *light[u][color[u]].begin());
	if (u == head[chain[u]])
		representative[chain[u]] = chainQuery(chain[u]);
}
// DFS LIGHT end
// HEAVY LIGHT: perform heavy-light decomposition on tree with random root
inline void heavyLight(int root) {
	for (int i = 0; i < n; ++i)
		head[i] = par[i] = -1;
	dfsHeavy(root); dfsLight(root);
}
// HEAVY LIGHT end
// QUERY UP: get the maximum on all connected nodes to u with the same color
inline int queryUp(int u) {
	int A = ancestor(u);
	// printf("query: u=%d anc=%d desc=%d val=%d\n", u, A, descendant(A), query(pos[A], pos[descendant(A)]));
	return query(pos[A], pos[descendant(A)]);
}
inline int tediousQuery(int u) {
	int A = ancestor(u), ans = INT_MIN;
	while (chain[u] != chain[A]) {
		ans = max(ans, chainQuery(chain[u]));
		u = par[head[chain[u]]];
	}
	return max(ans, query(pos[A], pos[descendant(A)]));
}
// QUERY UP end
// UPDATE UP: reupdate all representatives of connected ancestors of A with the same color
void updateUp(int u) {
	int c = color[u];
	int gA = greatAncestor(u);
	while (chain[u] != chain[gA]) {
		int value = chainQuery(chain[u]);
		int& rep = representative[chain[u]];
		int h = head[chain[u]];
		treeset& subtree = light[par[h]][c];
		subtree.erase(rep);
		subtree.insert(value);
		rep = value;
		update(pos[par[h]], *subtree.begin());
		u = par[h];
	}
	if (par[gA] != -1) updateUp(gA);
}
// UPDATE UP: end
// CHANGE COST: change cost of this node to w
inline void changeCost(int u, int w) {
	treeset& same = light[u][color[u]];
	treeset& diff = light[u][!color[u]];
	same.erase(cost[u]);
	diff.erase(cost[u]);
	same.insert(w);
	diff.insert(w);
	cost[u] = w;
	update(pos[u], *same.begin());
	updateUp(u);
}
// CHANGE COST end
// TOGGLE: toggle color of node u
inline void toggle(int u) {
	int& c = color[u];
	// step 1: change trees
	treeset& before = tree[c][chain[u]];
	treeset& after = tree[!c][chain[u]];
	before.erase(pos[u]);
	after.insert(pos[u]);
	// step 3: toggle color
	c ^= 1;
	// step 4: change value of rmq node into new max
	update(pos[u], *light[u][c].begin());
	// step 2: if u is a head of a chain, remove representative of chain first
	if (u == head[chain[u]] && par[u] != -1) {
		treeset& parent = light[par[u]][c];
		light[par[u]][!c].erase(representative[chain[u]]);
		light[par[u]][c].insert(representative[chain[u]]);
	}
	// step 5: update chains
	updateUp(u);
}

void debug(int u) {
	int A = ancestor(u);
	cout << "Ancestor: " << u << " " << A << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d: node=%d chain=%d cost=%d sub=%d color=%d black=", i, id[i], chain[id[i]], cost[id[i]], query(i, i) == INT_MIN ? 0 : query(i, i), color[id[i]]);
		for (treeset::iterator it = light[id[i]][BLACK].begin(); it != light[id[i]][BLACK].end(); ++it)
			printf("%d,", *it);
		printf("  \twhite=");
		for (treeset::iterator it = light[id[i]][WHITE].begin(); it != light[id[i]][WHITE].end(); ++it)
			printf("%d,", *it);
		printf("\n");
	}
}

int q, t, u, w, a, b;

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
	for (int i = 0; i < n; ++i)
		cin >> color[i];
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	heavyLight(rand() % n);
	cin >> q;
	while (q--) {
		cin >> t >> u; --u;
		// debug(u);
		if (t == 0) {
			assert(queryUp(u) == tediousQuery(u));
			cout << queryUp(u) << '\n';
		}
		else if (t == 1) {
			toggle(u);
		}
		else {
			cin >> w;
			changeCost(u, w);
		}
	}
	cout << flush;
}
