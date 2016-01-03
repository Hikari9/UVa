/**
	UVa 10703 - Free spots
	by Rico Tiongson
	Submitted: October 27, 2013
	Accepted 0.022s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
using namespace std;

int w, h, n;
int x1, y1, x2, y2;

bool board[505][505];

int main(){
	while( cin >> w >> h >> n, w || h || n ){
		memset( board, 0, sizeof board );
		int ans = w * h;
		while(n--){
			cin >> x1 >> y1 >> x2 >> y2;
			if( x1 > x2 ) swap( x1, x2 );
			if( y1 > y2 ) swap( y1, y2 );
			for( int i=x1; i<=x2; ++i ){
				for( int j=y1; j<=y2; ++j ){
					if( !board[i][j] ){
						board[i][j] = true;
						--ans;
					}
				}
			}
		}
		if( ans == 0 ) cout << "There is no empty spots." << endl;
		else if( ans == 1 ) cout << "There is one empty spot." << endl;
		else cout << "There are " << ans << " empty spots." << endl;
	}
}
