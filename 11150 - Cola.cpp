/**
	UVa 11150 - Cola
	by Rico Tiongson
	Submitted: July 25, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int n, i, mx;
int cola( int full, int empty ){
	if( full+empty<3 ){
		if( full+empty>=i ) return full;
		return -2000000000;
	}
	return cola( (full+empty)/3, (full+empty)%3 ) + full;
}
int main(){
	while( cin >> n ){
		i = 0;
		mx = cola(n,0);
		for( i = 3-n%3; i; --i ){
			mx = max( mx, cola(n,i) );
		}
		cout << mx << endl;
	}
}
