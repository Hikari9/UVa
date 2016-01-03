/**
	UVa 679 - Dropping Balls
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.382s C++
	O(logn) time
*/
#include<iostream>
using namespace std;
int t, d, i, mask, id, off;
int main(){
	cin >> t;
	while( t-- ){
		cin >> d >> i;
		mask = (1<<d);
		for( id=1, off=i; (id<<1)+1 < mask; ){
			if( off&1 ){
				// pick left
				id <<= 1;
				off = (off>>1) + 1;
			}
			else{
				// pick right
				id = (id<<1) + 1;
				off >>= 1;
			}
		}
		cout << id << endl;
	}
}
