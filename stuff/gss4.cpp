// SPOJ GSS4 - Can you answer these queries IV
// http://www.spoj.com/problems/GSS4/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long lag;
const int N = 100001;

int f[N];
int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }

lag arr[N], fenwick[N + 1];
int cmd, a, b, n, m, tc;
bool changed[N << 2];

void add(int i, lag x) {
	for (++i; i <= n; i += i & -i)
		fenwick[i] += x;
}

lag sum(int i) {
	lag s = 0;
	for (++i; i > 0; i -= i & -i)
		s += fenwick[i];
	return s;
}

lag query(int a, int b) {
	return sum(b) - sum(a - 1);
}

lag update(int a, int b) {
	for (a = find(a); a <= b; a = find(a + 1)) {
		lag x = query(a, a);
		lag sqrtx = sqrt(x);
		add(a, -x + sqrtx);
		if (sqrtx == 1) {
			f[find(a)] = find(a + 1);
		}
	}
}
void build() {
	for (int i = 0; i <= n; ++i) {
		fenwick[i] = 0;
		f[i] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == 1)
			f[find(i)] = find(i + 1);
		add(i, arr[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		if (tc) cout << "\n";
		cout << "Case #" << ++tc << ":\n";
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		cin >> m;
		while (m--) {
			cin >> cmd >> a >> b; --a, --b;
			if (a > b) swap(a, b);
			if (cmd) 
				cout << query(a, b) << '\n';
			else
				update(a, b);
		}
	}
	cout << flush;
}