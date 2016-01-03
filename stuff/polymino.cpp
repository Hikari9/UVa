#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, tc, gc;
char t[12][12], sub[12][12], sub2[12][12];
char g[12][12];
int mx, my, nx, ny;

bool possible() {
	mx = my = m;
	nx = ny = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == '*') {
				mx = min(mx, i);
				my = min(my, j);
				nx = max(nx, i);
				ny = max(ny, j);
			}
		}
	}
	for (int ai = 0; ai < n - nx + mx; ++ai) {
		for (int aj = 0; aj < n - ny + my; ++aj) {
			// check if it fits
			memset(sub, '.', sizeof sub);
			for (int i = 0; i <= nx - mx; ++i) {
				for (int j = 0; j <= nx - mx; ++j) {
					sub[ai + i][aj + j] = g[i + mx][j + my];
				}
			}
			for (int bi = 0; bi < n - nx + mx; ++bi) {
				for (int bj = 0; bj < n - ny + my; ++bj) {
					memcpy(sub2, sub, sizeof sub);
					bool cover = true;
					for (int i = 0; cover && i <= nx - mx; ++i) {
						for (int j = 0; cover && j <= nx - mx; ++j) {
							if (g[i + mx][j + my] == '*' && sub2[bi + i][bj + j] == '*') {
								// can't cover
								cover = false;
							}
							else if (g[i + mx][j + my] == '*')
								sub2[bi + i][bj + j] = '*';
						}
					}
					if (cover) {
					}
				}
			}
			next:;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		memset(t, '.', sizeof t);
		memset(g,  '.', sizeof g);
		tc = 0;
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
			t[i][strlen(t[i])] = '.';
			for (int j = 0; j < n; ++j)
				tc += (t[i][j] == '*');
		}
		memset(g, 0, sizeof g);
		for (int i = 0; i < m; ++i) {
			cin >> g[i];
			g[i][strlen(g[i])] = '.';
			for (int j = 0; j < m; ++j)
				gc += (g[i][j] == '*');
		}
		cout << possible() << '\n';
	
	}

	cout << flush;
}