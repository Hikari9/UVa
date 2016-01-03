#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long lag;
const int N = 100005;

struct FenwickTree {
	lag *fen; int n;
	FenwickTree(int n): n(n), fen(new lag[n + 1]) {}
	~FenwickTree() { delete[] fen; }
	void add(int i, lag x) {
		for (; i <= n; i += i & -i)
			fen[i] += x;
	}
	void add(int a, int b, lag x) {
		add(a, x); add(b + 1, -x);
	}
	lag get(int i) {
		lag S = 0;
		for (; i > 0; i -= i & -i)
			S += fen[i];
		return S;
	}
	// min lb such that S <= lb
	int lowerBound(lag S) {
		S--;
		int h, lb = 0;
		for (h = 1; h <= n; h <<= 1);
		for (h >>= 1; h > 0; h >>= 1) {
			lb += h;
			if (lb <= n && S >= fen[lb])
				S -= fen[lb];
			else
				lb -= h;
		} return lb + 1;
	}
	void print() {
		cout << "Array: ";
		for (int i = 1; i <= n; ++i)
			cout << get(i) << " ";
		cout << endl;
	}
};

int n, q;
int c, x;
pair<lag, lag> arr[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	FenwickTree *tree = new FenwickTree(n);
	FenwickTree *inv = new FenwickTree(n);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 1; i <= n; ++i) {
		inv ->add(arr[i].second, arr[i].second, i);
		tree->add(i, arr[i].first - arr[i-1].first);
	}
	// print();
	while (q--) {
		cin >> c >> x;
		if (c == 1) {
			// pilgrim enters queue

			int ix = inv->get(x);
			lag pilgrim = tree->get(ix);
			int last = tree->lowerBound(pilgrim + 1) - 1;

			// swap positions with last
			assert(last > 0 && last <= n);
			int a = x, b = arr[last].second;
			int av = inv->get(x), bv = last;
			swap(arr[av].second, arr[bv].second);
			swap(inv[a], inv[b]);
			// add 1 to new x
			add(inv[x], 1);
			add(inv[x] + 1, -1);
			assert(inv[x] + 1 <= n && get(inv[x]) <= get(inv[x] + 1) && get(inv[x] - 1) <= get(inv[x]));
			// print();
		}
		else if (c == 2) {
			// count number of queues at least x
			int lb = lowerBound(x);
			cout << (n - lb + 1) << '\n';
		} else {
			// open the doors of all queues at least x
			int lb = lowerBound(x);
			add(lb, -1);
		}
	}
	cout << flush;
	delete sorted, inv;
}