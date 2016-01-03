/**
	UVa 834 - Continued Fractions
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.015s C++
	O(gcd) time
*/
#include<iostream>
using namespace std;
char c;
void dfs( int n, int d ){
	if( !d ) return;
	cout << c << n/d;
	c = ',';
	dfs( d, n%d );
}
int main(){
	int a, b;
	while( cin >> a >> b ){
		cout << "[" << a/b;
		c = ';';
		dfs( b, a%b );
		cout << "]\n";
	}
}
