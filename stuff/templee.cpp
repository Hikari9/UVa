#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cassert>
#include <algorithm>
#define M ((L + R) >> 1)
#define P (p << 1)

using namespace std;
const int N = 500001;

int arr[N], key[N], pos[N];

struct SegmentTree {
	int n;
	int *st, *lazy;
	SegmentTree(int n): n(n) {
		st = new int[n << 2];
		lazy = new int[n << 2];
		build(1, 0, n - 1);
	}
	~SegmentTree() { delete[] st, lazy; }
	void pull(int p) {
		st[p] = max(st[P], st[P + 1]);
	}
	void push(int p, int L, int R) {
		if (lazy[p]) {
			st[p] += lazy[p];
			if (L != R) {
				lazy[P] += lazy[p];
				lazy[P + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
	}
	void build(int p, int L, int R) {
		lazy[p] = 0;
		if (L == R) {
			st[p] = arr[key[L]];
			return;
		}
		build(P, L, M);
		build(P + 1, M + 1, R);
		pull(p);
	}
	int a, b, x;
	void update(int a, int x) {update(a, a, x);}
	void update(int a, int b, int x) {
		this->a = a;
		this->b = b;
		this->x = x;
		Update(1, 0, n - 1);
	}
	void Update(int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return;
		if (a <= L && R <= b) {
			lazy[p] += x;
			push(p, L, R);
			return;
		}
		Update(P, L, M);
		Update(P + 1, M + 1, R);
		pull(p);
	}
	int query(int a) {return query(a, a);}
	int query(int a, int b) {
		this->a = a;
		this->b = b;
		return Query(1, 0, n - 1);
	}
	int Query(int p, int L, int R) {
		push(p, L, R);
		if (b < L || R < a) return INT_MIN;
		if (a <= L && R <= b) return st[p];
		int q = max(Query(P, L, M), Query(P + 1, M + 1, R));
		pull(p); return q;
	}
	// return L such that k <= arr[L]
	int lowerBound(int k) {
		this->x = k;
		return lowerBound(1, 0, n - 1);
	}
	int lowerBound(int p, int L, int R) {
		push(p, L, R);
		// cout << '\t' << x << " " << st[p] << " " << L << " " << R << endl;
		if (x > st[p]) return R + 1;
		if (L == R) return L;
		int lb = lowerBound(P, L, M);
		if (lb > M) lb = lowerBound(P + 1, M + 1, R);
		pull(p); return lb;
	}
};

int n, q, c, x;

bool byKey(int i, int j) {
	return arr[i] < arr[j];
}

void input() {
	for (int i = 0; i < n; ++i)
		cin >> arr[i], key[i] = i;
	sort(key, key + n, byKey);
	for (int i = 0; i < n; ++i)
		pos[key[i]] = i;
}


SegmentTree *tree;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> q) {
		input();
		tree = new SegmentTree(n);
		while (q--) {
			cin >> c >> x;
			if (c == 2) {
				cout << (n - tree->lowerBound(x)) << '\n';
			}
			else if (c == 3) {
				int lb = tree->lowerBound(x);
				tree->update(lb, n - 1, -1);
			}
			else if (c == 1) {
				// add one pilgrim
				--x;
				int midpos = pos[x];
				int value = tree->query(midpos);
				int lastpos = tree->lowerBound(value + 1) - 1;
				assert(value == tree->query(lastpos));
				// midpos ... lastpos
				// swap position and last
				pos[key[midpos]] = lastpos;
				pos[key[lastpos]] = midpos;
				swap(key[midpos], key[lastpos]);
				// increment lastpos
				tree->update(lastpos, 1);
			}
		}
		delete tree;
	}
	cout << flush;
}