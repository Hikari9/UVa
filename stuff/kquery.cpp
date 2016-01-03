#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 30001;
const int M = 200001;


map<int, int> Map;
int fenwick[N + 1], arr[N], arrid[N], qid[M], a[M], b[M], ans[M], K, q, n, positions[N], queries[N];
int *P[N], *Q[N]; int size, Psize[N], Qsize[N];

void add(int i, int x) {
	for (++i; i <= n; i += i & -i)
		fenwick[i] += x;
}

int sum(int i) {
	int S = 0;
	for (++i; i > 0; i -= i & -i)
		S += fenwick[i];
	return S;
}

int sum(int a, int b) { return sum(b) - sum(a - 1); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int d = Map.insert(make_pair(arr[i], Map.size())).first->second;
		arrid[i] = d;
		positions[d]++;
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> a[i] >> b[i] >> K;
		map<int, int>::iterator it = Map.upper_bound(K);
		if (it != Map.end()) {
			qid[i] = it->second;
			queries[it->second]++;
		}
		else {
			qid[i] = -1;
		}
	}
	for (int i = 0, M = Map.size(); i < M; ++i) {
		P[i] = new int[positions[i]];
		Q[i] = new int[queries[i]];
	}
	for (int i = 0; i < n; ++i) {
		P[arrid[i]][Psize[arrid[i]]++] = i;
	}
	for (int i = 0; i < q; ++i) {
		if (qid[i] != -1) Q[qid[i]][Qsize[qid[i]]++] = i;
	}
	for (map<int, int>::reverse_iterator it = Map.rbegin(); it != Map.rend(); ++it) {
		int d = it->second;
		for (int i = 0; i < Psize[d]; ++i) {
			add(P[d][i], 1);
		}
		for (int i = 0; i < Qsize[d]; ++i) {
			int id = Q[d][i];
			ans[id] = sum(a[id] - 1, b[id] - 1);
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
	cout << flush;
}