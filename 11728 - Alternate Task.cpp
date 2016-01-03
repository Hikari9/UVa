/**
	UVa 11728 - Alternate Task
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.016s C++
	O(nsqrtn) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int ans[1001], tc;
int sumOfFactors( int x ){
	int sum = 0, i;
	for( i=1; i * i < x; ++i ){
		if( x % i == 0 ){
			sum += i + x / i;
		}
	}
	if( i * i == x )
		sum += i;
	return sum;
}
int main(){
	memset( ans, -1, sizeof ans );
	for( int i=1; i<1001; ++i ){
		int sum = sumOfFactors(i);
		if( sum < 1001 ) ans[sum] = i;
	}
	int x;
	while( cin >> x && x ){
		cout << "Case " << ++tc << ": " << ans[x] << endl;
	}
}
