// #include <iostream>
#include <cstdio>
#include <cstring>
#define MX 100001

using namespace std;

int n, q, cmd, a, b;
int st[MX<<2][3], delta[MX<<2], temp[3];

inline void push(int p, int L, int R) {
	int d = delta[p];
	if (d) {
		for (int i=0; i<3; ++i)
			temp[i] = st[p][i];
		for (int i=0, ptr=i+d; i<3; ++i, ++ptr) {
			if (ptr == 3) ptr = 0;
			st[p][i] = temp[ptr];
		}
		if (L != R) {
			int P = (p << 1);
			delta[P] += d;
			delta[P+1] += d;
			if (delta[P] >= 3) delta[P] -= 3;
			if (delta[P+1] >= 3) delta[P+1] -= 3;
		}
		delta[p] = 0;
	}
}

inline void pull(int p) {
	int P = (p << 1);
	for (int i=0; i<3; ++i)
		st[p][i] = st[P][i] + st[P+1][i];
}

void build(int p, int L, int R) {
	delta[p] = 0;
	if (L == R) {
		st[p][0] = 1;
		st[p][1] = 0;
		st[p][2] = 0;
		return;
	}
	int P = (p << 1);
	int M = (L + R) >> 1;
	build(P, L, M);
	build(P+1, M+1, R);
	pull(p);
}

void update(int p, int L, int R) {
	if (L > b || R < a) {
		push(p, L, R);
		return;
	}
	if (a <= L && R <= b) {
		if (++delta[p] == 3) delta[p] = 0;
		push(p, L, R);
		return;
	}
	push(p, L, R);
	int P = (p << 1);
	int M = (L + R) >> 1;
	update(P, L, M);
	update(P+1, M+1, R);
	pull(p);
}

int query(int p, int L, int R) {
	push(p, L, R);
	if (L > b || R < a)
		return 0;
	if (a <= L && R <= b)
		return st[p][0];
	int P = (p << 1);
	int M = (L + R) >> 1;
	int ans = query(P, L, M) + query(P+1, M+1, R);
	pull(p);
	return ans;
}

int main() {
	scanf("%d %d", &n, &q);
	build(1, 0, n-1);
	while (q-- > 0) {
		scanf("%d %d %d", &cmd, &a, &b);
		if (cmd == 0)
			update(1, 0, n-1);
		else
			printf("%d\n", query(1, 0, n-1));
	}
	
}
