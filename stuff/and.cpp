#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
const int N = 100001;

int st[N][20], log2[N], t, n, k;

void build() {
	for (int j = 0; (2 << j) <= n; ++j) {
		for (int i = 0; i + (2 << j) <= n; ++i) {
			int k = i + (1 << j);
			st[i][j + 1] = (st[i][j] & st[k][j]);
		}
	}
}

int query(int a, int b) {
	if (a < 0) return query(a + n, n - 1) & query(0, b);
	if (b >= n) return query(0, b - n) & query(a, n - 1);
	int k = log2[b - a + 1];
	// cout << "Querying: " << a << " " << b << " " << k << " " << (b - (1 << k) + 1) << "(" << st[a][k] << "," << st[b-(1<<k)+1][k] << ") = " << (st[a][k] & st[b - (1 << k) + 1][k]) << endl;
	return st[a][k] & st[b - (1 << k) + 1][k];
}

int main() {
	for (int i = 1, l = -1; i < N; ++i)
		log2[i] = (l += ((i & (i - 1)) == 0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> st[i][0];
		if (k > n / 2) {
			int everything = INT_MAX;
			for (int i = 0; i < n; ++i)
				everything &= st[i][0];
			for (int i = 0; i < n; ++i) {
				if (i) cout << ' ';
				cout << everything;
			}
			cout << '\n';
		}
		else {
			build();
			for (int i = 0; i < n; ++i) {
				int a = i - k, b = i + k;
				if (i) cout << ' ';
				cout << query(a, b);
			}
			cout << '\n';
		}
	}
	cout << flush;
}