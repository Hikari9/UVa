#include <iostream>
#include <cstring>
#define MX 300005

using namespace std;

struct tree {
	tree *next[26], *suffix;
	long long count;
	int length;
	tree(int L, tree *S = NULL): length(L), count(0), suffix(S ? S : this) {
		for (int i = 0; i < 26; ++i) next[i] = NULL;
	}
};

tree *nodes[MX];
char _s[MX];
char *s = _s + 1;
int n;

#define reduce(x) \
	while (s[i - x->length - 1] != s[i]) \
		x = x->suffix;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	s[-1] = 26;
	tree *root = new tree(0, new tree(-1));
	tree *node = root;
	int c = 0;
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		s[i] -= 'a';
		reduce(node);
		if (node -> next[s[i]] == NULL) {
			tree *suffix;
			if (node -> length != -1) {
				suffix = node -> suffix;
				reduce(suffix);
				suffix = suffix -> next[s[i]];
			}
			else {
				suffix = root;
			}
			nodes[c++] = node -> next[s[i]] = new tree(node->length + 2, suffix);
		}
		node = node -> next[s[i]];
		node->count++;
	}
	long long ans = 0;
	while (c--) {
		tree *node = nodes[c];
		long long count = node -> count;
		node->suffix->count += count;
		ans = max(ans, count * node->length);
		// ans = mod(ans + mod(count * (count - 1) / 2));
	}
	cout << ans << endl;
}