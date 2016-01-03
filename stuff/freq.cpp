#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
const int N = 100005;
const int logN = 20;

map<int, int> first, last, freq;
int spt[N << 1][logN], id[N], arr[N], log2[N*2 + 1], n, m;

void build() {
	first.clear(); last.clear(); freq.clear();
	for (int i = 0; i < n; ++i) {
		if (i == 0 || arr[i] != arr[i - 1])
			first[arr[i]] = i;
		last[arr[i]] = i;
		freq[arr[i]]++;
		id[i] = freq.size() - 1;
	}
	n = freq.size();
	map<int, int>::iterator it = freq.begin();
	for (int i = 0; i < n; ++i) {
		spt[i][0] = it->second;
		++it;
	}
	for (int j = 0; (2 << j) <= n; ++j) {
		for (int i = 0; i + (2 << j) <= n; ++i) {
			int k = i + (1 << j);
			spt[i][j+1] = max(spt[i][j], spt[k][j]);
		}
	}
}

int query(int a, int b) {
	if (b < a) swap(a, b);
	if (arr[a] == arr[b]) return b - a + 1;
	int ans = max(last[arr[a]] - a + 1, b - first[arr[b]] + 1);
	a = last[arr[a]] + 1;
	b = first[arr[b]] - 1;
	if (a <= b) {
		a = id[a]; b = id[b];
		int k = log2[b - a + 1];
		int ab = b - (1 << k) + 1;
		ans = max(ans, max(spt[a][k], spt[ab][k]));
	}
	return ans;
}

int a, b;

int main() {
	for (int i = 1, l = -1; i <= N*2; ++i) {
		if (!(i & (i - 1))) l++;
		log2[i] = l;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m, n) {
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		while (m--) {
			cin >> a >> b; --a, --b;
			cout << query(a, b) << '\n';
		}
	}
	cout << flush;
}