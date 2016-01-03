/**
	UVa 11157 - Dynamic Frog
	by Rico Tiongson
	Submitted: Feb 17, 2014
	Accepted 0.026s C++
	BS + AP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n, d;
int pos[105];
bool small[105];
int id[105], low[105], ID;
bool ok;

void dfs( int jump, int parent, int u ){
	// cout << "STACK: " << parent << " -> " << u << endl;
	id[u] = low[u] = ID++;
	int children = 0;
	// cout << "FLAG1: " << parent << " -> " << u << endl;
	for( int i=u-1; i>=0 && pos[u] - pos[i] <= jump; --i ){
		if( id[i] == -1 ){
			dfs(jump, u, i);
			if( !ok ) return;
			children++;
			low[u] = min( low[u], low[i] );
			if( parent != u && id[u] <= low[i] ){
				if( small[u] ){
					ok = false;
					return;
				}
			}
				
		}
		else if( parent != i ){
			low[u] = min( low[u], id[i] );
		}
	}
	// cout << "FLAG2: " << parent << " -> " << u << endl;
	// cout << id[n-1] << endl;
	for( int i=u+1; i<n && pos[i] - pos[u] <= jump; ++i ){
		if( id[i] == -1 ){
			// cout << i << ": JUMPED" << endl;
			dfs(jump, u, i);
			// cout << i << ": END JUMP" << endl;
			if( !ok ) return;
			children++;
			low[u] = min( low[u], low[i] );
			if( parent != u && id[u] <= low[i] ){
				if( small[u] ){
					ok = false;
					return;
				}
			}
				
		}
		else if( parent != i ){
			low[u] = min( low[u], id[i] );
		}
	}
	// cout << "FLAG3: " << parent << " -> " << u << endl;
	if( parent == u && children <= 2 ){
		if( small[u] ){
			ok = false;
			return;
		}
	}
}

bool possible( int jump ){
	memset( id, -1, sizeof id );
	ID = 0;
	ok = true;
	
	dfs( jump, 0, 0 );
	// cout << jump << " " << ID << " " << ok << endl;
	if( ID < n ) return false;
	// for( int i=0; i<n; ++i ){
		// if( id[i] == -1 ) return false;
	// }
	return ok;
}

int main(){
	pos[0] = 0;
	small[0] = false;
	int t;
	char buf[10];
	// cin >> t;
	scanf( "%d", &t );
	for( int cases=1; cases<=t; ++cases ){
		// cin >> n >> d;
		scanf( "%d %d", &n, &d );
		for( int i=1; i<=n; ++i ){
			
			scanf( "%s", buf );
			char c;
			sscanf( buf, "%c-%d", &c, pos + i );
			// cin >> c;
			small[i] = (c=='S');
			// cin.get();
			// cin >> pos[i];
		}
		small[++n] = false;
		pos[n++] = d;
		int L = 1, R = d;
		while( L < R ){
			int M = (L+R) >> 1;
			if( !possible(M) ){
				L = M+1;
			}
			else{
				R = M;
			}
		}
		printf( "Case %d: %d\n", cases, L );
		// cout << "Case " << cases << ": " << L << endl;
	}
}
