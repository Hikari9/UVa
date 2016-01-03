// CodeForces 52C - Circular RMQ
// Segment Tree with Lazy Update
#include <iostream>
#include <sstream>
#include <climits>
#define MX 200001
#define INF LLONG_MAX

using namespace std;
typedef long long lag;

int n, q, l, r;
lag a[MX], st[MX<<2], delta[MX<<2], v;
char c[100];

void push(int p, int L, int R) {
	if (delta[p]) {
		st[p] += delta[p];
		if (L != R) {
			int P = p << 1;
			delta[P] += delta[p];
			delta[P+1] += delta[p];
		}
		delta[p] = 0;
	}
}

void pull(int p) {
	int P = p << 1;
	st[p] = min(st[P], st[P+1]);
}

void build(int p, int L, int R) {
	delta[p] = 0;
	if (L == R) {
		st[p] = a[L];
		return;
	}
	int P = p << 1;
	int M = (L + R) >> 1;
	build(P, L, M);
	build(P+1, M+1, R);
	st[p] = min(st[P], st[P+1]);	
}


lag query(int p, int L, int R) {
	push(p, L, R);
	if (L > r || R < l)
		return INF;
	if (l <= L && R <= r) {
		// cout << "\t" << L << " " << R << " " << st[p] << endl;
		return st[p];
	}
	int P = p << 1;
	int M = (L + R) >> 1;
	lag ans = min(query(P, L, M), query(P+1, M+1, R));
	pull(p);
	return ans;
}

void update(int p, int L, int R) {
	push(p, L, R);
	if (L > r || R < l)
		return;
	if (l <= L && R <= r) {
		delta[p] += v;
		push(p, L, R);
		// cout << "\t" << " " << L << " " << R << " " << st[p] << endl;
		return;
	}
	int P = p << 1;
	int M = (L + R) >> 1;
	update(P, L, M);
	update(P+1, M+1, R);
	pull(p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	build(1, 0, n-1);
	cin >> q;
	cin.ignore();
	while (q-- > 0) {
		cin.getline(c, 100);
		if (istringstream(c) >> l >> r >> v) {
			if (l <= r) {
				update(1, 0, n-1);
				// for (int i=0; i<
			}
			else {
				int t = r;
				r = n - 1;
				update(1, 0, n-1);
				r = t;
				l = 0;
				update(1, 0, n-1);
			}
		}
		else {
			if (l <= r) {
				cout << query(1, 0, n-1) << endl;
			}
			else {
				int t = r;
				r = n - 1;
				lag ans = query(1, 0, n-1);
				r = t;
				l = 0;
				ans = min(ans, query(1, 0, n-1));
				cout << ans << endl;
			}
		}
	}
}
