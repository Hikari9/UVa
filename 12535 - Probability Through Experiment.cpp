#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long lag;

int n, r, a[40001], tc;
double d;

int main() {
	while (scanf("%d%d", &n, &r) == 2 && (n || r)) {
		for (int i=0; i<n; ++i) {
			scanf("%lf", &d);
			a[i] = round(d * 1000);
		}
		sort(a, a+n);
		for (int i=0; i<n; ++i) {
			a[i+n] = a[i] + 360000;
		}
		lag non_acute = 0;
		for (int i=0; i<n; ++i) {
			int nodes = (int)(upper_bound(a+i, a+2*n, a[i] + 180000) - (a+i) - 1);
			non_acute += ((lag)nodes * (nodes - 1) >> 1);
		}
		printf("Case %d: %lld\n", ++tc, (lag)n * (n - 1) * (n - 2) / 6 - non_acute);
	}
}
