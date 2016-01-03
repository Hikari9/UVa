// SPOJ LCS - Longest Common Substring
// http://www.spoj.com/problems/LCS/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 250001;

int length[N << 1], fail[N << 1];
int next[N << 1][26], size;
void suffixAutomaton(const string& s) {
	memset(next[0], -1, sizeof next[0]);
	fail[0] = -1;
	length[0] = 0;
	size = 1;
	for (int i = 0, last = 0; i < s.length(); i++) {
		int c = s[i] - 'a', cur = size++;
		memset(next[cur], -1, sizeof next[cur]);
		length[cur] = length[last] + 1;
		fail[cur] = 0;
		int p = last;
		while (p != -1 && next[p][c] == -1) {
			next[p][c] = cur;
			p = fail[p];
		}
		if (p == -1) fail[cur] = 0;
		else {
			int child = next[p][c];
			if (length[p] + 1 == length[child])
				fail[cur] = child;
			else {
				int clone = size++;
				length[clone] = length[p] + 1;
				fail[clone] = fail[child];
				memcpy(next[clone], next[child], sizeof next[child]);
				while (p != -1 && next[p][c] == child) {
					next[p][c] = clone;
					p = fail[p];
				}
				fail[cur] = fail[child] = clone;
			}
		}
		last = cur;
	}
}

int LCS(const string& a, const string& b) {
	suffixAutomaton(a);
	int len = 0, lcs = 0, id = -1;
	for (int i = 0, cur = 0; i < b.length(); i++) {
		// cout << i << " " << cur << endl;
		int c = b[i] - 'a';
		if (next[cur][c] == -1) {
			while (cur != -1 && next[cur][c] == -1)
				cur = fail[cur];
			if (cur == -1) {cur = len = 0; continue;}
			len = length[cur];
		}
		++len;
		cur = next[cur][c];
		if (lcs < len) {
			lcs = len;
			id = i;
		}
	}
	id -= lcs - 1;
	return lcs; // return b.substr(id, lcs);
}

string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	cout << LCS(a, b) << endl;
}