/**
 * UVa 1052 - Bit Compressor
 * by Rico Tiongson
 * Accepted: 0.020s C++ 06/10/16
 */
#include <bits/stdc++.h>
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define forr(i, a, n) for (int i = (n) - 1; i >= a; --i)
#define pb push_back

using namespace std;
const int N = 40;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
enum {NO, UNIQUE, NOT_UNIQUE};

map<ll, map<ll, int> > dp[N];
ll l, n;
string s;
int tc, bits[1 << 16];
int count_bits(ll x) {
	return x == 0 ? 0 : bits[int(x & ((1 << 16) - 1))] + count_bits(x >> 16);
}
int count_zeroes(ll x) {
	if (!x) return 0;
	int lg = -count_bits(x);
	for (int i = 32; i > 0; i >>= 1) {
		if (x >> i) {
			lg += i;
			x >>= i;
		}
	}
	return lg + 1;
}
int solve(int i, ll ones, ll zeroes) {
	if (ones < 0 || zeroes < 0) {
		return NO;
	}
	// debug flag;
	// cout << "checking " << i << ' ' << ones << ' ' << zeroes << endl;
	if (i == s.length()) {
		return ones==0 && zeroes==0 ? UNIQUE : NO;
	}
	if (dp[i].count(ones) && dp[i][ones].count(zeroes)) {
		return dp[i][ones][zeroes];
	}
	if (s[i] == '0') {
		return dp[i][ones][zeroes] = solve(i + 1, ones, zeroes - 1);
	}
	ll def = 0;
	int ans = 0;
	forn (j, i, s.length()) {
		def = (def << 1) | (s[j] == '1');
		if (def != 2 && (j + 1 >= s.length() || s[j + 1] == '0')) {
			ans += solve(j + 1, ones - def, zeroes);
			if (def == 3)
				ans += solve(j + 1, ones - 2, zeroes); // special case
		}
		if (def > ones) break;
		if (ans >= NOT_UNIQUE) {
			return dp[i][ones][zeroes] = NOT_UNIQUE;
		}
	}
	return dp[i][ones][zeroes] = ans;
}

string outp[] = {"NO", "YES", "NOT UNIQUE"};

int main() {
	forn (i, 1, (1 << 16))
		bits[i] = bits[i >> 1] + (i & 1);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> l >> n && (n || l)) {
		cin >> s;
		forn (i, 0, s.length()) dp[i].clear();
		int ans = solve(0, n, l-n);
		cout << "Case #" << ++tc << ": " << outp[ans] << '\n';
	}
}
