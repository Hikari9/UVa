#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;
typedef long double LD;

LL ax, ay, r1;
LL bx, by, r2;

LD subsector(LD r, LD theta) {
	LD sector = r * r * acosl(theta);
	LD triangle = r * r * sinl(acosl(theta)) * theta;
	return sector - triangle;
}

LD area() {
	LL d2 = (ax-bx) * (ax-bx) + (ay-by) * (ay-by);
	LD d = sqrtl(d2);
	if (r1 + r2 <= d) return 0; // no intersection
	if (abs(r1 - r2) >= d) return min(r1, r2) * min(r1, r2) * M_PI; // circle in circle
	LD theta1 = (r1 * r1 + d * d - r2 * r2) / (2.0 * d * r1);
	LD theta2 = (r2 * r2 + d * d - r1 * r1) / (2.0 * d * r2);
	if (d + min(r1, r2) < max(r1, r2))
		return abs(subsector(r1, theta1) - subsector(r2, theta2));
	return subsector(r1, theta1) + subsector(r2, theta2);
}

int main() {
	cout.precision(20);
	cout << fixed;
	cin >> ax >> ay >> r1 >> bx >> by >> r2;
	cout << (double) area() << endl; // printing bugs in C++
}