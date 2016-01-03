/**
	UVa 11080 - Place the Guards
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.029s C++
	O(bfs) time
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
bool adj[205][205];
int t, v, e, a, b, i, j, c[2];
queue<int> q;
map<int,bool> m; // colorer
map<int,bool>::iterator it, itc;
int bi(){
	q = queue<int>();
	m[i] = false;
	q.push( i );
	c[false] = 1;
	c[true] = 0;
	while( !q.empty() ){
		itc = m.find( q.front() );
		for( j=0; j<v; ++j ){
			if( adj[q.front()][j] ){
				it = m.find( j );
				if( it!=m.end() ){
					if( it->second==itc->second ) return -1; // conflict
				}
				else{
					m[j] = !itc->second; // bicolor
					++ c[!itc->second];
					q.push(j);
				}
			}
		}
		q.pop();
	}
	return max( min( c[0],c[1] ), 1 );
}
int main(){
	cin >> t;
	while( t-- ){
		memset( adj, 0, sizeof adj );
		cin >> v >> e;
		m.clear();
		while( e-- ){
			cin >> a >> b;
			adj[a][b] = adj[b][a] = true;
		}
		a = 0;
		for( i=0; i<v; ++i ){
			if( m.count(i)==0 ){
				b = bi();
				if( b==-1 ) goto notfound;
				else a += b;
			}
		}
		cout << a << '\n';
		continue;
		notfound: cout << "-1\n";
	}
}
