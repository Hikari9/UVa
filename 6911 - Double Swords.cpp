/**
 * Live Archive 6911 - Double Swords
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000001, M = 100001;

int t, n, tc;
int stack[M], keep[M], in[M];
bool betray[N];
vector<int> a[N], b[N], c[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < N; ++i) {
			a[i].clear();
			b[i].clear();
			c[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			a[x].push_back(i);
			b[y].push_back(i);
			c[z].push_back(i);
		}
		int total = 0;
		int top = 0;
		for (int i = 0; i < N; ++i) {
			// add all starting points
			for (int x : b[i]) {
				stack[top++] = x;
				++in[x];
			}
			if (a[i].size()) {
				// force pop on single entry
				for (int x : a[i])
					betray[x] = true;
				int k = 0;
				while (top)
					if (betray[stack[--top]]) // don't pop if both single entry and in-range
						keep[k++] = stack[top];
					else {
						// cout << "Unbet: " << i << " " << stack[top] << endl; 
						--in[stack[top]];
					}
				while (k)
					stack[top++] = keep[--k];
				for (int x : a[i])
					betray[x] = false;
				total++;
				// cout << "Force: " << i << " " << total << endl;
			}
			bool pop = false;
			for (int x : c[i]) {
				if (in[x]) {
					// force pop if partner exists
					// cout << "Force pop: " << i << " " << x << endl;
					pop = true;
					break;
				}
			}
			// if (total == 3) cout << i << endl;
			if (pop) {
				total++;
				while (top) {
					// cout << "Unbetrayed: " << i << " " << total << endl;
					--in[stack[--top]];
				}
			}
		}
		printf("Case #%d: %d\n", ++tc, total);
	}
}