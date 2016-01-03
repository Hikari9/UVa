#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100001;

int x[N], y[N], lis[N], size, n;

int LIS(int arr[]) {
	size = 0;
	for (int i = 0; i < n; ++i) {
		int lb = (int) (lower_bound(lis, lis + size, arr[i]) - lis);
		lis[lb] = arr[i];
		if (lb == size) size++;
	}
	return size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	cout << min(LIS(x), LIS(y)) << endl;
}