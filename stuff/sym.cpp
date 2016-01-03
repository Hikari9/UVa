#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, tc;
long long m[5000][5000];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("\nN = %d", &n);
		bool sym = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%lld", &m[i][j]);
				if (m[i][j] < 0)
					sym = false;
			}
		}
		for (int i = 0; sym && i < n; ++i) {
			for (int j = 0; sym && j < n; ++j) {
				if (m[i][j] != m[n - i - 1][n - j - 1]) {
					sym = false;
				}
			}
		}
		printf("Test #%d: %symmetric.\n", ++tc, sym ? "S" : "Non-s");
	}
}