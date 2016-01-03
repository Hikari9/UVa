#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int t, n, h;
vector<int> ham[17][17];
char buf[20];

int length(int x) {
	int c = 0;
	while (x) {
		c++;
		x >>= 1;
	}
	return c;
}

int bits(int x) {
	int c = 0;
	while (x) {
		c += (x & 1);
		x >>= 1;
	}
	return c;
}

char* binary(int x) {
	for (int i = 0; i < n; ++i) {
		buf[n - i - 1] = '0' + (x & 1);
		x >>= 1;
	}
	buf[n] = '\0';
	return buf;
}

int main() {
	for (int i = 0, I = (1 << 16); i <= I; ++i) {
		ham[length(i)][bits(i)].push_back(i);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &h);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0, J = ham[i][h].size(); j < J; ++j) {
				printf("%s\n", binary(ham[i][h][j]));
			}
		}
		if (t) printf("\n");
	}
}
