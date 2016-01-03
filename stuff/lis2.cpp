// SPOJ LIS2 - Another Longest Increasing Subsequence Problem
// http://www.spoj.com/problems/LIS2/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define x first
#define y second

using namespace std;
const int N = 100001;
typedef pair<int, int> point;

int n;
point dummy;
set<point> s[N];

bool cmp(const point& a, const point& b) {
	return a.x < b.x && a.y < b.y;
}

bool check(set<point>& s) {
	for (set<point>::iterator it = s.begin(); it != s.end(); ++it)
		if (cmp(*it, dummy)) return true;
		else if (it->x >= dummy.x) break;
	return false;
}

int binarySearch(int L, int R) {
	while (L < R) {
		int M = (L + R) / 2;
		if (check(s[M]))
			L = M + 1;
		else
			R = M;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> dummy.x >> dummy.y;
		int id = binarySearch(0, n);
		if (id < n) {
			set<point>::iterator it = ++s[id].insert(dummy).first;
			while (it != s[id].end()) {
				if(cmp(dummy, *it))
					s[id].erase(it++);
				else it++;
			}
		}
	}
	int ans = 0;
	while (ans < n && !s[ans].empty())
		ans++;
	cout << ans << endl;
} 