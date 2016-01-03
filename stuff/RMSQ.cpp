// SPOJ GSS3 - Can you answer these queries III
// http://www.spoj.com/problems/GSS3/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define INF INT_MAX

using namespace std;
const int N = 50001;
int array[N];

struct SegmentTree {
	int L, R;
	int prefix, suffix, sum, data;
	SegmentTree *left, *right;
	void pull() {
		sum = left->sum + right->sum;
		prefix = max(left->prefix, left->sum + right->prefix);
		suffix = max(right->suffix, right->sum + left->suffix);
		data = max(max(left->data, right->data), left->suffix + right->prefix);
	}
	void copy(SegmentTree *node) {
		prefix = node->prefix;
		suffix = node->suffix;
		sum = node->sum;
		data = node->data;
	}
	SegmentTree(SegmentTree *node) { copy(node); }
	SegmentTree(SegmentTree *a, SegmentTree *b) {
		left = a; right = b;
		if (a == NULL) copy(b);
		else if (b == NULL) copy(a);
		else pull();
	}
	SegmentTree(int L, int R): L(L), R(R) {
		if (L == R) {
			left = right = NULL;
			prefix = data = suffix = sum = array[L];;
			return;
		}
		int M = (L + R) >> 1;
		left = new SegmentTree(L, M);
		right = new SegmentTree(M + 1, R);
		pull();
	}
	void update(int x, int value) {
		if (x < L || R < x) return;
		if (L == R) {
			array[L] = value;
			prefix = suffix = data = sum = value;
			return;
		}
		left->update(x, value);
		right->update(x, value);
		pull();
	}
	SegmentTree *query(int a, int b) {
		if (b < L || R < a) return NULL;
		if (a <= L && R <= b) return new SegmentTree(this);
		SegmentTree *l = left->query(a, b);
		SegmentTree *r = right->query(a, b);
		SegmentTree *q = new SegmentTree(l, r);
		delete l, r;
		return q;
	}
};

int n, q, cmd, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> array[i];
	SegmentTree tree(1, n);
	cin >> q;
	while (q--) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			tree.update(a, b);
		}
		else {
			cout << (*tree.query(a, b)).data << endl;
		}
	}
	cout << flush;
}