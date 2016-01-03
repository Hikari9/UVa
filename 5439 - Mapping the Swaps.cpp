/**
	ACM 5439 - Mapping the Swaps
	by Rico Tiongson
	Submitted: July 24, 2013
	Accepted 0.359s C++
	O(n^2) time
*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef vector<int> state;
int n, i, j, mn, sw;
state v, r;
// set<state> s;
ostream& print(const state& _ ){
	for( int k=0; k<_.size(); ++k ){
		cout << _[k] << ' ';
	}
	return cout;
}
int bfs(){
	queue<pair<state,int> > q;
	q.push( make_pair(v,0) );
	// s.clear(); // visited
	// s.insert( v );
	sw = 0;
	mn = -1;
	while( !q.empty() ){
		if( mn!=-1 && q.front().second==mn ){
			q.pop();
			continue;
		}
		// print(q.front().first) << ' ' << q.front().second << endl;
		++q.front().second;
		for( i=1; i<n; ++i ){
			// make state
			swap( q.front().first[i], q.front().first[i-1] );
			// print(q.front().first) << ' ' << q.front().second << endl;
			if( q.front().first==r ){
				if( mn==-1 )
					mn = q.front().second;
				if( q.front().second==mn )
					++sw;
			}
			// else if( s.insert( q.front().first ).second ){
				// not visited
			if( mn==-1 ){
				q.push( q.front() );
			}
			// }
			swap( q.front().first[i], q.front().first[i-1] );
		}
		q.pop();
	}
	return sw;
}
int main(){
	int tc = 0;
	while( cin >> n, n ){
		v.resize( n );
		for( i=0; i<n; ++i ) cin >> v[i];
		r = v;
		sort( r.begin(), r.end() );
		if( r==v ){
			cout << "There are 0 swap maps for input data set " << ++tc << '.' << endl;
		}
		else
		// mn = 0;
		// for( i=0; i<n; ++i ){
			// for( j=i+1; j<n; ++j ){
				// if( r[i] > r[j] ){
					// swap( r[i], r[j] );
					// ++mn;
				// }
			// }
		// }
		// cout << mn << endl;
		cout << "There are " << bfs() << " swap maps for input data set " << ++tc << '.' << endl;
	}
}
