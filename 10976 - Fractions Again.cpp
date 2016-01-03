/**
	UVa 10976 - Fractions Again?!
	by Rico Tiongson
	Accepted 0.036s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c;
long long n, n2, x, y;
char buf[10], ans[1024];
string sb;
int main(){
	while( gets( buf ) ){
		sscanf( buf, "%lld", &n );
		c = 0;
		sb.clear();
		for( x=n+1, n2 = n*2; x<=n2; ++x ){
			y = (n*x)/(x-n);
			if( (x*y)/(x+y) == n ){
				sprintf(ans, "1/%s = 1/%lld + 1/%lld\n", buf, y, x);
				sb.append( ans );
				++c;
			}
		}
		cout << c << endl << sb;
	}
}
