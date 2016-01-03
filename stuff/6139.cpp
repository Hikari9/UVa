#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100001;

int st[N << 1], a, b, n, m;
char cmd;

void update(int i, int x) {
	if (x < 0) x = -1;
	else if (x > 0) x = 1;
	for (st[i += n] = x; i > 0; i >>= 1) 
		st[i >> 1] = st[i] * st[i ^ 1];
}

int query(int a, int b) {
	int ans = 1;
	for (a += n, b += n + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1) ans *= st[a++];
		if (b & 1) ans *= st[--b];
	}
	return ans;
}

char sign(int a, int b) {
	int ans = query(a, b);
	return ans == 0 ? '0' : (ans == 1 ? '+' : '-');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			cin >> st[i + n];
			if (st[i + n] > 0) st[i + n] = 1;
			else if (st[i + n] < 0) st[i + n] = -1;
		}
		for (int i = n * 2 - 1; i > 0; i -= 2)
			st[i >> 1] = st[i] * st[i ^ 1];
		while (m--) {
			cin >> cmd >> a >> b;
			if (cmd == 'C')
				update(--a, b);
			else
				cout << sign(--a, --b);
		}
		cout << '\n';
	}
	cout << flush;
}