#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
#include <valarray>

using namespace std;
typedef complex<double> Complex;

void fft(Complex p[], int n) {
	int h = n / 2;
	if (n <= 1) return;
	Complex *even = new Complex[h];
	Complex  *odd = new Complex[h];
	for (int i = 0; i < n; ++i){
		if (i & 1)
			odd[i >> 1] = p[i];
		else
			even[i >> 1] = p[i];
	}
	fft(even, h); fft(odd, h);
	double a = 2 * M_PI / n;
	Complex wn(cos(a), sin(a)), w(1, 0);
	for (int k = 0; k < h; ++k) {
		p[k] = even[k] + w * odd[k];
		p[k + h] = even[k] - w * odd[k];
		w *= wn;
	}
	delete[] even, odd;
}

void inverse_fft(Complex p[], int n) {
	for (int i = 0; i < n; ++i)
		p[i].imag() *= -1;
	fft(p, n);
	for (int i = 0; i < n; ++i) {
		p[i].imag() *= -1;
		p[i] /= n;
	}
}

Complex* multiply(Complex a[], Complex b[], int n) {
	int n2 = 2 * n, h;
	for (h = 1; h < n2; h <<= 1);
	Complex *na = new Complex[h];
	Complex *nb = new Complex[h];
	for (int i = 0; i < n; ++i)
		na[i] = a[i];
	for (int i = 0; i < n; ++i)
		nb[i] = b[i];
	fft(na, h); fft(nb, h);
	for (int i = 0; i < h; ++i)
		na[i] *= nb[i];
	inverse_fft(na, h);
	delete[] nb;
	return na;
}

int t, n;
Complex a[10001], b[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= n; ++i) {
			int x;
			cin >> x;
			a[n - i] = x;
		}
		for (int i = 0; i <= n; ++i) {
			int x;
			cin >> x;
			b[n - i] = x;
		}
		Complex *p = multiply(a, b, n + 1);
		int deg = n * 2;
		for (int i = 0; i <= deg; ++i) {
			if (i) cout << ' ';
			cout << (long long) round(p[deg - i].real());
		}
		delete[] p;
		cout << '\n';
	}
	cout << flush;
}