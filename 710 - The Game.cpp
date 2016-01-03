#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;
#define endl '\n'

int n, m, a, b, c, d, tc, q;
char board[100][100];
char s[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inRange(int x, int y) {
	return x >= 0 && x <= n && y >= 0 && y <= m;
}

struct node {
	int x, y, dir, depth;
	node(int X, int Y, int D, int Dep):
		x(X), y(Y), dir(D), depth(Dep) {}
};

int bfs() {
	// add first segments to queue
	deque<node> q;
	memset(board, 0, sizeof board);
	for (int k = 0; k < 4; ++k) {
		int nx = a + dx[k];
		int ny = b + dy[k];
		if (inRange(nx, ny))
			q.push_back(node(nx, ny, k, 1));
	}
	while (!q.empty()) {
		node n = q.front(); q.pop_front();
		if (n.x == c && n.y == d)
			return n.depth;
		if (board[n.x][n.y] || s[n.x][n.y] == 'X')
			continue;
		board[n.x][n.y] = 1;
		// turn left, right, or straight
		for (int i = -1; i < 2; ++i) {
			int k = (n.dir + i + 4) % 4;
			int nx = n.x + dx[k];
			int ny = n.y + dy[k];
			if (!inRange(nx, ny) || board[nx][ny])
				continue;
			if (k == n.dir) {
				// straight
				q.push_front(node(nx, ny, k, n.depth));
			}
			else {
				q.push_back(node(nx, ny, k, n.depth + 1))
			}
		}
	}
	return -1; // not found
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		cin.getline(board[0], 100);
		for (int i = 0; i < m; ++i)
			cin.getline(board[i], 100);
		// update board based on input
		memset(s, ' ', sizeof s);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				s[i + 1][j + 1] = board[j][i];
			}
		}
		// extend borders
		++n, ++m;
		// proceed with queries
		cout << "Board #" << ++tc << ":" << endl;
		q = 0;
		while (cin >> a >> b >> c >> d, a || b || c || d) {
			cout << "Pair " << ++q << ": ";
			int ans = bfs();
			if (ans == -1)
				cout << "impossible." << endl;
			else
				cout << ans << " segments." << endl;
		}
		cout << endl;
	}

	cout << flush;
}