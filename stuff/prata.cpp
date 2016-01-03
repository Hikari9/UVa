#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct cook {
	long long time;
	int rank, evolution;
	cook(): time(0) {}
	cook(long long time, int rank, int evolution):
		time(time),
		rank(rank),
		evolution(evolution) {}
	bool operator < (const cook& c) const {
		return time > c.time;
	}
	cook next() const {
		return cook(time + rank * (evolution + 1), rank, evolution + 1);
	}
};

int t, prata, n, R;
priority_queue<cook> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> prata >> n;
		pq = priority_queue<cook>();
		for (int i = 0; i < n; ++i) {
			cin >> R;
			pq.push(cook(R, R, 1));
		}
		int cooked = 0;
		cook last;
		while (cooked < prata) {
			last = pq.top(); pq.pop();
			++cooked;
			pq.push(last.next());
		}
		cout << last.time << '\n';
	}
	cout << flush;
}