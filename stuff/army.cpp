#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100001;

int	n, L[N], R[N], l, r, loss;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> loss, n || loss) {
		for (int i = 1; i <= n; ++i) {
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[n] = 0;
		while (loss--) {
			cin >> l >> r;
			int nl = L[l];
			int nr = R[r];
			if (nl) cout << nl << " ";
			else cout << "* ";
			if (nr) cout << nr << "\n";
			else cout << "*\n";
			L[nr] = nl;
			R[nl] = nr;
		}
		cout << "-\n";
	}
	cout << flush;
}