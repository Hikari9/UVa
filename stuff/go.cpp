#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
typedef long long lag;
const int N = 100005;

int t, n, p[N], q[N], tc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		for (int i = 0; i < n; ++i)
			cin >> q[i];
		lag sum = 0, mn = LLONG_MAX;
		for (int i = 0; i < n; ++i) {
			sum += p[i] - q[i];
			mn = min(mn, sum);
		}
		int index = 0;
		while (mn < 0 && index < n) {
			mn -= p[index] - q[index++];
		}
		cout << "Case " << ++tc << ": ";
		if (index == n || sum < 0)
			cout << "Not possible\n";
		else
			cout << "Possible from station " << index + 1 << "\n";
	}

	cout << flush;
}