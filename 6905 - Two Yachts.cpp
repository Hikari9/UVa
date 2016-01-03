// Live Archive 6905 - Two Yachts
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
const int N = 10005;
struct boat {
	int L, R, cost;
	boat() {}
	boat(int x): L(x) {}
	bool operator < (const boat& b) const {
		return L < b.L;
	}
};

int t, n;
boat b[N];
map<int, long long> dp[N];

int bound(int pos) {
	return lower_bound(b, b + n, boat(pos)) - b;
}
long long solve(int i, int once) {
	if (i == n) return 0;
	if (once < b[i].L) once = b[i].L;
	if (dp[i].count(once)) return dp[i][once];
	// try adding this boat
	long long ignore = solve(i + 1, once);
	long long count = b[i].cost + solve(max(i + 1, min(bound(b[i].R + 1), bound(once))), max(once, b[i].R + 1));
	// printf("(%d, %d) once=%d: ignore=%lld count=%lld\n", b[i].L, b[i].R, once, ignore, count);
	return dp[i][once] = max(ignore, count);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &b[i].L, &b[i].R, &b[i].cost);
			dp[i].clear();
		}
		sort(b, b + n);
		printf("%lld\n", solve(0, b[0].L));
	}	
}
