#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define M ((L + R) >> 1)
#define P (p << 1)

using namespace std;
const int N = 100001;
typedef long long lag;

int n, m, t, a, b;
lag x;
lag color[N << 2], sum[N << 2], lazy[N << 2];

void pull(int p) {
	sum[p] = sum[P] + sum[P + 1];
	if (color[P] == color[P + 1])
		color[p] = color[P];
	else
		color[p] = 0;
}

void push(int p, int L, int R) {
	if (color[p] && L != R)
		color[P] = color[P + 1] = color[p];
	if (lazy[p]) {
		sum[p] += lazy[p] * (R - L + 1);
		if (L != R) {
			lazy[P] += lazy[p];
			lazy[P + 1] += lazy[p];
		}
		lazy[p] = 0;
	}
}

void update(int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b && color[p]) {
		lazy[p] += abs(color[p] - x);
		color[p] = x;
		push(p, L, R);
		return;
	}
	update(P, L, M);
	update(P + 1, M + 1, R);
	pull(p);
}

lag query(int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return sum[p];
	lag q = query(P, L, M) + query(P + 1, M + 1, R);
	pull(p); return q;
}

void build(int p = 1, int L = 1, int R = n) {
	sum[p] = lazy[p] = 0;
	if (L == R) {
		color[p] = L;
		return;
	}
	build(P, L, M);
	build(P + 1, M + 1, R);
	pull(p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	build();
	while (m--) {
		cin >> t >> a >> b;
		if (t == 1) {
			cin >> x;
			update();
		}
		else {
			cout << query() << '\n';
		}
	}
	cout << flush;
}