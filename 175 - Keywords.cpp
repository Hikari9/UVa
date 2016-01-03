// UVa 175 - Keywords
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=111

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <iterator>
#include <algorithm>

using namespace std;

struct keyword {
	int space;
	vector<int> titles;
	map<string, int> words;
	keyword() {cin >> space; ++space;}
};

int tc;
string title, buffer;
vector<keyword> keywords;
vector<string> words;

void normalize(string& s) {
	string buf;
	for (char& c : s) {
		if (isalpha(c) || c == ' ') buf += tolower(c);
	}
	s = buf;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> title, title != "#") {
		if (title[0] == 'P') {
			keywords.push_back(keyword());
			getline(cin, buffer);
			istringstream is(buffer);
			while (is >> buffer)
				++keywords.back().words[buffer];
		} else if (title[0] == 'T') {
			++tc;
			getline(cin, buffer, '|');
			normalize(buffer);
			istringstream is(buffer);
			words.clear();
			while (is >> buffer) words.push_back(buffer);
			for (keyword& k : keywords) {
				for (int i = 0; i < words.size(); ++i) {
					for (int j = 0; j < k.space && i + j + 1 < words.size(); ++j) {
						if ((words[i] == words[i + j + 1] && (k.words.count(words[i]) && k.words[words[i]] > 1)) || (words[i] != words[i + j + 1] && k.words.count(words[i]) && k.words.count(words[i + j + 1]))) {
							k.titles.push_back(tc);
							goto next;
						}
					}
				}
				next:;
			}
		}
	}

	tc = 0;
	for (keyword& k : keywords) {
		cout << ++tc << ": ";
		for (int i : k.titles) {
			if (i != k.titles.front())
				cout << ',';
			cout << i;
		}
		cout << '\n';
	}

	cout << flush;
}