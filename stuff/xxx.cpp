#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50001;
typedef long long lag;

int n, a, b, q; char c;
lag fen[N], arr[N], x;

// arr[i] = x
void add(int i, lag x) {
	for (int j = i; j <= n; j += j & -j)
		fen[j] += x - arr[j]; // one occ if leaf
	arr[i] = x;
}

lag sum(int i) {
	lag s = 0;
	for (; i > 0; i -= i & -i)
		s += fen[i];
	return s;
}

lag sum(int a, int b) {
	if (a > b) swap(a, b);
	return sum(b) - sum(a - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		add(i, x);
	}
	cin >> q;
	while (q--) {
		cin >> c >> a >> b;
		if (c == 'Q') cout << sum(a, b) << '\n';
		else add(a, b);
	}
	cout << flush;
}