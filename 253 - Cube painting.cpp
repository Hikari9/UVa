/**
	UVa 253 - Cube painting
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.016s C++
	O(24) time
*/
#include<iostream>
using namespace std;

string in, a, b, c;

int n[24][3] = {
	1, 2, 3,
	1, 3, 5,
	1, 5, 4,
	1, 4, 2,
	2, 3, 1,
	2, 1, 4,
	2, 4, 6,
	2, 6, 3,
	3, 2, 6,
	3, 6, 5,
	3, 5, 1,
	3, 1, 2,
	4, 2, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 2,
	5, 4, 1,
	5, 1, 3,
	5, 3, 6,
	5, 6, 4,
	6, 2, 4,
	6, 4, 5,
	6, 5, 3,
	6, 3, 2
};

int main(){
	c.resize(6);
	while( cin >> in ){
		a = in.substr(0, 6);
		b = in.substr(6);
		bool yes = false;
		for( int i=0; i<24; ++i ){
			for( int j=0; j<3; ++j ){
				c[j] = b[ n[i][j] - 1 ];
			}
			for( int j=0; j<3; ++j ){
				c[j+3] = b[ 7-n[i][3-j-1]-1 ];
			}
			if( a == c ){
				yes = true;
				break;
			}
		}
		cout << ( yes ? "TRUE" : "FALSE" ) << endl;
	}
}
