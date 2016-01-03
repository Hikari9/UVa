/**
	UVa 11244 - Counting Stars
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.039s C++
	O(8n^2) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int r, c, i, j, k, stars, dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1};
char s[110][110];
int main(){
	// cout << *s << endl;
	while( cin >> r >> c, r||c ){
		memset( s, '.', sizeof s );
		for( i=1; i<=r; ++i ){
			cin >> (s[i]+1);
		}
		stars = 0;
		for( i=1; i<=r; ++i ){
			for( j=1; j<=c; ++j ){
				if( s[i][j]=='*' ){
					// cout << i << ' ' << j << endl;
					for( k=0; k<8; ++k ){
						if( s[i+dx[k]][j+dy[k]]=='*' ) break;
					}
					if( k==8 ) ++stars;
				}
			}
		}
		cout << stars << endl;
	}
}
