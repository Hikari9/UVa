// CodeForces 346B - Lucky Common Subsequence
// http://codeforces.com/contest/346/problem/B

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define SAME -2
#define LEFT -3
#define RIGHT -4

using namespace std;
const int N = 105;

char a[N], b[N], v[N];
int par[N], alen, blen, vlen, dp[N][N][N], prev[N][N][N];

inline void maxify(int i, int j, int k, int L, int SIGN) {
	if (dp[i][j][k] < L) {
		dp[i][j][k] = L;
		prev[i][j][k] = SIGN;
	}
}

int lcsBottomUp() {
	for (int i = alen - 1; i >= 0; --i) {
		for (int j = blen - 1; j >= 0; --j) {
			for (int k = vlen - 1; k >= 0; --k) {
				maxify(i, j, k, dp[i+1][j][k], LEFT);
				maxify(i, j, k, dp[i][j+1][k], RIGHT);
				if (a[i] == b[j]) {
					int p = k - 1;
					while (p >= 0 && a[i] != v[p+1])
						p = par[p];
					++p;
					if (a[i] != v[p])
						maxify(i, j, k, dp[i+1][j+1][0] + 1, 0);
					else if (p + 1 < vlen)
						maxify(i, j, k, dp[i+1][j+1][p+1] + 1, p+1);					
				}
			}
		}
	}
	return dp[0][0][0];
}

void build() {
	par[0] = -1;
	alen = strlen(a);
	blen = strlen(b);
	vlen = strlen(v);
	for (int i = 0; i < vlen; ++i) {
		int p = i;
		do {p = par[p];}
		while (p != -1 && v[p + 1] != v[i + 1]);
		if (v[p + 1] == v[i + 1]) {
			par[i + 1] = p + 1;
		}
		else {
			par[i + 1] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> v;
	build();
	if (lcsBottomUp() == 0) {
		cout << "0" << endl;
		return 0;
	}
	cerr << dp[0][0][0] << endl;
	int i = 0, j = 0, k = 0;
	while (i < alen && j < blen) {
		int ni, nj, nk;
		switch(prev[i][j][k]) {
			case LEFT:
				ni = i + 1;
				nj = j;
				nk = k;
				break;
			case RIGHT:
				ni = i;
				nj = j + 1;
				nk = k;
				break;
			default:
				ni = i + 1;
				nj = j + 1;
				nk = prev[i][j][k];
				break;
		}
		int value = (ni < alen && nj < blen ? dp[ni][nj][nk] : 0);
		if (value != dp[i][j][k]) {
			cout << a[i];
			// cout << i << " " << j << " " << k << "=>" << ni << " " << nj << " " << nk << endl;
		}
		i = ni, j = nj, k = nk;
	}
	cout << endl;
}