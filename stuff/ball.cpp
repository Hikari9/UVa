#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define M ((L + R) >> 1)

struct tree {
	int L, R, data, lazy;
	tree *left, *right;
	tree(int L, int R): L(L), R(R), data(0), lazy(0), left(NULL), right(NULL) {}
	void push() {
		if (lazy) {
			data += lazy;
			if (L != R) {
				if (!left) left = new tree(L, M);
				if (!right) right = new tree(M + 1, R);
				left->lazy += lazy;
				right->lazy += lazy;
			}
			lazy = 0;
		}
	}
	void pull() {
		data = max(left ? left->data : 0, right ? right->data : 0);
	}
	void update(int a, int b, int x) {
		push();
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy += x;
			push(); return;
		}
		if (!left) left = new tree(L, M);
		if (!right) right = new tree(M + 1, R);
		left->update(a, b, x);
		right->update(a, b, x);
		pull();
	}
	int query(int a, int b) {
		push();
		if (b < L || R < a) return 0;
		if (a <= L && R <= b) return data;
		int q = max(left ? left->query(a, b) : 0, right ? right->query(a, b) : 0);
		pull(); return q;
	}
	~tree() {
		if (left) delete left;
		if (right) delete right;
	}
};

int t, n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		tree *root = new tree(0, 10000000);
		while (n--) {
			cin >> a >> b;
			root->update(a, b, 1);
		}
		cout << root->query(root->L, root->R) << '\n';
		delete root;
	}
	cout << flush;
}