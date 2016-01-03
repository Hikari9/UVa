/**
	UVa 117 - The Postal Worker Rings Once
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.015s C++
	O(n + mlogn) time
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#define INF -1
using namespace std;
struct node{
	int i, w;
	node() {}
	node( int I, int W ): i(I), w(W) {}
	bool operator<( const node& _ )const{
		return _.w < w;
	}
} E;
int n, m, a, b, i, j, sum;
unsigned deg[205];
bool v[26];
vector<unsigned> adj[26][26];
map<char,int> id;
string s;
int dijkstra(){
	// pick only minimum from adj matrix
	n = id.size();
	for( i=0; i<n; ++i ){
		for( j=0; j<n; ++j ){
			if( !adj[i][j].empty() ){
				swap( adj[i][j][0], *min_element( adj[i][j].begin(), adj[i][j].end() ) );
				adj[i][j].resize(1);
			}
		}
	}
	priority_queue<node> pq;
	memset( deg, INF, sizeof deg );
	memset( v, 0, sizeof v );
	deg[a] = 0;
	pq.push( node(a,0) );
	while( !pq.empty() ){
		E = pq.top();
		pq.pop();
		if( v[E.i] ) continue;
		if( E.i==b ) return E.w;
		v[E.i] = true;
		for( i=0; i<id.size(); ++i ){
			if( !adj[E.i][i].empty() && !v[i] && E.w + adj[E.i][i][0] < deg[i] ){
				deg[i] = E.w + adj[E.i][i][0];
				pq.push( node(i,deg[i]) );
			}
		}
	}
	return 0;
}
int main(){
	while( cin >> s ){
		if( s=="deadend" ){
			cout << "0\n";
			continue;
		}
		id.clear();
		for( i=0; i<26; ++i ){
			for( j=0; j<26; ++j ){
				adj[i][j].clear();
			}
		}
		memset( deg, 0, sizeof deg );
		sum = 0;
		do{
			a = id.insert( make_pair( s[0], id.size() ) ).first->second;
			b = id.insert( make_pair( s[s.size()-1], id.size() ) ).first->second;
			adj[a][b].push_back(s.size());
			adj[b][a].push_back(s.size());
			++deg[a], ++deg[b], ++m, sum += s.size();
		} while( cin >> s, s!="deadend" );
		a = b = -1;
		for( i=0; i<m; ++i ){
			if( deg[i] & 1 ){
				if( a==-1 ) a = i;
				else{
					b = i;
					break;
				}
			}
		}
		if( a==-1 )
			cout << sum << endl;
		else
			cout << sum + dijkstra() << endl;

	}
}
