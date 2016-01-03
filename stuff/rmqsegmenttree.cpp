// Range Min/Max Query (Segment Tree)
// SPOJ RMQSQ - Range Minimum Query

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
#define N 100005
#define INF INT_MAX

int tree[N * 2];
int get(int i) { return tree[i + N]; }
int update(int i, int x) { // arr[i] = x
	for (tree[i += N] = x; i; i >>= 1)
		tree[i] = min(tree[i], x);
}
int query(int a, int b) { // max[a, b]
	int ans = get(a); // sentinel
	for (a += N, b += N + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1) ans = min(ans, tree[a++]);
		if (b & 1) ans = min(ans, tree[--b]);
	}
	return ans;
}

int n, x, q, a, b;

int main() {
	for (int i = 0; i < N * 2; ++i)
		tree[i] = INF;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		{ cin >> x; update(i, x); }
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << query(a, b) << endl;
	}
	cout << flush;
}