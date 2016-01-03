// UVa 10625 - GNU
// By Rico Tiongson
// Linear Algebre 

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define endl '\n'

using namespace std;
typedef unsigned long long lag;
typedef map<char, map<char, lag>> matrix;

matrix identity() {
	matrix I;
	for (int i = 0; i < 128; ++i)
		I[i][i] = 1;
	return I;
}

matrix multiply(const matrix& A, const matrix& B) {
	matrix ans;
	for (auto& i : A) {
		for (auto& k : i.second) {
			auto row = B.find(k.first);
			if (row != B.end()) {
				for (auto& j : row -> second) {
					ans[i.first][j.first] += k.second * j.second;
				}
			}
		}
	}
	return ans;
}

matrix pow(matrix b, int e) {
	matrix ans = identity();
	while (e) {
		if (e & 1)
			ans = multiply(ans, b);
		if (e >>= 1)
			b = multiply(b, b);
	}
	return ans;
}

matrix convert(const string& text) {
	matrix m;
	for (auto c : text)
		m[0][c]++;
	return m;
}

ostream& operator << (ostream& out, const matrix& m) {
	for (auto& row : m) {
		if (row.second.size() == 1)
			continue;
		for (auto& col : row.second) {
			out << row.first << " -> " << col.first << " " << col.second << endl;
		}
	}
	return out;
}

int t, n, k;
string s;
char letter;
matrix adj;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		adj = identity();
		for (int i = 0; i < n; ++i) {
			cin >> s;
			adj[s[0]].clear();
			for (int i = 3; i < s.length(); ++i)
				adj[s[0]][s[i]]++;
		}
		cin >> n;
		while (n--) {
			cin >> s >> letter >> k;
			cout << multiply(convert(s), pow(adj, k))[0][letter] << endl;
		}
	}
	cout << flush;
}