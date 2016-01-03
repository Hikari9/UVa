/**
	UVa 1210 - Sum of Consecutive Prime Numbers
	by Rico Tiongson
	Submitted: July 30, 2013
	Accepted 0.022s C++
	O(nloglogn + n^2) pregen + O(1) time
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> pr;
int i, j, lim, ans[10001], sum;
void addprime( int x ){
	lim = sqrt( x ) + 1;
	for( j=1; pr[j] < lim; ++j ){
		if( x%pr[j]==0 ) return;
	}
	pr.push_back( x );
}
int main(){
	pr.push_back( 2 );
	pr.push_back( 3 );
	for( i=5; i<10000; i+=4 ){
		addprime( i );
		if( (i+=2) < 10000 )
			addprime( i );
	}
	for( i=0; i<pr.size(); ++i ){
		sum = 0;
		for( j=i; j<pr.size(); ++j ){
			sum += pr[j];
			if( sum >10000 ) break;
			++ans[sum];
		}
	}
	while( cin >> i, i ){
		cout << ans[i] << endl;
	}
}
