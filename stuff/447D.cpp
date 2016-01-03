#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 1001;
const int K = 1000001;

long long n, m, k, p, x, row[N], col[N];
long long dp[2][K], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> x;
			row[i] += x;
			col[j] += x;
		}
	}
	make_heap(row, row + n);
	make_heap(col, col + m);
	for (int i = 1; i <= k; ++i) {
		dp[0][i] = dp[0][i - 1] + row[0];
		dp[1][i] = dp[1][i - 1] + col[0];
		pop_heap(row, row + n);
		pop_heap(col, col + m);
		row[n - 1] -= m * p;
		col[m - 1] -= n * p;
		push_heap(row, row + n);
		push_heap(col, col + m);
	}
	ans = LLONG_MIN;
	for (int i = 0; i <= k; ++i) {
		ans = max(ans, dp[0][i] + dp[1][k-i] - 1LL * i * (k - i) * p);
	}
	cout << ans << endl;
}