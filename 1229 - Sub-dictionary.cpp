/**
	UVa 1229 - Sub-Dictionary
	by Rico Tiongson
	Submitted: September 19, 2013
	Accepted 0.018s C++
	O(topo) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#define MX 105
using namespace std;

struct cmp{
	bool operator()( const string* const a, const string* const b )const{
		return *a < *b;
	}
};

int n, i, out[MX], topo[MX], co[MX], ID, anc;
bool adj[MX][MX], v[MX];
set<const string*,cmp> ans;
set<const string*,cmp>::iterator it;

map<string,int> M;
map<string,int>::iterator ii;
const string* str[MX];
char a[30], buf[100005], *b;
int aa, bb, c;

bool u[MX];

void topo_dfs( int x ){
	// if( v[x] ) return;
	v[x] = true;
	for( int j=0; j<n; ++j ){
		if( !v[j] && adj[x][j] ) topo_dfs(j);
	}
	topo[ID++] = x;
}

int ancestors( int x ){
	// if( v[x] ) return 0;
	int sum = 1;
	v[x] = true;
	co[x] = c;
	for( int j=0; j<n; ++j ){
		if( !v[j] && adj[j][x]  ){
			sum += ancestors(j);
		}
	}
	return sum;
}

void dfs( int x ){
	// if( v[x] ) return;
	v[x] = true;
	ans.insert( str[x] );
	for( int j=0; j<n; ++j ){
		if( !v[j] && adj[x][j] ) dfs(j);
	}
}

int j;

int main(){
	while( scanf("%d",&n)==1 && n ){
		memset( adj, 0, sizeof adj );
		memset( out, 0, sizeof out );
		M.clear();
		for( i=0; i<n; ++i ){
			scanf( "%s", a );
			gets(buf);
			aa = M.insert( make_pair( a, M.size() ) ).first->second;
			for( b=strtok(buf," "); b; b=strtok(NULL," ") ){
				bb = M.insert( make_pair( b, M.size() ) ).first->second;
				adj[aa][bb] = 1;
				++out[aa];
			}
		}
		// for( i=0; i<n; ++i ) cout << out[i] << endl;
		for( ii=M.begin(); ii!=M.end(); ++ii )
			str[ii->second] = &ii->first;
		memset( v, 0, sizeof v );
		ID = 0;
		for( i=0; i<n; ++i ){
			if( !v[i] ) topo_dfs(i);
		}
		// for( i=0; i<n; ++i ) cout << topo[i] << endl;
		memset( v, 0, sizeof v );
		memset( u, 0, sizeof u );
		memset( co, 0, sizeof co );
		c = 0;
		for( i=n-1; i>=0; --i ){
			if( !v[ topo[i] ] ){
				++c;
				if( out[ topo[i] ]==0 ){
					co[ topo[i] ] = c;
					u[ topo[i] ] = 1;
				}
				else if( ancestors( topo[i] )>1 ){
					for( j=0; j<n; ++j ){
						if( c==co[j] ) u[j] = 1;
					}
				}
			}
		}
		// for( i=0; i<n; ++i ){
			// if( u[i] ) cout << i << endl;
		// }
		ans.clear();
		memset( v, 0, sizeof v );
		for( i=0; i<n; ++i ){
			if( u[i] ) dfs(i);
		}
		printf( "%d\n", ans.size() );
		for( it=ans.begin(); it!=ans.end(); ++it ){
			if( it!=ans.begin() ) putchar(' ');
			cout << **it;
		}
		putchar('\n');
	}
}
