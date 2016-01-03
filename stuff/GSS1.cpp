#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
#define N 50001
#define P (p << 1)
#define M ((L + R) >> 1)

struct node {
	int prefix, suffix, sum, data;
	void assign(int x) {
		prefix = suffix = sum = data = x;
	}
	bool operator == (const node& n) const {
		return prefix == n.prefix && suffix == n.suffix && sum == n.sum && data == n.data;
	}
};

int n, q, array[N];
node tree[N << 2], inf = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

void pull(node& p, node& left, node& right) {
	if (left == inf) p = right;
	else if (right == inf) p = left;
	else {
		p.prefix = max(left.prefix, left.sum + right.prefix);
		p.suffix = max(right.suffix, left.suffix + right.sum);
		p.data = max(max(left.data, right.data), left.suffix + right.prefix);
		p.sum = left.sum + right.sum;
	}
}

void build(int p = 1, int L = 1, int R = n) {
	if (L == R) {
		tree[p].assign(array[L]);
		return;
	}
	build(P, L, M);
	build(P + 1, M + 1, R);
	pull(tree[p], tree[P], tree[P+1]);
}

void update(int i, int v, int p = 1, int L = 1, int R = n) {
	if (i < L || R < i) return;
	if (L == R) {
		tree[p].assign(array[L] = v);
		return;
	}
	update(i, v, P, L, M);
	update(i, v, P + 1, M + 1, R);
	pull(tree[p], tree[P], tree[P+1]);
}

node query(int a, int b, int p = 1, int L = 1, int R = n) {
	if (b < L || R < a) return inf;
	if (a <= L && R <= b) return tree[p];
	node left = query(a, b, P, L, M);
	node right = query(a, b, P + 1, M + 1, R);
	node q; pull(q, left, right);
	return q;
}

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#define endl '\n'
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> array[i];
	build();
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << query(a, b).data << endl;
	}
	cout << flush;
}