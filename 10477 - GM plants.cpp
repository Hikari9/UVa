// SPOJ 10477 [IOPC1207] - GM plants
// Segment Tree
// #include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 100001

#define GREEN 0
#define RED 1

using namespace std;

int t, n[3], q, cmd, red[3], green[3], point[2][3], a, b;
int st[3][MX<<2][2];
bool delta[3][MX<<2];

inline void push(int st[][2], bool delta[], int p, int L, int R) {
	if (delta[p] & 1) {
		swap(st[p][GREEN], st[p][RED]);
		if (L != R) {
			int P = (p << 1);
			delta[P] ^= 1;
			delta[P+1] ^= 1;
		}
		delta[p] = 0;
	}
}

inline void pull(int st[][2], int p) {
	int P = (p << 1);
	for (int i=0; i<2; ++i)
		st[p][i] = st[P][i] + st[P+1][i];
}

void build(int st[][2], bool delta[], int p, int L, int R) {
	delta[p] = 0;
	if (L == R) {
		st[p][GREEN] = 1;
		st[p][RED] = 0;
		return;
	}
	int P = (p << 1);
	int M = (L + R) >> 1;
	build(st, delta, P, L, M);
	build(st, delta, P+1, M+1, R);
	pull(st, p);
}

void update(int st[][2], bool delta[], int p, int L, int R) {
	push(st, delta, p, L, R);
	if (R < a || L > b)
		return;
	if (a <= L && R <= b) {
		delta[p] ^= 1;
		push(st, delta, p, L, R);
		return;
	}
	int P = (p << 1);
	int M = (L + R) >> 1;
	update(st, delta, P, L, M);
	update(st, delta, P+1, M+1, R);
	pull(st, p);
}

int query(int st[][2], bool delta[], int p, int L, int R, int a, int b) {
	push(st, delta, p, L, R);
	if (R < a || L > b)
		return 0;
	if (a <= L && R <= b)
		return st[p][RED];
	int P = (p << 1);
	int M = (L + R) >> 1;
	int ans = query(st, delta, P, L, M, a, b) + query(st, delta, P+1, M+1, R, a, b);
	pull(st, p);
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d%d%d%d", &n[0], &n[1], &n[2], &q);
		for (int i=0; i<3; ++i) {
			build(st[i], delta[i], 1, 0, n[i] - 1);
		}
		while (q-- > 0) {
			scanf("%d", &cmd);
			if (cmd == 3) {
				for (int i=0; i<2; ++i)
					for (int j=0; j<3; ++j)
						scanf("%d", &point[i][j]);
				for (int i=0; i<3; ++i) {
					red[i] = query(st[i], delta[i], 1, 0, n[i] - 1, point[0][i], point[1][i]);
					green[i] = point[1][i] - point[0][i] + 1 - red[i];
					// printf("%d %d\n", red[i], green[i]);
				}
				long long ans = (long long)red[0] * red[1] * red[2] + (long long)red[0] * green[1] * green[2] + (long long)green[0] * red[1] * green[2] + (long long)green[0] * green[1] * red[2];
				// long long top = (((long long)red[0] * green[1]) + (red[1] * green[0])) * green[2];
				// long long bottom = (((long long)point[1][1] - point[0][1] + 1) * (point[1][0] - point[0][0] + 1) - ((red[0] * green[1]) + (red[1] * green[0]))) * red[2];
				printf("%lld\n", ans);
			}
			else {
				scanf("%d%d", &a, &b);
				update(st[cmd], delta[cmd], 1, 0, n[cmd] - 1);
			}
		}
	}
}
