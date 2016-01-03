/**
	UVa 10920 - Spiral Tap
	by Rico Tiongson
	Submitted: 0.042s C++
	O(0.5sqrtnlogn) time
*/
#include <iostream>
#include <algorithm>
#define MX 100001
using namespace std;
typedef long long lag;
lag P, sq[MX];
int SZ;
int main(){
	for( lag i=0; i<MX; ++i )
		sq[i] = (2*i+1)*(2*i+1);
	while( cin >> SZ >> P, SZ || P ){
		if( P == 1 ){
			int x = (SZ+1)/2;
			cout << "Line = " << x << ", column = " << x << "." << endl;
			continue;
		}
		int l = lower_bound( sq, sq+MX, P ) - sq;
		int x = (SZ+1)/2 + l, y;
		lag d = (sq[l] - sq[l-1])/4;
		lag diff = sq[l] - P;
		if( diff < d ){
			// right
			y = x;
			x -= diff;
		}
		else if( diff < 2*d ){
			// down
			y = x;
			x -= 2*l;
			y -= diff - d;
		}
		else if( diff < 3*d ){
			// left
			y = x - 2*l;
			x -= 2*l;
			x += diff % d;
		}
		else{
			// up
			y = x - 2*l;
			y += diff % d;
		}
		cout << "Line = " << x << ", column = " << y << "." << endl;
	}
}
