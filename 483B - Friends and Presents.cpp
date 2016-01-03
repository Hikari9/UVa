// CodeForces 483B - Friends and Presents
// Binary Search + Math
#include <iostream>
#include <limits>
using namespace std;
typedef unsigned long long lag;

int cnt1, cnt2, x, y;
lag L, R;

bool valid(lag v) {
	lag div = v / (x * y);
	lag mod = v % (x * y);
	lag c1 = div*(x-1) + mod/y;
	lag c2 = div*(y-1) + mod/x;
	lag free = x*y - x - y + 1;
	lag F = div*free + (mod + mod/(x * y) - mod/x - mod/y);
	if (c1 + F < cnt1 || c2 + F < cnt2) return false;
	lag p1 = (cnt1 < c1 ? 0 : cnt1 - c1);
	lag p2 = (cnt2 < c2 ? 0 : cnt2 - c2);
	if (p1 + p2 > F) return false;
	return true;
}

int main() {
	cin >> cnt1 >> cnt2 >> x >> y;
	L = 0;
	R = numeric_limits<lag>::max();
	while (L < R) {
		lag v = (L + R) >> 1;
		if (valid(v))
			R = v;
		else
			L = v + 1;
	}
	// cout << boolalpha << valid(5) << endl;
	cout << L << endl;
}
