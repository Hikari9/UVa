#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 50002;

char s[N];
int n, sa[N], pos[N], tmp[N], lcp[N], gap;

inline bool cmp(int i, int j) {
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap; j += gap;
	return i < n && j < n ? pos[i] < pos[j] : j < i;
}

void buildSA() {
	n = strlen(s);
	s[n++] = '$';
	s[n] = 0;
	for (int i = 0; i < n; ++i) {
		sa[i] = i;
		pos[i] = s[i];
	}
	for (gap = 1;; gap <<= 1) {
		sort(sa, sa + n, cmp);
		for (int i = 1; i < n; ++i)
			tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
		for (int i = 0; i < n; ++i)
			pos[sa[i]] = tmp[i];
		if (tmp[n - 1] == n - 1) break;
	}
}

void buildLCP() {
	lcp[0] = 0;
	for (int i = 0, k = 0; i < n; ++i) {
		if (pos[i] != 0) {
			for (int j = sa[pos[i] - 1]; s[i + k] == s[j + k]; ++k);
			lcp[pos[i]] = k;
			if (k) --k;
		}
	}
}

#define endl '\n'
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	cin.getline(s, N);
	while (t--) {
		cin.getline(s, N);
		if (s[0] == 0) {
			cout << 1 << endl;
			continue;
		}
		buildSA();
		buildLCP();
		unsigned long long ans = 0;
		for (int i = 1; i < n; ++i) {
			int len = n - sa[i] - 1;
			ans += (len - lcp[i]);
			// cout << i << " "<< ans << endl;
			// cout << i << " " << lcp[i] << " " << s + sa[i] << endl;
		}
		cout << ans << endl;
	}
	cout << flush;
}