#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;

string s;
set<string> visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> s) {
		if (s == "0")
			break;
		visited.clear();
		cout << "Original number was " << s << endl;
		int length = 0;
		while (true) {
			sort(s.begin(), s.end());
			int small = stoi(s);
			reverse(s.begin(), s.end());
			int big = stoi(s);
			int diff = big - small;
			cout << big << " - " << small << " = " << diff << endl;
			s = to_string(diff);
			length++;
			if (visited.count(s))
				break;
			visited.insert(s);
		}
		cout << "Chain length " << length << endl << endl;
	}
	cout << flush;
}