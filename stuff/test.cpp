#include <bits/stdc++.h>

using namespace std;
const int N = 100001;

int n,  v[N], size, start[N], len[N];
long long a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int mx = 0;
	for (int i = 0, j; i < n; i = j) {
		start[i] = v[size++] = i;
		len[i] = 1;
		for (j = i + 1; j < n; ++j) {
			if (a[j - 1] >= a[j]) {
				break;
			}
			start[j] = i;
			len[i]++;
		}
		mx = max(mx, len[i] + 1);
	}
	// try combining segments
	for (int i = 1; i < size; ++i) {
		int s = v[i - 1];
		int t = v[i];
		// try changing t
		if (t + 1 < n && a[t - 1] + 1 < a[t + 1]) {
			if (start[t + 1] == start[t])
				mx = max(mx, len[s] + len[t]);
			else
				mx = max(mx, len[s] + len[t + 1] + 1);
		}
		// try changing t - 1
		if (s <= t - 2 && a[t - 2] + 1 < a[t]) {
			mx = max(mx, len[s] + len[t]);
		}
	}
	cout << min(mx, n) << endl;
}