/**
	UVa 11550 - Demanding Dilemma
	by Rico Tiongson
	Submitted: November 2, 2013
	Accepted 0.016s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
int t, n, m;
int cnt[1005];
bool b[1005][1005];
int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		memset( cnt, 0, sizeof cnt );
		memset( cnt2, 0, sizeof cnt2 );
		for( int i=0; i<n; ++i ){
			for( int j=0; j<m; ++j ){
				cin >> b[i][j];
				if( b[i][j] ) cnt[j]++;
			}
		}
		
		bool ok = true;
		for( int j=0; j<m; ++j ){
			if( cnt[j] != 2 ){
				ok = false;
				goto end;
			}
		}
		
		{
			set< pair<int, int> > edges;
			for( int j=0; j<m; ++j ){
				if( cnt[j] == 2 ){
					vector<int> v;
					for( int i=0; i<n; ++i ){
						if( b[i][j] ) v.push_back(i);
					}
					if( !edges.insert( make_pair( v[0], v[1] ) ).second ){
						ok = false;
						goto end;
					}
				}
			}
		}
		end:
		cout << ( ok ? "Yes" : "No" ) << endl;
	}
}
