/**
	UVa 155 - All Squares
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.018s C++
	O(logn) time
*/
#include <iostream>
using namespace std;

int abs( int x ){ return x < 0 ? -x : x; }
int k, x, y, c;

int main(){
	while( cin >> k >> x >> y, k || x || y ){
		c = 0;
		for( int cx=1024, cy=1024; k>0; k >>= 1 ){
			int dx = x - cx;
			int dy = y - cy;
			if( max( abs(dx), abs(dy) ) <= k ){
				c++;
			}
			if( dx * dy == 0 ) break;
			dx /= abs(dx);
			dy /= abs(dy);
			cx += dx * k;
			cy += dy * k;
		}
		cout.width(3);
		cout << right << c << endl;
	}
}
