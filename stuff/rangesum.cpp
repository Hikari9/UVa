#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200005;
typedef long long lag;

int n, q, op, L, R;
lag arr[N], x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = n; i > 0; --i) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		arr[i] += arr[i - 1];
	}
	cin >> q;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> L >> R;
			L = n - L + 1;
			R = n - R + 1;
			cout << arr[max(L, R)] - arr[min(L, R) - 1] << '\n';
		}
		else {
			cin >> x;
			arr[n + 1] = arr[n] + x;
			++n;
		}
	}

	cout << flush;
}