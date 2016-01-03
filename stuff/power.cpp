#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <algorithm>
#define M ((L + R) >> 1)
#define P (p << 1)

using namespace std;
const int N = 100001;

int t, n, m, arr[N], tc;
long long st[N << 2][2], mask = (1ll << 32);
queue<long long> lazy[N << 2];

void pull(int p) {
	st[p][0] = st[P][0] + st[P + 1][0];
	st[p][1] = st[P][1] + st[P + 1][1];
}

void build(int p = 1, int L = 0, int R = n - 1) {
	st[p][0] = st[p][1] = 0;
	lazy[p] = queue<long long>();
	if (L == R) {
		st[p][0] = arr[L] * arr[L];
		st[p][1] = arr[L];
		return;
	}
	build(P, L, M); build(P + 1, M + 1, R);
	pull(p);
}

void push(int p, int L, int R) {
	while (!lazy[p].empty()) {
		long long l = lazy[p].front(); lazy[p].pop();
		if (l & mask) { // set
			l ^= mask;
			st[p][0] = (R - L + 1) * l * l;
			st[p][1] = (R - L + 1) * l;
			l ^= mask;
		}
		else { // add
			st[p][0] += 2 * l * st[p][1] + (R - L + 1) * l * l;
			st[p][1] += (R - L + 1) * l;
		}
		if (L != R) {
			if (!lazy[P].empty() && (lazy[P].back() & mask) == (l & mask)) {
				if (l & mask) lazy[P].back() = l;
				else lazy[P].back() += l;
			}
			else lazy[P].push(l);
			if (!lazy[P + 1].empty() && (lazy[P + 1].back() & mask) == (l & mask)) {
				if (l & mask) lazy[P + 1].back() = l;
				else lazy[P + 1].back() += l;
			}
		}
	}
}


void add(int a, int b, int x, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p].push(x);
		push(p, L, R); return;
	}
	add(a, b, x, P, L, M);
	add(a, b, x, P + 1, M + 1, R);
	pull(p);
}

void set(int a, int b, int x, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p].push(x | mask);
		push(p, L, R); return;
	}
	set(a, b, x, P, L, M);
	set(a, b, x, P + 1, M + 1, R);
	pull(p);
}

long long query(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return st[p][0];
	long long q = query(a, b, P, L, M) + query(a, b, P + 1, M + 1, R);
	pull(p); return q;
}

int cmd, a, b, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cout << "Case " << ++tc << ":\n";
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		while (m--) {
			cin >> cmd >> a >> b;
			--a, --b;
			if (cmd == 2)
				cout << query(a, b) << "\n";
			else if (cmd == 1) {
				cin >> x;
				add(a, b, x);
			}
			else {
				cin >> x;
				set(a, b, x);
			}
		}
	}
	cout << flush;
}