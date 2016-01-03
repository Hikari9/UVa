#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100001;

struct node {
	int pre, suf, sum, result;
	node(int pre = INT_MIN, int suf = INT_MIN, int sum = 0, int result = INT_MIN):
		pre(pre), suf(suf), sum(sum), result(result) {}
	void assign(int x) { pre = suf = sum = result = x; }
	void copy(const node& a) {
		pre = a.pre;
		suf = a.suf;
		sum = a.sum;
		result = a.result;
	}
	node& pull(const node& a, const node& b) {
		if (a.pre == INT_MIN) {
			copy(b);
		}
		else if (b.pre == INT_MIN) {
			copy(a);
		}
		else {
			sum = a.sum + b.sum;
			pre = max(a.pre, a.sum + b.pre);
			suf = max(a.suf + b.sum, b.suf);
			result = max(max(a.result, b.result), a.suf + b.pre);
		}
		return *this;
	}
};

node st[N << 1];
int arr[N], t, n, q, ax, ay, bx, by;

void build(int p = 1, int L = 0, int R = n - 1) {
	if (L == R) {
		st[p].assign(arr[L]);
		return;
	}
	build(P, L, M); build(P + 1, M + 1, R);
	st[p].pull(st[P], st[P + 1]);
}

node query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	if (b < L || R < a) return node();
	if (a <= L && R <= b) return st[p];
	node l = query(a, b, P, L, M);
	node r = query(a, b, P + 1, M + 1, R);
	return node().pull(l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		cin >> q;
		while (q--) {
			cin >> ax >> ay >> bx >> by;
			--ax, --ay, --bx, --by;
			int ans = INT_MIN;
			// intersection query
			if (bx <= ay) {
				// ax bx ay by
				ans = max(ans, query(ax, ay).suf + query(ay, by).pre - arr[ay]);
				ans = max(ans, query(ax, bx).suf + query(bx, by).pre - arr[bx]);
				ans = max(ans, query(bx, ay).result);
			}
			// complement query
			else {
				// ax ay bx by
				node left = query(ax, ay);
				node mid = query(ay + 1, bx - 1);
				node right = query(bx, by);
				ans = max(ans, left.suf + mid.sum + right.pre);
			}
			cout << ans << "\n";
		}
	}
	cout << flush;
}