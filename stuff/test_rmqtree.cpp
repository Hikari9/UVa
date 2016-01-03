/***************************************************************************
 *   Copyright (C) 2007 by Joao Carreira
 *
 *  This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

/*
 * Range Minimum/Maximum query search using a tree
 * O(n) construction, O(logn) query
 */


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

    void init(int node, int beg, int end, vector<int>& M, vector<int>& m, const vector<int>& n){
	if (beg == end)
	    M[node] = m[node] = n[beg];
	else {
	    init(node * 2, beg, (beg + end) / 2, M, m, n);
	    init(node * 2 + 1,(beg + end) / 2 + 1, end, M, m, n);
	    M[node] = max(M[2 * node], M[2 * node + 1]);
	    m[node] = min(m[2 * node], m[2 * node + 1]);
	}
    }

pair<int,int> query(int node, int beg, int end, vector<int>& M, vector<int>& m, vector<int>& n, int i, int j) {
    pair<int,int> p1, p2;

    if (end < i || beg > j)
	return make_pair(-1, -1);

    if (beg >= i && end <= j)
	return make_pair(M[node], m[node]);

    p1 = query(2 * node, beg, (beg + end) / 2, M, m, n, i, j);
    p2 = query(2 * node + 1, (beg + end) / 2 + 1, end, M, m, n, i, j);

    if (p1 == make_pair(-1, -1))
	return p2;

    if (p2 == make_pair(-1, -1))
	return p1;

    pair<int,int> res = make_pair(max(max(0, p1.first), max(0, p2.first)), min(max(0, p1.second), max(0, p2.second)));
    return res;
}


int main(){
    /* number of elements in the sequence */
    int N;

    /* number of queries */
    int  Q;

    cout << "Insert the number of values in the sequence: ";
    cin >> N;
    cout << "Insert the number of queries: ";
    cin >> Q;
    vector<int> n(N), m(4 * N), M(4 * N);

    cout << "Insert " << N << " values:  " << endl;
    for (int i = 0; i < N; i++)
	cin >> n[i];

    init(1, 0, N - 1, M, m, n);

    cout << "Insert " << Q << " queries (one based interval):" << endl;
    for (int k = 0; k < Q; k++) {
	int i, j;
	cin >> i >> j;
	i--; j--;
	pair<int,int> res = query(1, 0, N - 1, M, m, n, i, j);
	cout << "max: " << res.first <<  "  min: " << res.second << endl << endl;
    }
    return 0;
}
