#include <bits/stdc++.h>

using namespace std;
#define M ((L + R) >> 1)

struct SegmentTree {
	int L, R, mn, mx, lazy;
	SegmentTree *left, *right;
	SegmentTree(int L, int R):
		L(L), R(R), left(0), right(0), lazy(-1), mn(INT_MAX), mx(INT_MIN) {}
	void push() {
		if (lazy != -1) {
			mn = mx = lazy;
			if (L != R) {
				if (!left)   left = new SegmentTree(L, M);
				if (!right) right = new SegmentTree(M + 1, R);
				left->lazy = right->lazy = lazy;
			}
			lazy = -1;
		}
	}
	void pull() {
		mn = min(left ? left->mn : INT_MAX, right ? right->mn : INT_MAX);
		mx = max(left ? left->mx : INT_MIN, right ? right->mx : INT_MIN);
	}
	void update(int a, int b, int x) {
		push();
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy = x;
			push();
			return;
		}
		if (!left) left = new SegmentTree(L, M);
		if (!right) right = new SegmentTree(M + 1, R);
		left->update(a, b, x);
		right->update(a, b, x);
		pull();
	}
	/*
	int query(int a, int b, bool minquery) {
		push();
		if (b < L || R < a) return minquery ? INT_MAX : INT_MIN;
		if (a <= L && R <= b)
			return minquery ? mn : mx;
		int lquery = left ? left->query(a, b, minquery) : (minquery ? INT_MAX : INT_MIN);
		int rquery = right ? right->query(a, b, minquery) : (minquery ? INT_MAX : INT_MIN);
		pull(); return (minquery ? min<int> : max<int>)(lquery, rquery);
	}
	*/
	~SegmentTree() {
		if (left) delete left;
		if (right) delete right;
	}
};

int t, n, l, r;
set<int> tree;

void traverse(SegmentTree *u) {
	if (!u) return;
	u->push();
	if (u->mn != u->mx) traverse(u->left), traverse(u->right);
	else tree.insert(u->mn);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		SegmentTree *root = new SegmentTree(1, 10000000);
		for (int i = 0; i < n; ++i) {
			cin >> l >> r;
			root->update(l, r, i);
		}
		tree.clear();
		traverse(root);
		cout << tree.size() << '\n';
		delete root;
	}
	cout << flush;
}