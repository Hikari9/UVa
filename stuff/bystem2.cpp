#include <iostream>
#include <cstring>

using namespace std;

int t, h, w;
int dp[101][101], a[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i = 0; i < h; ++i) 
			for (int j = 0; j < w; ++j)
				cin >> a[i][j];
		memcpy(dp, a, sizeof a);
		for (int i = 1; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
				for (int k = -1; k < 2; k += 2) {
					if (j + k >= 0 && j + k < w) {
						dp[i][j] = max(dp[i - 1][j + k] + a[i][j], dp[i][j]);
					}
				}
			}
		}
		int mx = 0;
		for (int j = 0; j < w; ++j) {
			mx = max(mx, dp[h - 1][j]);
		}
		cout << mx << endl;
	}
}