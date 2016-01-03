// Line sweep - segment cover
// SPOJ NICEDAY - The day of the competitors
// http://www.spoj.com/problems/NICEDAY/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <map>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) / 2)

using namespace std;
const int N = 100005;

struct contestant {
	int a, b, c;
	bool operator < (const contestant& o) const { return c < o.c; }
};
int t, n, st[N << 2], lazy[N << 2];
contestant c[N];

void build() {
	fill(st, st + (n << 2), INT_MAX);
	fill(lazy, lazy + (n << 2), INT_MAX);
}
void push(int p, int L, int R) {
	if (lazy[p] != INT_MAX) {
		st[p] = min(st[p], lazy[p]);
		if (L != R) {
			lazy[P]     = min(lazy[p], lazy[P]);
			lazy[P + 1] = min(lazy[p], lazy[P + 1]);
		}
		lazy[p] = INT_MAX;
	}
}
void pull(int p) { st[p] = min(st[P], st[P + 1]); }
void update(int a, int b, int x, int p = 1, int L = 0, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p] = x;
		push(p, L, R);
		return;
	}
	update(a, b, x, P, L, M);
	update(a, b, x, P + 1, M + 1, R);
	pull(p);
}
int query(int a, int b, int p = 1, int L = 0, int R = n) {
	push(p, L, R);
	if (b < L || R < a) return INT_MAX;
	if (a <= L && R <= b) return st[p];
	int q = min(query(a, b, P, L, M), query(a, b, P + 1, M + 1, R));
	pull(p); return q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t-- > 0) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> c[i].a >> c[i].b >> c[i].c;
		sort(c, c + n);
		build();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (query(c[i].a, c[i].a) > c[i].b) {
				update(c[i].a, n, c[i].b);
				ans++;
			}
		}
		cout << ans << '\n';
	}
	cout << flush;
}