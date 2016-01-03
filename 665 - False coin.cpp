/**
	UVa 665 - False coin
	by Rico Tiongson
	Submitted: October 27, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int m, n, k, p;
bool no[101], l[101], g[101];
int a[101], b[101];
char c;
int main(){
	cin >> m;
	bool first = true;
	done:
	while(m--){
		if( first ) first = false;
		else cout << endl;
		cin >> n >> k;
		memset( no, 0, sizeof no );
		memset( l, 0, sizeof l );
		memset( g, 0, sizeof g );
		while(k--){
			cin >> p;
			for( int i=0; i<p; ++i ){
				cin >> a[i];
			}
			for( int i=0; i<p; ++i ){
				cin >> b[i];
			}
			cin >> c;
			switch(c){
				case '<':
					for( int i=0; i<p; ++i ){
						l[a[i]] = true;
						g[b[i]] = true;
					}
					break;
				case '>':
					for( int i=0; i<p; ++i ){
						l[b[i]] = true;
						g[a[i]] = true;
					}
					break;
				case '=':
					for( int i=0; i<p; ++i ){
						no[a[i]] = true;
						no[b[i]] = true;
					}
			}
		}
		int noes = 0, ls = 0, gs = 0;
		for( int i=1; i<=n; ++i ){
			if( no[i] ){
				++noes;
				l[i] = g[i] = false;
			}
		}
		
		for( int i=1; i<=n; ++i ){
			l[i] = g[i] = ( l[i] ^ g[i] );
		}
		int found = -1;
		for( int i=1; i<=n; ++i ){
			if( l[i] ){
				if( found != -1 ){
					++ls;
					found = -1;
					break;
				}
				found = i;
			}
		}
		if( found != -1 ){
			cout << found << endl;
			continue;
		}
		found = -1;
		for( int i=1; i<=n; ++i ){
			if( g[i] ){
				if( found != -1 ){
					++gs;
					found = -1;
					break;
				}
				found = i;
			}
		}
		if( found != -1 )
			cout << found << endl;
		else{
			if( noes == n - 1 ){
				for( int i=1; i<=n; ++i ){
					if( !no[i] ){
						cout << i << endl;
						goto done;
					}
				}
			}
			else cout << "0" << endl;
		}
		
	}
}
