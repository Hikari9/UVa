/**
	UVa 388  - Galactic Import
	by Rico Tiongson
	Submitted: October 17, 2013
	Accepted 0.019s C++
	O(|V| + E) time
*/
#include<iostream>
#include<queue>
#define INF 2000000000

using namespace std;
typedef pair<int, int> edge;

int n;
int path[27];
double val[27];
bool adj[27][27];

char bfs(){
	queue<edge> q;
	path[26] = 0;
	q.push( edge(26, 0) );
	while( !q.empty() ){
		edge E = q.front(); q.pop();
		for( int i=0; i<26; ++i ){
			if( adj[E.first][i] && E.second + 1 < path[i] ){
				path[i] = E.second + 1;
				q.push( edge(i, E.second + 1) );
			}
		}
	}
	double mx = 0.0;
	int mxi = 0;
	for( int i=0; i<26; ++i ){
		double d = val[i] - ( val[i] * 0.05 * ( path[i] - 1 ) );
		if( d > mx ){
			mx = d;
			mxi = i;
		}
	}
	return mxi + 'A';
}

int main(){
	char c;
	string s;
	while( cin >> n ){
		for( int i=0; i<27; ++i ){
			path[i] = INF;
			val[i] = 0.0;
			for( int j=0; j<27; ++j ){
				adj[i][j] = 0;
			}
		}
		for( int i=0; i<n; ++i ){
			cin >> c;
			c -= 'A';
			cin >> val[c];
			val[c] *= 100.0;
			cin >> s;
			for( int j=0; j<s.length(); ++j ){
				if( s[j] == '*' )
					adj[c][26] = adj[26][c] = 1;
				else
					adj[c][s[j]-'A'] = adj[s[j]-'A'][c] = 1;
			}
		}
		cout << "Import from " << bfs() << endl;
	}
}
