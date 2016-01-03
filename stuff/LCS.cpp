#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MX = 500005;

char s[MX];
int N, pos[MX], tmp[MX], sa[MX], lcp[MX], cnt[MX], gap, alen, blen;

bool cmp(int i, int j) {
	return s[i] != s[j] ? s[i] < s[j] : j < i;
}

bool sufEqual(int i, int j) {
	if (pos[i] != pos[j]) return false;
	if (i + gap >= N) return false;
	i += gap / 2; j += gap / 2;
	return pos[i] == pos[j];
}

void buildSuffixArray() { // O (n log n)
	N = alen + blen;
	for (int i = 0; i < N; ++i)
		sa[i] = i, pos[i] = s[i];
	sort(sa, sa + N, cmp);
	for (gap = 1; gap < N; gap <<= 1) {
		for (int i = 0; i < N; ++i)
			tmp[i] = pos[i];
		for (int i = 0; i < N; ++i)
			tmp[sa[i]] = (i > 0 && sufEqual(sa[i-1], sa[i]) ? tmp[sa[i-1]] : i);
		for (int i = 0; i < N; ++i)
			pos[i] = tmp[i], tmp[i] = sa[i], cnt[i] = i;
		for (int i = 0; i < N; ++i) {
			int id = tmp[i] - gap;
			if (id >= 0)
				sa[cnt[pos[id]]++] = id;
		}
	}
	for (int i = 0; i < N; ++i)
		pos[sa[i]] = i;
}

void buildLCP() {
	for (int i = 0, k = 0; i < N; ++i) {
		if (pos[i] != N - 1) {
			for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k]; ++k);
			lcp[pos[i]] = k;
			if (k) k--;
		} else lcp[pos[i]] = 0;
	}
}

int LCS() {
	buildSuffixArray();
	buildLCP();
	int lcs = 0;
	for (int i = 0; i + 1 < N; ++i) {
		if ((sa[i] < alen) != (sa[i + 1] < alen)) {
			lcs = max(lcs, lcp[i]);
		}
	}
	return lcs;
}

int main() {
	scanf("%s", s);
	alen = strlen(s);
	s[alen++] = '$';
	scanf("%s", s + alen);
	blen = strlen(s + alen);
	s[alen + (blen++)] = '#';
	printf("%d\n", LCS());
}