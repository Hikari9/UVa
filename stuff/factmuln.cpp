#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MX = 1000000;

bool isPrime[MX];
int primes[MX>>1], prsize;
void sieve() {
	primes[prsize++] = 2;
	isPrime[2] = true;
	for (int i = 3; i < MX; i += 2)
		isPrime[i] = true;
	for (int i = 3; i < MX; i += 2) {
		if (isPrime[i]) {
			primes[prsize++] = i;
			if ((long long) i * i < MX) {
				for (int j = i * i; j < MX; j += i)
					isPrime[j] = false;
			}
		}
	}
}

int t, n, pr[MX], ex[MX], size;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	cin >> t;
	while (t--) {
		cin >> n;
		if (n < MX && isPrime[n]) {
			cout << n << endl;
			continue;
		}
		int ans = 1;
		for (int i = 0; i < prsize && n > 1; ++i) {
			int p = primes[i];
			if (p * p > n) break;
			int count = 0;
			while (n % p == 0) {
				count++;
				n /= p;
			}
			if (count > 0) {
				int actual = p;
				if (count < p) {
					actual = p + count - 1;
				}
				else {
					for (int j = p, total = 0; total < count; actual = j++)
						for (int k = p; j / k > 0; k *= p)
							total += j / k;
				}
				// cout << p << " " << count << ": " << actual << endl;
				ans = max(ans, actual);
			}
		}
		if (n > 1) {
			int p = n;
			int count = 1;
			int actual = p;
			if (count < p) {
				actual = p + count - 1;
			}
			else {
				for (int j = p, total = 0; total < count; actual = j++)
					for (int k = p; j / k > 0; k *= p)
						total += j / k;
			}
			// cout << p << " " << count << ": " << actual << endl;
			ans = max(ans, actual);
		}
		cout << ans << endl;
	}
}