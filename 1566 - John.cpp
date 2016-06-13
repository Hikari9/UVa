// UVa 1566 - John
// Classic Misere Nim Game
// 06/13/2016
// by Rico Tiongson
#include <bits/stdc++.h>
using namespace std;
int t, n, a[50];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			x ^= a[i];
			if (a[i] > mx) mx = a[i];
		}
		x ^= (mx <= 1);
		if (x) puts("John");
		else puts("Brother");
	}
}
