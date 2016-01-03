// RMQ Sparse Table
// SPOJ RMQSQ - Range Minimum Query
// http://www.spoj.com/problems/RMQSQ/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
#define N 100005
#define logN 17
#define INF INT_MAX

int arr[N], log2[N], st[N][logN];
int n, x, q, a, b;

void buildSparseTable() {
	for (int i = 1, l = -1; i <= n; i++) {
		if ((i & (i - 1)) == 0) l++;
		log2[i] = l;
	}
	for (int i = 0; i < n; i++)
		st[i][0] = arr[i];
	for (int j = 0; (2 << j) <= n; j++) {
		for (int i = 0; i + (2 << j) <= n; i++) {
			int a = st[i][j];
			int b = st[i + (1 << j)][j];
			st[i][j + 1] = min(a, b);
		}
	}
}

int query(int a, int b) {
	int k = log2[b - a + 1]; // 2^k <= (b - a + 1)
	return min(st[a][k], st[b - (1 << k) + 1][k]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	buildSparseTable();
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << query(a, b) << endl;
	}
	cout << flush;
}