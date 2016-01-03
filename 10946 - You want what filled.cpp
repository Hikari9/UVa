/**
	UVa 10946 - You want what filled?
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.039s C++
	O(n^2) time
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector< pair<char,int> > ans;
int n, m, i, j, cnt, tc;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
char c[505][505], C;
string str;
inline bool cmp( const pair<char,int>& a, const pair<char,int>& b ){
	if( a.second==b.second ) return a.first < b.first;
	return a.second > b.second;
}
inline bool inRange( int x, int y ){
	return x>=0 && x<n && y>=0 && y<m;
}
void dfs( int x, int y ){
	if(!inRange(x,y)) return;
	if(c[x][y]!=C) return;
	c[x][y] = '.';
	++cnt;
	for( int k=0; k<4; ++k ) dfs( x+dx[k], y+dy[k] );
}
int main(){
	while( cin >> n >> m, n||m ){
		ans.clear();
		cin.ignore();
		for( i=0; i<n; ++i ){
			cin.getline( c[i], 505 );
		}
		for( i=0; i<n; ++i ){
			for( j=0; j<m; ++j ){
				if( c[i][j]!='.' ){
					cnt = 0;
					C = c[i][j];
					dfs(i,j);
					ans.push_back( make_pair(C,cnt) );
				}
			}
		}
		// for( i=0; i<n; ++i ){
			// cout << c[i] << endl;
		// }
		cout << "Problem " << ++tc << ":" << endl;
		sort( ans.begin(), ans.end(), cmp );
		for( i=0; i<ans.size(); ++i ){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}
