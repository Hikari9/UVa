#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
const int N = 200001;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int t, n, arr[N], pos[N];
oset elem;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		elem.clear();
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			elem.insert(i + 1);
		}
		for (int i = n - 1; i >= 0; --i) {
			oset::iterator it = elem.find_by_order(arr[i]);
			pos[i] = *it;
			elem.erase(it);
		}
		for (int i = 0; i < n; ++i) {
			if (i) cout << ' ';
			cout << pos[i];
		}
		cout << '\n';
	}
	cout << flush;
}