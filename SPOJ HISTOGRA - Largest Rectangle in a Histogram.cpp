// SPOJ HISTOGRA
// http://www.spoj.com/problems/HISTOGRA/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef struct pair<int, int> edge;
const int N = 100001;

int f[N], c[N], h[N], n;
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a != b) {
		f[a] = b;
		c[b] += c[a];
	}
}

priority_queue<edge> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n, n) {
		long long area = 0;
		pq = priority_queue<edge>();
		for (int i = 0; i < n; ++i) {
			cin >> h[i];
			f[i] = i;
			c[i] = 1;
			pq.push(edge(h[i], i));
			area = max(area, (long long) h[i]);
		}
		while (!pq.empty()) {
			edge e = pq.top(); pq.pop();
			int x = find(e.second);
			if (e.second > 0 && h[e.second - 1] >= e.first) {
				merge(e.second, e.second - 1);
			}
			if (e.second + 1 < n && h[e.second + 1] >= e.first) {
				merge(e.second, e.second + 1);
			}
			area = max(area, e.first * (long long) c[find(e.second)]);
		}
		cout << area << '\n';
	}
	cout << flush;
}