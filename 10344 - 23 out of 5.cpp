/**
	UVa 10344 - 23 out of 5
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.548s C++
	O(n!3^n) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, pi[5];
bool breaker;
bool input(){
	for( i=0; i<5; ++i ){
		cin >> pi[i];
	}
	for( i=0; i<5; ++i ){
		if( pi[i] ) return true;
	}
	return false;
}
bool dfs( int x, long long ans ){
	if( x==5 ){
		// evaluate
		// cout << " = " << ans << endl;
		if( ans==23 ) return true;
		return false;
	}
	if( dfs( x+1, ans+pi[x] ) ) return true;
	if( dfs( x+1, ans-pi[x] ) ) return true;
	if( dfs( x+1, ans*pi[x] ) ) return true;
	// if( dfs( x+1, ans*-pi[x] ) ) return true;
	return false;
}
int main(){
	while( input() ){
		sort( pi, pi+5 );
		breaker = false;
		do{ 
			if( dfs( 1, pi[0] ) ){
				cout << "Possible\n";
				breaker = true;
				break;
			}
		} while( next_permutation( pi, pi+5 ) );
		if( !breaker ) cout << "Impossible\n";
	}
}
