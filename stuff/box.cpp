#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100001;
typedef unsigned long long lag;
#define P (p << 1)
#define M ((L + R) >> 1)

int n, q;
lag arr[N], st[N << 2], z[N << 2], w, h;

void pull(int p) {
	st[p] = max(st[P], st[P + 1]);
}

void push(int p, int L, int R) {
	if (z[p]) {
		st[p] = max(st[p], z[p]);
		if (L != R) {
			z[P] = max(z[P], z[p]);
			z[P + 1] = max(z[P + 1], z[p]);
		}
		z[p] = 0;
	}
}

void build(int p = 1, int L = 0, int R = n - 1) {
	if (L == R) {
		st[p] = arr[L];
		return;
	}
	build(P, L, M); build(P + 1, M + 1, R);
	pull(p);
}

lag query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return st[p];
	lag q = max(query(a, b, P, L, M), query(a, b, P + 1, M + 1, R));
	pull(p); return q;
}

void update(int a, int b, lag x, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {z[p] = x; push(p, L, R); return;}
	update(a, b, x, P, L, M); update(a, b, x, P + 1, M + 1, R);
	pull(p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	build();
	cin >> q;
	while (q--) {
		cin >> w >> h; --w;
		lag base = query(0, w);
		cout << base << '\n';
		update(0, w, base + h);
	}
	cout << flush;
}