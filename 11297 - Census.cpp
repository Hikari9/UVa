// UVa 11297 - Census
// 0.055s C++ Rank 1, bitch
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2272

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
const int N = 505;

int n, m, q, a1, a2, b1, b2, mn, mx, x, y, v;
int t1[N<<1][N<<1], t2[N<<1][N<<1];
char cmd;

inline void build() {
	for (int i = 2 * n - 1; i > 0; --i) {
		for (int j = 2 * m - 1; j > 0; --j) {
			t1[i][j >> 1] = min(t1[i][j], t1[i][j^1]);
			t2[i][j >> 1] = max(t2[i][j], t2[i][j^1]);
			t1[i >> 1][j] = min(t1[i][j], t1[i ^ 1][j]);
			t2[i >> 1][j] = max(t2[i][j], t2[i ^ 1][j]);
		}
	}
}

inline void update() {
	t1[x + n][y + m] = t2[x + n][y + m] = v;
	for (int i = x + n; i > 0; i >>= 1) {
		for (int j = y + m; j > 0; j >>= 1) {
			t1[i][j >> 1] = min(t1[i][j], t1[i][j ^ 1]);
			t2[i][j >> 1] = max(t2[i][j], t2[i][j ^ 1]);
			t1[i >> 1][j] = min(t1[i][j], t1[i ^ 1][j]);
			t2[i >> 1][j] = max(t2[i][j], t2[i ^ 1][j]);
		}
	}
}

inline void query() {
	mn = INT_MAX;
	mx = INT_MIN;
	for (int i1 = a1 + n, i2 = a2 + n + 1; i1 < i2; i1 >>= 1, i2 >>= 1) {
		if (i1 & 1) {
			for (int j1 = b1 + m, j2 = b2 + m + 1; j1 < j2; j1 >>= 1, j2 >>= 1) {
				if (j1 & 1) {
					mn = min(mn, t1[i1][j1]);
					mx = max(mx, t2[i1][j1]);
					++j1;
				}
				if (j2 & 1) {
					--j2;
					mn = min(mn, t1[i1][j2]);
					mx = max(mx, t2[i1][j2]);
				}
			}
			++i1;
		}
		if (i2 & 1) {
			--i2;
			for (int j1 = b1 + m, j2 = b2 + m + 1; j1 < j2; j1 >>= 1, j2 >>= 1) {
				if (j1 & 1) {
					mn = min(mn, t1[i2][j1]);
					mx = max(mx, t2[i2][j1]);
					++j1;
				}
				if (j2 & 1) {
					--j2;
					mn = min(mn, t1[i2][j2]);
					mx = max(mx, t2[i2][j2]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; m = n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v;
			t1[i+n][j+m] = t2[i+n][j+m] = v;
		}
	}
	build();
	cin >> q;
	while (q--) {
		cin >> cmd;
		if (cmd == 'q') {
			cin >> a1 >> b1 >> a2 >> b2;
			--a1, --a2, --b1, --b2;
			query(); cout << mx << ' ' << mn << '\n';
		} else if (cmd == 'c') {
			cin >> x >> y >> v;
			--x, --y; update();
		}
	}
	cout << flush;
}