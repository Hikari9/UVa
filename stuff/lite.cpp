#include <bits/stdc++.h>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100001;

int n, m, st[N << 2], lz[N << 2];

void push(int p, int L, int R) {
	if (lz[p]) {
		st[p] = R - L + 1 - st[p];
		if (L != R) {
			lz[P] ^= 1;
			lz[P + 1] ^= 1;
		}
		lz[p] = 0;
	}
}

void pull(int p) {
	st[p] = st[P] + st[P + 1];
}

void update(int a, int b, int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lz[p] ^= 1;
		push(p, L, R);
		return;
	}
	update(a, b, P, L, M);
	update(a, b, P + 1, M + 1, R);
	pull(p);
}

int query(int a, int b, int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return st[p];
	int q = query(a, b, P, L, M) + query(a, b, P + 1, M + 1, R);
	pull(p); return q;
}

int cmd, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> cmd >> L >> R;
		if (cmd) {
			cout << query(L, R) << '\n';
		}
		else {
			update(L, R);
		}
	}
	cout << flush;
}