#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int V = 1000001;
const int N = 10001;

bitset<V> isPrime;
void sieve();
int t, n, a, b, v, q, c, st[N << 2], Z[N << 2], arr[N], tc;

void pull(int p) {
	st[p] = st[P] + st[P + 1];
}

void push(int p, int L, int R) {
	if (Z[p] != -1) {
		st[p] = Z[p] * (R - L + 1);
		if (L != R)
			Z[P] = Z[P + 1] = Z[p];
		Z[p] = -1;
	}
}

void build(int p = 1, int L = 0, int R = n - 1) {
	Z[p] = -1;
	if (L == R) {
		st[p] = arr[L];
		return;
	}
	build(P, L, M);
	build(P + 1, M + 1, R);
	pull(p);
}

void update(int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		Z[p] = v;
		push(p, L, R);
		return;
	}
	update(P, L, M); update(P + 1, M + 1, R);
	pull(p);
}

int query(int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return st[p];
	int q = query(P, L, M) + query(P + 1, M + 1, R);
	pull(p); return q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	cin >> t;
	while (t--) {
		cout << "Case " << ++tc << ":\n";
		cin >> n >> q;
		memset(arr, 0, sizeof arr);
		memset(st, 0, sizeof st);
		for (int i = 0; i < n; ++i) {
			cin >> v;
			arr[i] = isPrime[v];
		}
		build();
		while (q-- > 0) {
			cin >> c >> a >> b; --a, --b;
			if (b < a) swap(a, b);
			if (c)
				cout << query() << '\n';
			else {
				cin >> v;
				v = isPrime[v];
				update();
			}
		}
	}
	cout << flush;
}

void sieve() {
	isPrime[2] = true;
	for (int i = 3; i < V; i += 2)
		isPrime[i] = true;
	for (int i = 3; i < V; i += 2) {
		if (isPrime[i]) {
			if ((long long) i * i >= V) break;
			for (int j = i * i; j < V; j += i)
				isPrime[j] = false;
		}
	}
}