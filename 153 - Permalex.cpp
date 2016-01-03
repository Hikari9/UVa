#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#define MX 35
#define endl '\n'

using namespace std;
typedef long long lag;

map<int, int> factors[MX];

// pregen prime factors
void pregen() {
	for (int i = 2; i < MX; ++i) {
		factors[i] = factors[i - 1];
		int x = i;
		for (int j = 2; x > 1; ++j) {
			while (x % j == 0) {
				x /= j;
				factors[i][j]++;
			}
		}
	}
}

lag power(lag b, int e) {
	lag ans = 1;
	while (e) {
		if (e & 1)
			ans *= b;
		if (e >>= 1)
			b *= b;
	}
	return ans;
}

lag permutations(map<char, int>& cnt) {
	lag total = 0;
	for (auto& it : cnt)
		total += it.second;

	map<int, int> f;
	for (auto& prime : factors[total]) {
		f[prime.first] += prime.second;
	}

	for (auto& it : cnt) {
		for (auto& prime : factors[it.second]) {
			f[prime.first] -= prime.second;
		}
	}
	lag ans = 1;
	for (auto& it : f) {
		ans *= power(it.first, it.second);
	}
	return ans;
}

map<char, int> cnt;
set<char> letters;

lag score(const string& s) {
	int len = s.length();
	cnt.clear();
	for (int i = 0; i < len; ++i)
		cnt[s[i]]++;
	lag ans = 0;
	for (int i = 0; i < len; ++i) {
		letters.clear();
		for (int j = i; j < len; ++j)
			letters.insert(s[j]);
		for (char letter : letters) {
			if (letter >= s[i])
				break;
			// combinatorics: n! / (a!b!...)
			cnt[letter]--;
			ans += permutations(cnt);
			// cout << "\t" << i << ": " << permutations(cnt) << endl;
			cnt[letter]++;
		}
		cnt[s[i]]--;
	}
	return ans + 1;
}

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pregen();
	while (getline(cin, s)) {
		if (s == "#") break;
		cout.width(10);
		cout << score(s) << endl;
	}
	cout << flush;
}