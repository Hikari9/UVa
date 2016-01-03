// APIO 2014 - Palindromes
// By Rico Tiongson
// O(n) using suffix tree and Manacher's algorithm

#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stack>
#define MX 700000

using namespace std;
typedef long long lag;

struct tree;

string s;
char c[MX];
int span[MX];
tree *node[MX], *palindromes[MX];
int p;

lag score();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cout << score() << endl;
}

struct tree {
	tree *next[26];
	lag cnt;
	int depth;
	tree *parent;

	tree(int d = 0, tree *p = NULL):
		cnt(0), depth(d), parent(p) {
			for (int i = 0; i < 26; ++i)
				next[i] = NULL;
		}

	tree* get(char c) {
		if (next[c - 'a'] != NULL)
			return next[c - 'a'];
		else {
			return palindromes[p++] = next[c - 'a'] = new tree(depth + 2, this);
		}
	}

};

lag score() {

	// prepare boundary array

	int n = s.length();
	int cn = n * 2 + 1;

	for (int i = 0; i < n; ++i)
		c[i * 2 + 1] = s[i];

	tree *odd = new tree(-1);
	tree *even = new tree();

	// prepare tree nodes

	for (int i = 0; i < cn; ++i) {
		if (i & 1) {
			node[i] = odd -> get(c[i]);
		}
		else {
			node[i] = even;
		}
	}

	int center = 0, radius = 0;
	int left = 0, right = 0; // two pointers

	// manacher's algorithm: extend palindromes in tree
	// linear time

	for (int i = 1; i < cn; ++i) {
		if (i > radius) {
			// no cache
			span[i] = 0;
			left = i - 1;
			right = i + 1;
		}
		else {
			// cache from mirror
			int mirror = center * 2 - i;
			if (span[mirror] < radius - i) {
				// node will be exactly the same as mirror
				span[i] = span[mirror];
				node[i] = node[mirror];
				left = -1;
			}
			else {
				// node will be a little shorter than mirror
				span[i] = radius - i;
				right = radius + 1;
				left = i * 2 - right;
				node[i] = node[mirror];
				while (node[i] -> depth > radius - i)
					node[i] = node[i] -> parent;
			}
		}
		// extend palindrome (and tree) if possible
		while (left >= 0 && right < cn && c[left] == c[right]) {
			if (c[right])
				node[i] = node[i] -> get(c[right]);
			span[i]++;
			left--;
			right++;
		}
		// add longest palindrome to count
		node[i] -> cnt++;
		// check if new index can serve as cache
		if (i + span[i] > radius) {
			center = i;
			radius = i + span[i];
		}
	}

	lag ans = 0;

	while (p--) {
		tree *node = palindromes[p];
		node->parent->cnt += node->cnt;
		ans = max(ans, node->cnt * node->depth);
	}

	return ans;

	// print(&odd); print(&even);

}
