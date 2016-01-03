// Live Archive 6045 - Alien Abduction
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4056

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>

using namespace std;

int vx[50005], vy[50005], vsize;
vector<int>* vi[50005];
long long ax, ay, bx, by;
int E, a, b, c, d, e, f, x, y;

struct node {
	int lx, ly, rx, ry, count;
	vector<int> id;
	node *ul, *ur, *dl, *dr;
	node(int lx, int rx, int ly, int ry):
		lx(lx), ly(ly), rx(rx), ry(ry), count(0), ul(NULL), ur(NULL), dl(NULL), dr(NULL) {}
	~node() {
		id.clear();
		if (ul) delete ul;
		if (ur) delete ur;
		if (dl) delete dl;
		if (dr) delete dr;
	}
	inline void pull() {
		if (ul && !ul->count) {
			delete ul;
			ul = NULL;
		}
		if (ur && !ur->count) {
			delete ur;
			ur = NULL;
		}
		if (dl && !dl->count) {
			delete dl;
			dl = NULL;
		}
		if (dr && !dr->count) {
			delete dr;
			dr = NULL;
		}
		count = 0;
		if (ul) count += ul->count;
		if (ur) count += ur->count;
		if (dl) count += dl->count;
		if (dr) count += dr->count;
	}

	// insert node to the tree
	void insert(int x, int y, int i) {
		if (lx == rx && ly == ry) {
			assert(x == lx && y == ly);
			++count;
			id.push_back(i);
			return;
		}
		int mx = (lx + rx) / 2;
		int my = (ly + ry) / 2;
		// cout << x << " " << (x <= mx) << " " << y << " " << (y <= my) << endl;
		if (x <= mx) {
			if (y <= my) {
				// down left
				if (!dl) dl = new node(lx, mx, ly, my);
				dl->insert(x, y, i);
			} else {
				// up left
				if (!ul) ul = new node(lx, mx, my + 1, ry);
				ul->insert(x, y, i);
			}
		} else {
			if (y <= my) {
				// down right
				if (!dr) dr = new node(mx + 1, rx, ly, my);
				dr->insert(x, y, i);
			} else {
				// up right
				if (!ur) ur = new node(mx + 1, rx, my + 1, ry);
				ur->insert(x, y, i);
			}
		}
		pull();
	}

	// put all nodes inside the rectangle to (vx, vy) vector
	void abduct() {
		if (bx < lx || rx < ax || by < ly || ry < ay)
			return; // can't abduct
		// prune quadrants
		if (E != -1) {
			if (x > rx) { // right
				if (y < ly) {if (0LL + x - rx + ly - y > E) return;}
				else if (y > ry) {if (0LL + x - rx + y - ry > E) return;}
				else if (0LL + x - rx > E) return;
			} else if (x < lx) { // left
				if (y < ly) {if (0LL + lx - x + ly - y > E) return;}
				else if (y > ry) {if (0LL + lx - x + y - ry > E) return;}
				else if (0LL + lx - x > E) return;
			} else { // mid
				if (y < ly) {if (0LL + ly - y > E) return;}
				else if (y > ry) {if (0LL + y - ry > E) return;}
				// inside
			}
		}
		if (lx == rx && ly == ry) {
			if (abs(1LL * lx - x) + abs(1LL * ly - y) > E && E != -1) return;
			// abduct this
			count = 0;
			vx[vsize] = lx;
			vy[vsize] = ly;
			vi[vsize++] = new vector<int>(id);
			id.clear();
			// printf("Abducted (%d %d)\n", lx, ly);
			return;
		} else {
			int mx = (lx + rx) / 2;
			int my = (ly + ry) / 2;
			if (dl) dl->abduct();
			if (ul) ul->abduct();
			if (dr) dr->abduct();
			if (ur) ur->abduct();
		}
		pull();
	}

};

int t, n, q, w, h, N, tc;
int tx[50005], ty[50005], ti[50005], size;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &q, &w, &h);
		// get largest power of 2 from (w, h)
		for (N = 1; N <= max(w, h)+1; N <<= 1);
		node *tree = new node(0, N-1, 0, N-1);
		// insert to tree
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x, &y);
			tree->insert(x, y, i);
		}
		// abduct queries
		while (q--) {
			scanf("%d%d%d%d%d%d%d%d%d", &x, &y, &E, &a, &b, &c, &d, &e, &f);
			ax = bx = x;
			ay = by = y;
			ax -= E;
			bx += E;
			ay -= E;
			by += E;
			// printf("From (%d, %d): Abduct energy: E=%d (%lld, %lld) (%lld, %lld)\n", x, y, E, ax, ay, bx, by);
			vsize = 0;
			tree->abduct();
			a %= w;
			b %= w;
			c %= w;
			d %= h;
			e %= h;
			f %= h;
			size = 0;
			// printf("Abduction %d\n", q);
			for (int i = 0; i < vsize; ++i) {
				ax = vx[i];
				ay = vy[i];
				// printf("Putting back (%lld, %lld)\n", ax, ay);
				vector<int>& v = *vi[i];
				bx = (ax * a % w + ay % w * b % w) % w;
				by = (ax * d % h + ay % h * e % h) % h;
				for (int j = 0; j < v.size(); ++j) {
					x = (int) ((bx + 1LL * c * v[j] % w) % w);
					y = (int) ((by + 1LL * f * v[j] % h) % h);
					// printf("Person %d abducted at (%lld, %lld) returned at (%d, %d)\n", v[j], ax, ay, x, y);
					tree->insert(x, y, v[j]);
				}
				v.clear();
			}
		}
		// abduct everything
		// printf("Abducting everything %d\n", N);
		E = -1;
		ax = 0, ay = 0, bx = N, by = N;
		vsize = 0;
		tree->abduct();
		// printf("\nABDUCT COMPLETE %d\n", vsize);
		for (int i = 0; i < vsize; ++i) {
			x = vx[i];
			y = vy[i];
			vector<int>& v = *vi[i];
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				tx[id] = x;
				ty[id] = y;
			}
			v.clear();
		}
		printf("Case #%d:\n", ++tc);
		for (int i = 1; i <= n; ++i)
			printf("%d %d\n", tx[i], ty[i]);
	}
}