// Splay Order Statistics Tree
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1850

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ctime>

using namespace std;
using namespace __gnu_pbds;
const int N = 2000001;
typedef tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> oset;
oset nums;

int lucky[N], size;
int dp[N], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < N; i += 2) {
		nums.insert(i);
	}
	for (oset::iterator it = ++nums.begin(); it != nums.end(); ++it) {
		int strike = *it;
		if (strike > nums.size()) break;
		for (int j = strike - 1; j < nums.size(); j += strike - 1) {
			nums.erase(nums.find_by_order(j));
		}
	}
	for (oset::iterator it = nums.begin(); it != nums.end(); ++it)
		lucky[*it] = 1;
	while (cin >> n) {
		if (n & 1)
			cout << n << " is not the sum of two luckies!\n";
		else {
			if (!dp[n]) {
				dp[n] = -1;
				for (int i = n / 2; i >= 1; --i) {
					if (lucky[i] && lucky[n - i]) {
						dp[n] = i;
						break;
					}
				}
			}
			if (dp[n] == -1) {
				cout << n << " is not the sum of two luckies!\n";
			}
			else {
				cout << n << " is the sum of " << dp[n] << " and " << n - dp[n] << ".\n";
			}
		}
	}
	cout << flush;
}