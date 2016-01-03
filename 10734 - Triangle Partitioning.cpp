/**
	UVa 10734 - Triangle Partitioning
	by Rico Tiongson
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#define eps 1e-5
using namespace std;

struct triangle {
	double s[3];
	triangle() {}
	triangle(double a, double b, double c) {
		s[0] = a;
		s[1] = b;
		s[2] = c;
		sort(s, s + 3);
		double factor = 1000.0 / s[2];
		s[0] *= factor;
		s[1] *= factor;
		s[2] *= factor;
	}
	triangle * split() const {
		triangle * ans = new triangle[2];
		double a = s[0];
		double b = s[1];
		double c = s[2];
		double d = sqrt(a*a + c*c/4 + (b*b - a*a - c*c)/2);
		double d2 = sqrt(b*b + c*c/4 + (a*a - b*b - c*c)/2);
		assert(abs(d - d2) < eps);
		ans[0] = triangle(a, c/2, d);
		ans[1] = triangle(b, c/2, d);
		return ans;
	}
	bool operator < (const triangle& t) const {
		for (int i=0; i<3; ++i) {
			if (abs(s[i] - t.s[i]) > eps)
				return s[i] < t.s[i];
		}
		return false;
	}
	friend ostream& operator << (ostream& out, triangle t) {
		for (int i=0; i<3; ++i) out << t.s[i] << " || ";
		return out;
	}
};

set<triangle> visited;

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b, c, tc=0;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		visited.clear();
		queue<triangle> q;
		q.push(triangle(a, b, c));
		while (!q.empty()) {
			triangle t = q.front(); q.pop();
			// cout << t << endl;
			if (visited.count(t)) continue;
			visited.insert(t);
			triangle * s = t.split();
			q.push(s[0]);
			q.push(s[1]);
			// delete s;
			
		}
		printf("Triangle %d: %u\n", ++tc, visited.size());
	}
}
