#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = (1 << 17);

int n, m, tree[N << 1], level[N << 1], p, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	n = (1 << n);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i + n];
		level[i + n] = 0;
	}
	for (int i = n * 2 - 1; i > 0; i -= 2) {
		level[i >> 1] = level[i] ^ 1;
		if (level[i >> 1] & 1) // OR
			tree[i >> 1] = tree[i] | tree[i ^ 1];
		else // XOR
			tree[i >> 1] = tree[i] ^ tree[i ^ 1];
	}
	while (m--) {
		cin >> p >> b;
		for (tree[p += n-1] = b; p > 0; p >>= 1) {
			if (level[p >> 1] & 1) // OR
				tree[p >> 1] = tree[p] | tree[p ^ 1];
			else // XOR
				tree[p >> 1] = tree[p] ^ tree[p ^ 1];
		}
		cout << tree[1] << '\n';
	}
	cout << flush;
}