#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int t, n, m, tc;
char g[105][105];

int run() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == '.')
				continue;
			else if (g[i][j] != '<')
				break;
			// try all three directions
			bool end = true;
			for (int k = j + 1; k < m && end; ++k) {
				if (g[i][k] != '.') {
					g[i][j] = '>';
					end = false;
				}
			}
			for (int k = i - 1; k >= 0 && end; --k) {
				if (g[k][j] != '.') {
					g[i][j] = '^';
					end = false;
				}
			}
			for (int k = i + 1; k < n && end; ++k) {
				if (g[k][j] != '.') {
					g[i][j] = 'v';
					end = false;
				}
			}
			if (end) return -1;
			ans++;
			break;
		}
		for (int j = m - 1; j >= 0; --j) {
			if (g[i][j] == '.')
				continue;
			else if (g[i][j] != '>')
				break;
			// try all three directions
			bool end = true;
			for (int k = j - 1; k >= 0 && end; --k) {
				if (g[i][k] != '.') {
					g[i][j] = '<';
					end = false;
				}
			}
			for (int k = i - 1; k >= 0 && end; --k) {
				if (g[k][j] != '.') {
					g[i][j] = '^';
					end = false;
				}
			}
			for (int k = i + 1; k < n && end; ++k) {
				if (g[k][j] != '.') {
					g[i][j] = 'v';
					end = false;
				}
			}
			if (end) return -1;
			ans++;
			break;
		}
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (g[i][j] == '.') continue;
			if (g[i][j] != '^') break;
			bool end = true;
			for (int k = i + 1; k < n && end; ++k) {
				if (g[k][j] != '.') {
					g[i][j] = 'v';
					end = false;
				}
			}
			for (int k = j - 1; k >= 0 && end; --k) {
				if (g[i][k] != '.') {
					g[i][j] = '<';
					end = false;
				}
			}
			for (int k = j + 1; k < m && end; ++k) {
				if (g[i][k] != '.') {
					g[i][j] = '>';
					end = false;
				}
			}
			if (end) return -1;
			ans++;
			break;
		}
		for (int i = n - 1; i >= 0; --i) {
			if (g[i][j] == '.') continue;
			if (g[i][j] != 'v') break;
			bool end = true;
			for (int k = i - 1; k >= 0 && end; --k) {
				if (g[k][j] != '.') {
					g[i][j] = '^';
					end = false;
				}
			}
			for (int k = j - 1; k >= 0 && end; --k) {
				if (g[i][k] != '.') {
					g[i][j] = '<';
					end = false;
				}
			}
			for (int k = j + 1; k < m && end; ++k) {
				if (g[i][k] != '.') {
					g[i][j] = '>';
					end = false;
				}
			}
			if (end) return -1;
			ans++;
			break;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> g[i];
		cout << "Case #" << ++tc << ": ";
		int ans = run();
		if (ans == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
		//for (int i = 0; i < n; ++i)
		//	cout << g[i] << endl;
	}
	cout << flush;
}