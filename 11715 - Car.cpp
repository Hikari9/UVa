#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, tc;
double x, y, z;
const char * format = "%.3lf %.3lf\n";

int main() {
	while (scanf("%d", &n) == 1 && n) {
		scanf("%lf%lf%lf", &x, &y, &z);
		printf("Case %d: ", ++tc);
		// Kinematics:
		// s = ut + 1/2at^2
		// s = vt - 1/2at^2
		// v^2 = u^2 + 2as
		// s = (u + v) / 2 * t
		double u, v, t, s, a;
		switch (n) {
			case 1:
				u = x;
				v = y;
				t = z;
				s = (u + v) * t / 2;
				a = (v*v - u*u) / (2*s);
				printf(format, s, a);
				break;
			case 2:
				u = x;
				v = y;
				a = z;
				s = (v*v - u*u) / (2*a);
				t  = s * 2 / (u + v);
				printf(format, s, t);
				break;
			case 3:
				u = x;
				a = y;
				s = z;
				v = sqrt(u*u + 2*a*s);
				t = s * 2 / (u + v);
				printf(format, v, t);
				break;
			case 4:
				v = x;
				a = y;
				s = z;
				u = sqrt(v*v - 2*a*s);
				t = s * 2 / (u + v);
				printf(format, u, t);
				break;
		}
		
	}
}
