#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mirror(i) (n - i - 1)
#define R mirror(L)
#define I mirror(i)

using namespace std;
const int N = 101;

int t, n, h, m, c;
int g[N][N];

void perform(int L) {
	// cout << c << endl;
	switch(c) {
		case 1: // upside down flip
			// cout << "Upside down flip, ring " << L << endl;
			for (int i = L; i <= R; ++i)
				swap(g[L][i], g[R][i]);
			for (int i = L + 1; i < I; ++i) {
				swap(g[i][L], g[I][L]);
				swap(g[i][R], g[I][R]);
			}
			break;
		case 2: // left right flip
			// cout << "Left right flip, ring " << L << endl;
			for (int i = L; i <= R; ++i)
				swap(g[i][L], g[i][R]);
			for (int i = L + 1; i < I; ++i) {
				swap(g[L][i], g[L][I]);
				swap(g[R][i], g[R][I]);
			}
			break;
		case 3: // main diagonal
			// cout << "Diagonal flip, ring " << L << endl;
			for (int i = L; i <= R; ++i)
				swap(g[L][i], g[i][L]);
			for (int i = L + 1; i < R; ++i)
				swap(g[R][i], g[i][R]);
			break;
		case 4: // inverse diagonal
			// cout << "Inverse flip, ring " << L << endl;
			for (int i = L; i <= R; ++i)
				swap(g[L][i], g[I][R]);
			for (int i = L + 1; i < R; ++i)
				swap(g[i][L], g[R][I]);
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
			}
		}
		h = (n / 2) + (n % 2);

		for (int i = 0; i < h; ++i) {
			cin >> m;
			for (int k = 0; k < m; ++k) {
				cin >> c;
				perform(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if(j) cout << ' ';
				cout << g[i][j];
			}
			cout << '\n';
		}
	}
	cout << flush;
}