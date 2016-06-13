// UVa 10043 - Chainsaw Massacre
// by Rico Tiongson
// 06/13/15

#include <bits/stdc++.h>

// macros
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define forr(i, a, n) for (int i = (n) - 1; i >= a; --i)
#define pb push_back

using namespace std;
const int N = 3050;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int t, n, L, W;
int k, x, y, dx, dy;
pii tree[N];
multiset<int> bound, mbound;

ll sweep() {
	sort(tree, tree + n);
	ll ans = 0;
	forn (i, 0, n-1) {
		int left = tree[i].first;
		if (i + 1 < n && left != tree[i+1].first) {
			bound.clear();
			mbound.clear();
			bound.insert(0);
			bound.insert(W);
			mbound.insert(W);
			forn (j, i + 1, n) {
				int right = tree[j].first;
				int line = tree[j].second;
				int upd = *mbound.rbegin();
				ans = max(ans, 1LL * upd * (right - left));
				if (bound.count(line))
					continue;
				auto top = bound.lower_bound(line);
				auto bot = top; --bot;
				mbound.erase(mbound.find(*top - *bot));
				mbound.insert(*top - line);
				mbound.insert(line - *bot);
				bound.insert(line);
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &L, &W);
		n = 0;
		tree[n++] = {0, 0};
		tree[n++] = {L, 0};
		tree[n++] = {0, W};
		tree[n++] = {L, W};
		while (scanf("%d", &k) == 1 && k) {
			if (k == 1) {
				scanf("%d%d", &x, &y);
				if (x >= 0 && x <= L && y >= 0 && y <= W) {
					// cout << x << ' ' << y << endl;
					tree[n++] = {x, y};
				}
			} else {
				scanf("%d%d%d%d", &x, &y, &dx, &dy);
				forn (i, 0, k) {
					if (x >= 0 && x <= L && y >= 0 && y <= W) {
						// cout << x << ' ' << y << endl;
						tree[n++] = {x, y};
					}
					x += dx;
					y += dy;
				}
			}
		}
		printf("%lld\n", sweep());
	}
}
