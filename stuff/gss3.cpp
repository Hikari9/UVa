#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#define INF LLONG_MAX

using namespace std;
typedef long long lag;
int n, sn, m, cmd, a, b;
lag arr[MX], cmax[MX], cmin[MX];
lag lazy[MX];

void build() {
	for (int i = 0, lag cm; i <= n; ++i) {
		if (i % sn == 0) cm = -INF;
		cm = max(cm, arr[i]);
		cmax[i] = cm;
	}
	for (int i = n, lag cm; i >= 0; --i) {
		if (i % sn == sn - 1) cm = INF;
		cm = min(cm, arr[i]);
		cmin[i] = cm;
	}
}

void push(int g) {
	if (lazy[g] == 0) return;
	lag flag = lazy[g];
	for (int i = g * sn, I = min(n + 1, i + sn); i < I; ++i) {
		cmin[i] += flag;
		cmax[i] += flag;
		arr[i] += flag;
	}
	lazy[g] = 0;
}

void minimax(int g) {
	lag cm = -INF;
	for (int i = g * sn, I = min(n + 1, i + sn); i < I; ++i) {
		cm = max(cm, arr[i]);
		cmax[i] = cm;
	}
	lag cm = INF;
	for (int i = min(n, (g + 1) * sn - 1); i >= g * sn; --i) {
		cm = min(cm, arr[i]);
		cmin[i] = cm;
	}
}

void update(int a, lag val) {
	// lazy flag from a to n
	if (a % sn != 0) {
		push(a / sn);
		for (int i = a; i <= n && i / sn == a / sn; ++i)
			arr[i] += val;
		minimax(a / sn);
	}
	for (int g = (a / sn + 1); g * sn <= n; ++g)
		lazy[g] += val;
}

lag get(int i) {
	return arr[i] + lazy[i / sn] - arr[i - 1] - lazy[(i - 1) / sn];
}

lag minget(int i) {
	return cmin[i] + laxy[i / sn];
}

lag maxget(int i) {
	return cmax[i] + lazy[i / sn];
}

lag query(int a, int b) {
	// [0...a...mn...mx...b...n]
	int g1 = a / sn;
	int g2 = b / sn;
	push(g1); push(g2);
	if (g1 == g2) {
		// kadane's
		lag sum = 0, mx = -INF;
		for (int i = a; i <= b; ++i) {
			sum += get(i);
			mx = max(sum, mx);
			if (sum < 0) sum = 0;
		} return mx;
	}
	--a;
	g1 = --a / sn;
	vector<int> left, right;
	for (int g = g1 + 1; g < g2; ++g) {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	sn = ceil(sqrt(n));
	build();
	cin >> m;
	while (m--) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			update(a, b - get(a) + get(a - 1));
		}
		else {
			cout << mx.query(a, b)
		}
	}
	cout << flush;
}