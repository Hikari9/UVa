// SPOJ GSS2

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100005;

long long sum[N << 2], rmq[N << 2], lazy[N << 2], bestlazy[N << 2], ans[N];
int n, m, a, b, arr[N], x[N];
int _last[N << 1], *last = _last + N;
vector<int> y[N];

void push(int p, int L, int R) {
	rmq[p] = max(rmq[p], sum[p] + bestlazy[p]);
	sum[p] += lazy[p];
	if (L != R) {
		bestlazy[P] = max(bestlazy[P], lazy[P] + bestlazy[p]);
		bestlazy[P + 1] = max(bestlazy[P + 1], lazy[P + 1] + bestlazy[p]);
		lazy[P]     += lazy[p];
		lazy[P + 1] += lazy[p];
	}
	lazy[p] = bestlazy[p] = 0;
}

void pull(int p) {
	sum[p] = max(sum[P], sum[P + 1]);
	rmq[p] = max(rmq[P], rmq[P + 1]);
}

void update(int a, int b, int x, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p] = x;
		bestlazy[p] = max(bestlazy[p], (long long) x);
		push(p, L, R);
		return;
	}
	update(a, b, x, P, L, M);
	update(a, b, x, P + 1, M + 1, R);
	pull(p);
}

long long query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return rmq[p];
	long long q = max(query(a, b, P, L, M), query(a, b, P + 1, M + 1, R));
	pull(p); return q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b; --a, --b;
		x[i] = a;
		y[b].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		update(last[arr[i]], i, arr[i]);
		last[arr[i]] = i + 1;
		for (int j = 0; j < y[i].size(); ++j) {
			int id = y[i][j];
			int L = x[id];
			ans[id] = query(L, i);
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
	cout << flush;
}