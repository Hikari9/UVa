#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct state {
	char c[3][3];
	unsigned long long h; int prevMove;
	state *prev;
	state() {
		prevMove = -1;
		prev = NULL;
		h = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				c[i][j] = i * 3 + j;
			}
		}
		recomputeHash();
	}
	state(state* s, int move) {
		memcpy(c, s->c, sizeof c);
		prev = s;
		prevMove = move;
		h = s->h;
	}
	bool operator < (const state& s) const {
		return h < s.h;
	}
	friend istream& operator >> (istream& in, state& s) {
		s.h = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				in >> s.c[i][j];
				if (s.c[i][j] != 'x') {
					s.c[i][j] -= '1';
				}
				else {
					s.c[i][j] = 8;
				}
			}
		}
		s.recomputeHash();
	}
	int find() const {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (c[i][j] == 8)
					return i * 3 + j;
			}
		}
	}
	void recomputeHash() {
		h = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				h = (9 * h) + c[i][j];
			}
		}
	}
	bool valid() const {
		char test[9];
		memset(test, 0, sizeof test);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (c[i][j] < 0 || c[i][j] > 8) return false;
				if (++test[c[i][j]] != 1) return false;
			}
		}
		return true;
	}
	friend ostream& operator << (ostream& out, const state& s) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (s.c[i][j] == 8) out << 'x';
				else out << (char) (s.c[i][j] + '1');
			}
			out << endl;
		}
		return out;
	}
} initial, final;

int t;
char c;
map<unsigned long long, state*> visited;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char move[] = "uldr";

void bfs(state* root) {
	queue<state*> q;
	q.push(root);
	visited[root->h] = root;
	while (!q.empty()) {
		state *s = q.front(); q.pop();
		int pos = s->find();
		int i = pos / 3;
		int j = pos % 3;
		// swap with all positions
		for (int k = 3; k >= 0; --k) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
				state *next = new state(s, k);
				swap(next->c[i][j], next->c[nx][ny]);
				next->recomputeHash();
				if (visited.count(next->h)) continue;
				visited[next->h] = next;
				q.push(next);
			}
		}
	}
	
}


int main() {
	// spread from final
	bfs(&final);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> initial;
		if (initial.valid() && visited.count(initial.h)) {
			state *s = visited[initial.h];
			while (s->prev) {
				// cout << endl << *s << endl;
				cout << move[s->prevMove];
				s = s->prev;
			}
			cout << '\n';
		}
		else {
			cout << "unsolvable\n";
		}
		if (t) cout << '\n';
	}
	cout << flush;
}