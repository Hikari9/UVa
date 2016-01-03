/**
	UVa 154 - Recycling
	by Rico Tiongson
	Submitted: July 25, 2013
	Accepted 0.019s C++
	O(4n^2) time
*/
#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define INF 2147483647
using namespace std;
struct change{
	int ID[5];
} C[101];
char in[100005];
int mn, mni, x, y, c, i, j, k, len;
pair<char,int> pr[] = {
	make_pair( 'b', 0 ),
	make_pair( 'g', 1 ),
	make_pair( 'o', 2 ),
	make_pair( 'r', 3 ),
	make_pair( 'y', 4 )
},
pr2[] = {
	make_pair( 'A', 2 ),
	make_pair( 'G', 1 ),
	make_pair( 'N', 4 ),
	make_pair( 'P', 0 ),
	make_pair( 'S', 3 )
};
map<char,int> bin( pr, pr+5 ), typ( pr2, pr2+5 );
int dist( const change& X, const change& Y ){
	y = 0;
	for( k=0; k<5; ++k ){
		y += (X.ID[k]!=Y.ID[k]);
	}
	return y;
}
int main(){
	while( gets( in ), in[0]!='#' ){
		if( in[0]=='e' ){
			cout << "1\n";
			continue;
		}
		c = 0;
		do{
			for( k=0, len=strlen( in ); k<len; k+=4 ){
				C[c].ID[ bin[in[k]] ] = typ[in[k+2]];
			}
			++c;
		} while( gets( in ), in[0]!='e' );
		// count changes
		mn = INF;
		for( i=0; i<c; ++i ){
			x = 0;
			for( j=0; j<c; ++j ){
				x += dist( C[i], C[j] );
			}
			// cout << x << endl;
			if( x < mn ){
				mn = x;
				mni = i;
			}
		}
		cout << mni+1 << endl;
	}
}
