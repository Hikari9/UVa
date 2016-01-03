// SPOJ NHAY - Needle in a Haystack
// http://www.spoj.com/problems/NHAY/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define endl '\n'

using namespace std;

int *par;

void buildKMP(string& f) {
	int n = f.length();
	par = new int[n + 1];
	par[0] = -1; par[1] = 0;
	int i = 2, j = 0;
	while (i <= n) {
		if (f[i - 1] == f[j])
			par[i++] = ++j;
		else if (j > 0)
			j = par[j];
		else
			par[i++] = 0;
	}
}

void KMP(string& s, string& f) {
	// if (s.length() < f.length()) return;
	buildKMP(f);
	for (int i = 0, j = 0, n = s.length(); i + j < s.length();) {
		if (s[i + j] == f[j]) {
			if (++j == f.length()) {
				// match
				cout << i << endl;
				i += j - par[j];
				if (j > 0) j = par[j];
			}
		}
		else {
			i += j - par[j];
			if (j > 0) j = par[j];
		}
	}
	delete[] par;
}

int n,tc;
string needle, haystack;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		if (tc++) cout << endl;
		cin >> needle >> haystack;
		KMP(haystack, needle);
	}
	cout << flush;
}