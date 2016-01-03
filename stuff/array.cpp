#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 100001;

int n, sn, m;
struct query {
	int L, R, id;
	bool operator < (const query& Q) const {
		int a = L / sn;
		int b = Q.L / sn;
		if (a == b) return R < Q.R;
		return a < b;
	}
} Q[N];

int occ[N], ans[N], arr[N];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> Q[i].L >> Q[i].R;
		Q[i].id = i;
	}
	sn = ceil(sqrt(n));
	sort(Q, Q + m);
	int l = 0, r = -1, c = 0;

	for (int i = 0; i < m; ++i) {
		int L = Q[i].L - 1, R = Q[i].R - 1;
		while (r < R) {
			r++;
			if (arr[r] <= n) {
				if (occ[arr[r]] == arr[r])
					c--;
				if (++occ[arr[r]] == arr[r])
					c++;
			}
		}
		while (l > L) {
			l--;
			if (arr[l] <= n) {
				if (occ[arr[l]] == arr[l])
					c--;
				if (++occ[arr[l]] == arr[l])
					c++;
			}
		}
		while (l < L) {
			if (arr[l] <= n) {
				if (occ[arr[l]] == arr[l])
					c--;
				if (--occ[arr[l]] == arr[l])
					c++;
			}
			l++;
		}
		while (r > R) {
			if (arr[r] <= n) {
				if (occ[arr[r]] == arr[r])
					c--;
				if (--occ[arr[r]] == arr[r])
					c++;
			}
			r--;
		}
		ans[Q[i].id] = c;
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << "\n";
	cout << flush;
}