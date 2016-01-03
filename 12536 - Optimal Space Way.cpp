// UVa 12536 - Optimal Space Way AC Line Regression
#include <iostream>
#include <cmath>
using namespace std;

int N, Q, tc, S;
double x[10001], y[10001], M;
double X, Y, X2, Y2, XY;
double a, b, c, disc, s1, s2, b1, b2;

double optimal(double s, double b) {
	double sum = 0;
	for (int i=0; i<N; ++i) {
		double top = s*x[i] - y[i] + b;
		sum += top * top;
	}
	double top = s*x[S] - y[S] + b;
	sum += (M - 1) * top * top;
	return sum / (s * s + 1);
}

double optimal() {
	double a = XY - X*Y/(N + M - 1);
	double b = X2 - Y2 + (Y*Y - X*X)/(N + M - 1);
	double c = -XY + X*Y/(N + M - 1);
	double disc = sqrt(b*b - 4*a*c);
	double s1 = (-b + disc) / (2*a);
	double s2 = (-b - disc) / (2*a);
	double b1 = (Y - s1*X) / (N + M - 1);
	double b2 = (Y - s2*X) / (N + M - 1);
	return min(optimal(s1, b1), optimal(s2, b2)) / (N + M - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(5);
	while (cin >> N >> Q, N || Q) {
		cout << "Case " << ++tc << ":" << endl;
		X = Y = X2 = Y2 = XY = 0;
		for (int i=0; i<N; ++i) {
			cin >> x[i] >> y[i];
			X += x[i];
			Y += y[i];
			X2 += x[i] * x[i];
			Y2 += y[i] * y[i];
			XY += x[i] * y[i];
		}
		M = 1;
		S = 0;
		cout << optimal() << endl;
		for (int q=1; q<=Q; ++q) {
			cin >> S >> M;
			X += (M - 1) * x[S];
			Y += (M - 1) * y[S];
			X2 += (M - 1) * x[S] * x[S];
			Y2 += (M - 1) * y[S] * y[S];
			XY += (M - 1) * x[S] * y[S];
			cout << q << ": " << optimal() << endl;
			X -= (M - 1) * x[S];
			Y -= (M - 1) * y[S];
			X2 -= (M - 1) * x[S] * x[S];
			Y2 -= (M - 1) * y[S] * y[S];
			XY -= (M - 1) * x[S] * y[S];
		}
	}
}
