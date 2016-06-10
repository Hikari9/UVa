// UVa 11743 - Credit Check
// by Rico Tiongson
// 06/10/16
#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;
int f(int x) {
	int a = x/10%10*2;
	int b = x/1000%10*2;
	return a%10 + a/10%10 + b%10 + b/10%10;
}
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int un = a%10 + a/100%10 + b%10 + b/100%10 + c%10 + c/100%10 + d%10 + d/100%10;
		int db = f(a) + f(b) + f(c) + f(d);
		printf((un + db) % 10 == 0 ? "Valid\n" : "Invalid\n");
	}
}
