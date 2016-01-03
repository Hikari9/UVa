// CodeForces 295A - Greg and Array
// http://codeforces.com/problemset/problem/295/A

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define root 1, 0, n - 1
#define M ((L + R) >> 1)
#define P (p << 1)

using namespace std;
typedef long long lag;
const int N = 100001;

struct Fenwick {
	lag *tree;
	int size;
	Fenwick(int size): size(size) {
		tree = new lag[size + 1];
		memset(tree, 0, sizeof(lag) * (size + 1));
	}
	void add(int i, lag x) {
		for (; i <= size; i += i & -i)
			tree[i] += x;
	}
	void add(int a, int b, lag x) {
		add(a, x); add(b + 1, -x);
	}
	lag get(int i) {
		lag res = 0;
		for (; i > 0; i -= i & -i)
			res += tree[i];
		return res;
	}
} *actual, *query;

int n, m, k, L[N], R[N], a, b;
lag D[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	actual = new Fenwick(n);
	query = new Fenwick(m);
	for (int i = 1; i <= n; ++i) {
		cin >> D[i];
		actual->add(i, D[i] - D[i - 1]);
	}
	for (int i = 1; i <= m; ++i)
		cin >> L[i] >> R[i] >> D[i];
	while (k--) {
		cin >> a >> b;
		query->add(a, b, 1);
	}
	for (int i = 1; i <= m; ++i) {
		actual->add(L[i], R[i], D[i] * query->get(i));
	}
	for (int i = 1; i <= n; ++i)
		cout << actual->get(i) << (i == n ? '\n' : ' ');
	cout << flush;
}