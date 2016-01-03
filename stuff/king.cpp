#include <iostream>
#include <cstring>

using namespace std;
const int N = 101;

int n, r, c, k, g[2][N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> r >> c >> k, n || r || c || k) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> g[0][i][j];
			}
		}
		bool changed = true;
		int kk, K;
		for (kk = 0, K = 1; changed && kk < k; ++kk, K ^= 1) {
			changed = false;
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					g[K][i][j] = g[!K][i][j];
					for (int l = 0; l < 4; ++l) {
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
							if ((g[!K][nx][ny] + 1) % n == g[!K][i][j]) {
								g[K][i][j] = g[!K][nx][ny];
								changed = true;
								break;
							}
						}
					}
				}
			}
		}
		K ^= 1;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (j) cout << ' ';
				cout << g[K][i][j];
			}
			cout << '\n';
		}
	}
	cout << flush;
}