/**
	UVa 12527 - Different Digits
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.012s C++
	O(nlog(10)n) pregen + O(1) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int rep[5001], i;
bool used[10];
bool repeating( int x ){
	memset(used,0,sizeof used);
	while( x ){
		if( used[x%10] ) return false;
		used[x%10] = true;
		x/=10;
	}
	return true;
}
int main(){
	for( i=0; i<5001; ++i ){
		rep[i] = repeating(i);
	}
	for( i=1; i<5001; ++i ){
		rep[i] += rep[i-1];
	}
	int a, b;
	while( cin >> a >> b ){
		cout << rep[b] - rep[a-1] << endl;
	}
}
