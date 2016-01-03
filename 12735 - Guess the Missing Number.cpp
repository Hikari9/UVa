#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int t, n;
int mask[1001];
map<int, int> ask;
map<int, int> candidates;

void eraser(map<int, int>& m, bool idToRemove) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ) {
		if (it->second == idToRemove) {
			m.erase(it++);
		}
		else it++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		ask.clear();
		candidates.clear();
		for (int i = 1; i < n; ++i) {
			ask[i] = 0;
			candidates[i] = 1;
		}
		candidates[n] = 1;
		int bit = 0;
		while (candidates.size() > 1) {

			int expected[2] = {0, 0};
			for (auto& it : candidates) {
				int a = it.first & (1 << bit);
				it.second = (a != 0);
				expected[it.second]++;
			}
			int count[2] = {0, 0};
			for (auto& it : ask) {
				cout << "Ask " << it.first << " " << bit << endl;
				cin >> it.second;
				count[it.second]++;
			}
			bool idToRemove = (expected[1] == count[1]);
			eraser(candidates, idToRemove);
			eraser(ask, idToRemove);
			bit++;
		}
		cout << "Answer " << candidates.begin()->first << endl;
	}
}