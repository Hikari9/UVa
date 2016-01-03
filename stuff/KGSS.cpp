#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
const int N = 100005;
typedef long long lag;

int n, x, q, a, b, arr[N];
char cmd;
lag tree[N << 1][2], temp[4];

void minimize(lag res[], lag a[], lag b[]) {
	temp[0] = a[0];
	temp[1] = a[1];
	temp[2] = b[0];
	temp[3] = b[1];
	sort(temp, temp + 4);
	res[0] = temp[3];
	res[1] = temp[2];
}

void build() {
	for (int i = 0; i < n; ++i) {
		tree[i + n][0] = arr[i];
		tree[i + n][1] = INT_MIN;
	}
	for (int i = n * 2 - 1; i > 0; --i)
		minimize(tree[i >> 1], tree[i], tree[i ^ 1]);
}

int query(int a, int b) {
	lag ans[2] = {INT_MIN, INT_MIN};
	for (a += n, b += n + 1; a < b; a >>= 1, b >>= 1) {
		if (a & 1)
			minimize(ans, ans, tree[a++]);
		if (b & 1)
			minimize(ans, ans, tree[--b]);
	}
	return ans[0] + ans[1];
}

void update(int i, int x) {
	tree[i += n][0] = x;
	tree[i][1] = INT_MIN;
	for (; i > 0; i >>= 1)
		minimize(tree[i >> 1], tree[i], tree[i ^ 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	build();
	cin >> q;
	while (q--) {
		cin >> cmd >> a >> b;
		if (cmd == 'Q')
			cout << query(--a, --b) << '\n';
		else {
			--a;
			arr[a] = b;
			update(a, b);
		}
	}
	cout << flush;
}