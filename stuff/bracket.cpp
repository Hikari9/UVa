#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 1000005;

struct node {
	int length, open, close;
	node(): length(0), open(0), close(0) {}
	int leftOpen() const { return open - length / 2; }
	int leftClose() const { return close - length / 2; }
	node& pull(const node& a, const node& b) {
		int canAdd = min(a.leftOpen(), b.leftClose());
		length = a.length + b.length + canAdd * 2;
		open = a.open + b.open;
		close = a.close + b.close;
	}
} *st;

int n, m;
char seq[N];

void build(int p = 1, int L = 0, int R = n - 1) {
	// cout << "Building: " << p << " " << L << " " << R << endl;
	if (L == R) {
		st[p].length = 0;
		st[p].open = (seq[L] == '(');
		st[p].close = (seq[L] == ')');
		return;
	}
	build(P, L, M);
	build(P + 1, M + 1, R);
	st[p].pull(st[P], st[P + 1]);
}

node* query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	if (b < L || R < a) return NULL;
	if (a <= L && R <= b) return new node(st[p]);
	node *left = query(a, b, P, L, M);
	node *right = query(a, b, P + 1, M + 1, R);
	if (left == NULL) return right;
	if (right == NULL) return left;
	node *ans = new node();
	ans->pull(*left, *right);
	delete left, right;
	return ans;
}

int L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> seq;
	n = strlen(seq);
	st = new node[n << 2];
	build();
	cin >> m;
	while (m--) {
		cin >> L >> R;
		node *q = query(--L, --R);
		cout << q->length << '\n';
		delete q;
	}
	delete[] st;
	cout << flush;
}