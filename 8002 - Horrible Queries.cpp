// Segment Tree
#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 100001

using namespace std;
typedef long long lag;

int t, n, m, cmd, l, r, v;
lag st[MX<<2], delta[MX<<2];

void push(int p, int L, int R) {
	if (delta[p] != 0) {
		st[p] += (R - L + 1) * (delta[p]);
		if (L != R) {
			int P = (p << 1);
			delta[P] += delta[p];
			delta[P+1] += delta[p];
		}
		delta[p] = 0;
	}
}

void pull(int p) {
	int P = (p << 1);
	st[p] = st[P] + st[P+1];
}

void update(int p, int L, int R) {
	push(p, L, R);
	if (L > r || R < l)
		return;
	if (l <= L && R <= r) {
		delta[p] += v;
		push(p, L, R);
		return;
	}
	int P = (p << 1);
	int M = (L + R) >> 1;
	update(P, L, M);
	update(P+1, M+1, R);
	pull(p);
}

lag query(int p, int L, int R) {
	push(p, L, R);
	if (L > r || R < l)
		return 0;
	if (l <= L && R <= r)
		return st[p];
	int P = (p << 1);
	int M = (L + R) >> 1;
	lag ans = query(P, L, M) + query(P+1, M+1, R);
	pull(p);
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d%d", &n, &m);
		memset(st, 0, sizeof(lag) * (n << 2));
		memset(delta, 0, sizeof(lag) * (n << 2));
		while (m-- > 0) {
			scanf("%d%d%d", &cmd, &l, &r);
			--l, --r;
			if (cmd == 0) {
				scanf("%d", &v);
				update(1, 0, n-1);
			}
			else {
				printf("%lld\n", query(1, 0, n-1));
			}
		}
	}
}
