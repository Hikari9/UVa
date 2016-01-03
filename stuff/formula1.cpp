#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;

int g, p, s, K, x, grand[N][N], k[N], score[N];
int winner[N], size;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> g >> p, g || p) {
		for (int i = 0; i < g; ++i) {
			for (int j = 1; j <= p; ++j) {
				cin >> x;
				grand[i][x] = j;
			}
		}
		cin >> s;
		for (int i = 1; i <= s; ++i) {
			cin >> K;
			for (int j = 1; j <= p; ++j)
				score[j] = 0;
			for (int j = 1; j <= K; ++j) {
				cin >> x;
				for (int k = 0; k < g; ++k) {
					int pilot = grand[k][j];
					score[pilot] += x;
				}
			}
			size = 0;
			winner[size++] = 1;
			for (int j = 2; j <= p; ++j) {
				if (score[j] > score[winner[0]]) {
					size = 0;
					winner[size++] = j;
				}
				else if (score[j] == score[winner[0]])
					winner[size++] = j;
			}
			for (int j = 0; j < size; ++j) {
				if (j) cout << ' ';
				cout << winner[j];
			}
			cout << '\n';
		}
	}
	cout << flush;
}