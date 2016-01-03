// UVa 736 - Lost In Space
// C++11 0.009s (rank 1)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 51;

int t, n;
char s[N][N], a[N];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const char *dir[] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

vector<int> pos[128];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		gets(s[0]);
		for (int i = 0; i < n; ++i)
			gets(s[i]);
		for (int i = 0; i < 128; ++i)
			pos[i].clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[i][j] != ' ') {
					pos[s[i][j]].push_back((i << 6) | j);
				}
			}
		}
		while (gets(a) && *a) {
			printf("\n%s\n", a);;
			int len = strlen(a);
			bool processed = false;
			for (auto start : pos[a[0]]) {
				int x = start >> 6;
				int y = start & ((1 << 6) - 1);
				for (int k = 0; k < 8; ++k) {
					int lx = x + dx[k] * (len - 1);
					int ly = y + dy[k] * (len - 1);
					if (lx >= 0 && ly >= 0 && lx < n && ly < n) {
						bool ok = true;
						int i = 1;
						for (int j = 1; i < len; ++i, ++j) {
							int nx = x + dx[k] * j;
							int ny = y + dy[k] * j;
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
								ok = false;
								break;
							}
							if (s[nx][ny] == ' ') {
								--i;
								continue;
							}
							if (a[i] != s[nx][ny]) {
								ok = false;
								break;
							}
						}
						if (ok && i >= len) {
							printf("(%d,%d) - %s\n", x + 1, y + 1, dir[k]);
							processed = true;
						}
					}
				}
			}
			if (!processed) printf("not found\n");
		}
		if (t) printf("\n");
	}
}