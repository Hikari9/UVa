#include <bits/stdc++.h>

using namespace std;

int t, n, arr[30001], temp[30001];
long long inv;
map<string, queue<int> > order;
char buf[21];

void mergeSort(int L, int R) {
	if (L >= R) return;
	int M = (L + R) / 2;
	mergeSort(L, M);
	mergeSort(M + 1, R);
	int i = L, j = M + 1, c = 0;
	while (i <= M && j <= R) {
		if (arr[i] < arr[j]) {
			temp[c++] = arr[i++];
		} else {
			temp[c++] = arr[j++];
			inv += M - i + 1;
		}
	}
	while (i <= M) temp[c++] = arr[i++];
	while (j <= R) temp[c++] = arr[j++];
	for (int i = 0; i < c; ++i)
		arr[L + i] = temp[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		order.clear();
		for (int i = 0; i < n; ++i) {
			cin >> buf;
			order[buf].push(i);
		}
		for (int i = 0; i < n; ++i) {
			cin >> buf;
			queue<int>& q = order[buf];
			arr[i] = q.front(); q.pop();
		}
		inv = 0;
		mergeSort(0, n - 1);
		cout << inv << '\n';
	}
	cout << flush;
}