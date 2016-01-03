#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2000001;

int t, n, m, a, b, tc;
int log2[N], st[N][22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1, l = -1; i < N; ++i) {
		if ((i & (i - 1)) == 0) l++;
		log2[i] = l;
	}
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> st[i][0];
		for (int j = 0; (2 << j) <= n; ++j) {
			for (int i = 0; i + (2 << j) <= n; ++i) {
				int k = i + (1 << j);
				st[i][j + 1] = min(st[i][j], st[k][j]);
			}
		}
		cout << "Scenario #" << ++tc << ":\n";
		while (m--) {
			cin >> a >> b; --a, --b;
			if (b < a) swap(a, b);
			int k = log2[b - a + 1];
			cout << min(st[a][k], st[b - (1 << k) + 1][k]) << '\n';
		}
	}
	cout << flush;
}