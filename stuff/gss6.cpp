#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 200001;
typedef long long lag;

struct node {
	lag pre, sum, suf, ans;
	node() {}
	ndoe(lag x): pre(x), sum(x), suf(x), ans(x) {}
	// pull
	node(const node& a, const node& b) {
		pre = max(a.pre, a.sum + b.pre);
		suf = max(a.suf + b.sum, b.suf);
		sum = a.sum + b.sum;
		ans = max(max(a.ans, b.ans), a.suf + b.pre);
	}
};

int n, m, x, y;
char cmd;
node *st[N << 2], *dummy;
lag lazy[N << 2], arr[N];

void push(int p, int L, int R) {
	if (lazy[p]) {
		lag toAdd = lazy[p] * (R - L + 1);
		st[p] -> pre += toAdd;
		st[p] -> suf += toAdd;
		st[p] -> sum += toAdd;
		st[p] -> ans += toAdd;
		if (L != R) {
			lazy[P] += lazy[p];
			lazy[P + 1] += lazy[p];
		}
		lazy[p] = 0;
	}
}

void pull(int p) {
	if (st[p]) delete st[p];
	st[p] = new node(*st[P], *st[P + 1]);
}

void build(int p = 1, int L = 0, int R = n * 2 - 1) {
	lazy[p] = 0;
	if (L == R) {
		st[p] = new node(arr[L]);
		return;
	}
	build(P, L, M); build(P + 1, M + 1, R);
	pull(p);
}

void update(int a, int b, lag x, int p = 1, int L = 0, int R = n * 2 - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p] += x;
		push(p, L, R);
		return;
	}
	update(a, b, x, P, L, M);
	update(a, b, x, P + 1, M + 1, R);
	pull(p);
}

node *query(int a, int b, int p = 1, int L = 0, int R = n * 2 - 1) {
	push(p, L, R);
	if (b < L || R < a) return NULL;
	if (a <= L && R <= b) return st[p];
	node *left = query(a, b, P, L, M);
	node *right = query(a, b, P + 1, M + 1, R);
	if (left == NULL) return right;
	if (right == NULL) return left;
	node *ans = new node(*left, *right);
	pull(p); delete left, right; return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	build();
	cin >> m;
	while (m--) {
		cin >> cmd >> x; --x;
		switch(cmd) {
			case 'I': // insert
				cin >> y;
				update(x, n * 2 - 1, y);
				update(x + 1, n * 2 - 1, -y);
				break;
			case 'D': // delete
				dummy = query(x, x);
				update(x)
		}
	}
	cout << flush;
}