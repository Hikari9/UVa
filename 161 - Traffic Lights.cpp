/**
	UVa 161 - Traffic Lights
	by Rico Tiongson
	Submitted: July 25, 2013
	Accepted 0.022s C++
	O(18000n) time
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char buf[105];
int x, i, j, k;
vector<vector<int> > v(1);
bool h[18001];
int main(){
	while( gets( buf ), strcmp( buf, "0 0 0" ) ){
		istringstream in( buf );
		while( in >> x ){
			if( x ) v.back().push_back( x );
			else v.push_back( vector<int>() );
		}
	}
	v.pop_back();
	// read vector input
	for( i=0; i<v.size(); ++i ){
		memset( h, 1, sizeof h );
		x = 18001; // min orange
		for( j=0; j<v[i].size(); ++j ){
			x = min( v[i][j], x );
			// simulate
			// cout << v[i][j]-5+v[i][j] << endl;
			for( k=v[i][j]-5; k<18001; k+=2*v[i][j] ){
				// cout << k << ' ' << k+v[i][j]+5 << endl;
				fill( h+k, h+min( k+v[i][j]+5, 18001 ), false );
			}
		}
		for( j=x; j<18001; ++j ){
			if( h[j] ) goto found;
		}
		puts("Signals fail to synchronise in 5 hours");
		continue;
		found: printf("%02d:%02d:%02d\n", j/3600, (j/60)%60, j%60);
	}
}
