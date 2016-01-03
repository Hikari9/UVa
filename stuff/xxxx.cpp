#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define P (p << 1)
#define M ((L + R) >> 1)

using namespace std;
const int N = 50001;
const int sqrtN = 224;

int n, sn, arr[N];
lag sum[sqrtN];
mapper bucket[sqrtN];

void build() {
	sn = ceil(sqrt(n));
	for (int i = 0; i < n; ++i) {
		if (++bucket[i / sn][arr[i]] == 1)
			sum[i / sn] += arr[i];
	}
}

mapper temp;

lag query(int a, int b) {
	if (a / sn == b / sn) {
		temp.clear();
		lag S = 0;
		for (int i = a; i <= b; ++i) {
			if (++temp[arr[i]] == 1)
				S += arr[i];
		}
		return S;
	}
	temp.clear();
	lag S = 0;
	if (a % sn != 0) {
		temp.clear();
		while (a < n && a % sn != 0) {

		}
		for (int i = a; i < n && i % sn != 0; ++i) {

		}
	}
	
}

char cmd;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	build();
	cin >> q;
	while (q--) {
		cin >> cmd >> a >> b;
		if (cmd == 'Q')
			cout << query(--a, --b) << '\n';
		else
			update(--a, b);
	}
	cout << flush;
}