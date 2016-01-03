#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct State {
	int length, link, endPos;
	map<int, int> next;
	vector<int> ilink;
};

State *buildSuffixAutomaton(string s) {
	int n = s.length();
	int root = -1;
	vector<State> st;
	st.reserve(max(2, 2 * n - 1));
	st.push_back(State());
	st[0].link = st[0].endpos = root;
	int last = 0;
	int size = 1;
	for (int i = 0; i < s.length(); i++) {
		st.push_back(State());
		State& cur = st.back();
		cur.length = st[last].length + 1;
		cur.endpos = st[last].length;
		int p = last;
		while (p != root && st[p].next.count(c) == 0) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == root)
			cur.link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].length + 1 == st[q].length)
				cur.link = q;
			else {
				st.push_back(State());
				State& clone = st.back();
				clone.length = st[p].length + 1;
				clone.next = st[q].next;
				clone.link = st[q].link;
				while (p != root && st[p].next[c] == q) {
					st[p].next[c] = st.size() - 1;
					p = st[p].link;
				}
				cur.link = st[q].link = st.size() - 1;
				clone.endpos = -1;
			}
		}
		last = cur;
	}
	for (int  = 1; i < st.size(); ++i) {
		st[st[i].link].ilink.add(i);
	}
}

int main() {
	
}