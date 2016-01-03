// SPOJ GM Plants
// http://www.spoj.com/problems/IOPC1207/

#include <iostream>
#include <cstdio>
#include <cstring>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100001;

struct SegmentTree {
	int st[N << 2]; bool lazy[N << 2];
	int n;
	void init(int n) {
		this->n = n;
		memset(st, 0, sizeof(int) * (n << 2));
		memset(lazy, 0, sizeof(bool) * (n << 2));
	}
	void push(int p, int L, int R) {
		if (lazy[p]) {
			st[p] = R - L + 1 - st[p];
			lazy[p] = 0;
			if (L != R) {
				lazy[P] ^= 1;
				lazy[P + 1] ^= 1;
			}
		}
	}
	void pull(int p) {
		st[p] = st[P] + st[P + 1];
	}
	int query(int a, int b) { return query(a, b, 1, 0, n - 1); }
	int query(int a, int b, int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return 0;
		if (a <= L && R <= b) return st[p];
		int q = query(a, b, P, L, M) + query(a, b, P + 1, M + 1, R);
		pull(p); return q;
	}
	void flip(int a, int b) { flip(a, b, 1, 0, n - 1); }
	void flip(int a, int b, int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy[p] ^= 1;
			push(p, L, R);
			return;
		}
		flip(a, b, P, L, M);
		flip(a, b, P + 1, M + 1, R);
		pull(p);
	}
} tree[3];

int t, nx, ny, nz, q, cmd, a, b;
int x, y, z, xx, yy, zz;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> nx >> ny >> nz >> q;
		tree[0].init(nx);
		tree[1].init(ny);
		tree[2].init(nz);
		while (q--) {
			cin >> cmd;
			if (cmd < 3) {
				cin >> a >> b;
				tree[cmd].flip(a, b);
			}
			else {
				cin >> x >> y >> z >> xx >> yy >> zz;
				int xred = tree[0].query(x, xx);
				int yred = tree[1].query(y, yy);
				int zred = tree[2].query(z, zz);
				int xgreen = xx - x + 1 - xred;
				int ygreen = yy - y + 1 - yred;
				int zgreen = zz - z + 1 - zred;
				long long allred = 1LL * xred * yred * zred;
				allred += 1LL * xred * ygreen * zgreen;
				allred += 1LL * yred * xgreen * zgreen;
				allred += 1LL * zred * xgreen * ygreen;
				cout << allred << '\n';
			}
		}
	}
	cout << flush;
}