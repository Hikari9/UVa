#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 100005;

int n, m, l, r, cmd, p;
int arr[N], d[N << 2][3];
int ptrans[] = {0, 0, 0, 1, 0, 2};
int pinv[] = {2, 3, 5};


void push(int p, int L, int R) {
	for (int j = 0; j < 3; ++j) {
		int& k = d[p][j];
		if (k) {
			if (L == R) {
				while (k > 0 && arr[L] % pinv[j] == 0) {
					arr[L] /= pinv[j];
					k--;
				}
			}
			else {
				d[P][j] += k;
				d[P + 1][j] += k;
			}
			k = 0;
		}
	}
}

void divide(int a, int b, int x, int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (b < L || R < a) {
		return;
	}
	if (a <= L && R <= b) {
		d[p][ptrans[x]]++;
		push(p, L, R);
		return;
	}
	divide(a, b, x, P, L, M);
	divide(a, b, x, P + 1, M + 1, R);
}

void modify(int i, int x, int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (L == R) {
		arr[i] = x;
		return;
	}
	if (i <= M) modify(i, x, P, L, M);
	else modify(i, x, P + 1, M + 1, R);
}

void finish(int p = 1, int L = 1, int R = n) {
	push(p, L, R);
	if (L == R) return;
	finish(P, L, M);
	finish(P + 1, M + 1, R);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	cin >> m;
	while (m--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> l >> r >> p;
			divide(l, r, p);
		}
		else {
			cin >> l >> p;
			modify(l, p);
		}
	}
	finish();
	for (int i = 1; i <= n; ++i)
		cout << arr[i] << (i == n ? '\n' : ' ');
	cout << flush;
}