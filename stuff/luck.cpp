#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int N = 2000001;
// splay order statistics set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
oset nums;


void build() {
	// 6i + 1 and 6i + 3
	for (int i = 1; i < N; i += 2) {
		nums.insert(i);
	}
	long dh = 0;
	for (oset::iterator it = ++nums.begin(); it != nums.end(); ++it) {
		int skip = *it - 1;
		if (skip >= nums.size()) break;
		for (int j = skip; j < nums.size(); j += skip)
			nums.erase(nums.find_by_order(j));
	}
	cout << nums.size() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	build();

	cout << flush;
}