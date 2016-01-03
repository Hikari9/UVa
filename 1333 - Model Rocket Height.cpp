// UVa 1333 - Model Rocket Height
// Accepted 0.015s C++

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double D, H;
double a, b, c;
double x, y, z;

double cot2 (double theta) {
	theta *= M_PI / 180.;
	return 1 / tan(theta) / tan(theta);
}

int main () {
	while (scanf("%lf%lf", &D, &H) == 2) {
		while (scanf("%lf%lf%lf", &a, &b, &c) && a > 0 && b > 0 && c > 0) {
			a = cot2(a);
			b = cot2(b);
			c = cot2(c);
			x = D * (c - a) / (2 * a - 4 * b + 2 * c);
			z = sqrt(((x - D) * (x - D) - x * x) / (a - b));
			y = sqrt(c * z * z - (x + D) * (x + D));
			printf("%.0lf\n", z + H);
		}
	}
}
