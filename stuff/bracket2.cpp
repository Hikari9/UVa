#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M ((L + R) >> 1)
#define P (p << 1)

using namespace std;
const int N = 350001;

long long st[N << 2], lazy[N << 2];
int n, t, stack[N];
char bra[N + 1];

void push(int p, int L, int R) {
	if (lazy[p]) {
		st[p] = lazy[p] * (R - L + 1);
		if (L != R)
			lazy[P] = lazy[P + 1] = lazy[p];
		lazy[p] = 0;
	}
}

void pull(int p) {
	st[p] = st[P] + st[P + 1];
}

void cover(int a, int b, int c, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		lazy[p] = c;
		push(p, L, R); return;
	}
	cover(a, b, c, P, L, M);
	cover(a, b, c, P + 1, M + 1, R);
	pull(p);
}

long long sum(int a, int b, int p = 1, int L = 0, int R = n - 1) {
	push(p, L, R);
	if (b < L || R < a) return 0;
	if (a <= L && R <= b) return st[p];
	long long s = sum(a, b, P, L, M) + sum(a, b, P + 1, M + 1, R);
	pull(p); return s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> bra;
		n = strlen(bra);
		int top = 0, maxdep = 0, ptr = 0;
		long long area = 0, sums[2] = {0, 0};
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);
		for (int i = 0; i < n; ++i) {
			if (bra[i] == '(')
				stack[top++] = i;
			else {
				maxdep = max(maxdep, top);
				int L = stack[--top];
				int height = maxdep - top;
				cout << "Covering: " << L + 1 << " " << i << " height=" << height << endl;
				cout << (long long) (i - L) * height - sum(L + 1, i) << endl;
				sums[ptr ^= 1] += (long long) (i - L) * height - sum(L + 1, i);
				cover(L + 1, i, height);
				if (top == 0) {
					area += sums[ptr];
					odd = even = maxdep = 0;
				}
			}
		}
		cout << area << '\n';
	}
	cout << flush;
}