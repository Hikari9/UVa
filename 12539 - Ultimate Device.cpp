/**
	UVa 12539 - Ultimate Device
	by Rico Tiongson
	Submitted: October 23, 2014
	Accepted 4.165s C++
	O(n^3) DP with masking
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int PR = 95;
const int PW = 8;
const int M = 10007;

const int pr[PR] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};

const int powers[PW] = {9,6,4,4,3,3,3,3};

int get_mask(int x) {
	int mask = 0;
	for (int i=0; i<PW; ++i) {
		int c = 0;
		while (x % pr[i] == 0) {
			++c;
			x /= pr[i];
		}
		mask = mask * powers[i] + c;
	}
	int m = mask;
	return mask;
}

int modPow(int b, int e) {
	if (e == 0)
		return 1;
	int h = modPow(b, e >> 1);
	h = (h * h) % M;
	if (e & 1)
		return (h * b) % M;
	return h;
}

int evaluate(int mask) {
	int ans = 1;
	for (int i=PW-1; i>=0; --i) {
		ans = (ans * modPow(pr[i], mask % powers[i])) % M;
		mask /= powers[i];
	}
	return ans;
}

int lcm(int a, int b) {
	int mask = 0;
	int next = 1;
	for (int i=PW-1; i>=0; --i) {
		int v1 = a % powers[i];
		int v2 = b % powers[i];
		mask += next * max(v1, v2);
		next *= powers[i];
		a /= powers[i];
		b /= powers[i];
	}
	return mask;
}

int t, n, m[101], r[101], x, y, tc;
int dp[101][69985][2];
bool same[101];
pair<int, int> p[101];

int f(int i, int mask, bool has_residue) {
	has_residue &= same[i];
	if (dp[i][mask][has_residue] != -1)
		return dp[i][mask][has_residue];
	if (has_residue) {
		return dp[i][mask][1] = 
			f(i-1, lcm(mask, m[i]), true) +
			f(i-1, mask, true) % M;
	}
	return dp[i][mask][0] = 
		((r[i] * f(i-1, lcm(mask, m[i]), true)) % M +
		f(i-1, mask, false)) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	for (int i=0; i<69985; ++i)
		dp[0][i][0] = dp[0][i][1] = evaluate(i);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; ++i) {
			cin >> x;
			y = 1;
			for (int j=PW; j<PR; ++j) {
				int p = pr[j];
				if (x % p == 0) {
					x /= p;
					y *= p;
				}
			}
			p[i].first = y;
			p[i].second = x;
		}
		sort (p + 1, p + n + 1);
		for (int i=n; i>0; --i) {
			r[i] = p[i].first;
			m[i] = get_mask(p[i].second);
			same[i] = (i != n && r[i] == r[i+1]);
		}
		memset (&dp[1], -1, sizeof(dp[1]) * n);
		cout << "Case " << ++tc << ": " << f(n,0,0)-1 << endl;
	}
}
