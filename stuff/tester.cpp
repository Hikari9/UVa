// SPOJ SARRAY - Suffix Array
// http://www.spoj.com/problems/SARRAY/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define endl '\n'

using namespace std;
const int MX = 100005;

char s[MX];
int N, pos[MX], val[MX], cnt[MX], sa[MX],  gap;

bool cmp(int i, int j) {
	return s[i] != s[j] ? s[i] < s[j] : j < i;
}
bool equal(int i, int j) {
	return pos[i] == pos[j]
		&& i + gap < N
		&& pos[i + gap/2] == pos[j + gap/2];
}

void buildSA() {
	N = strlen(s); s[N++] = '$';
	for (int i = 0; i < N; ++i)
		sa[i] = i, pos[i] = s[i];
	sort(sa, sa + N, cmp);
	for (gap = 1; gap < N; gap <<= 1) {
		val[sa[0]] = 0;
		for (int i = 1; i < N; ++i)
			val[sa[i]] = equal(sa[i - 1], sa[i]) ? val[sa[i - 1]] : i;
		for (int i = 0; i < N; ++i) {
			{ pos[i] = val[i]; val[i] = sa[i]; cnt[i] = i; }
		for (int i = 0; i < N; i++) {
			int id = val[i] - gap;
			if (id >= 0) sa[cnt[pos[id]]++] = id;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	buildSA();
	for (int i = 1; i < N; ++i)
		cout << sa[i] << endl;
	cout << flush;
}