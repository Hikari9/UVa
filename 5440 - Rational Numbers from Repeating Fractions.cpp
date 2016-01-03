/**
	ACM 5440 - Rational Numbers from Repeating Fractions
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.112s C++
	O(?) time
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int gcd( int a, int b ){
	int temp;
	while( b ){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int Pow( int b, int e ){
	if( e==0 ) return 1;
	int half = Pow( b, e/2 );
	if( e%2 ) return half * half * b;
	return half * half;
}
int n, len, numerator, denominator, g, tc=0;
char buf[51], *p = buf+2;
int main(){
	start:
	cin >> n;
	if( n==-1 ) return 0;
	cin >> buf;
	cout << "Case " << ++tc << ": ";
	len = strlen( buf );
	if( len<3 ){
		cout << "0/1" << endl;
		goto start;
		// zero
	}
	len -= 2;
	
	// trim
	// while( len && p[len-1]=='0' ) p[--len] = '\0';
	// if( !len ){
		// cout << "0" << endl;
		// goto start;
	// }
	// cout << p << endl;
	
	// get numerator
	numerator = atoi( p );
	denominator = Pow( 10, len );
	n = max( 0, len-n );
	if( n==len ){
		g = gcd( numerator, denominator );
		cout << numerator/g << "/" << denominator/g << endl;
		goto start;
	}
	p[n] = '\0';
	numerator -= atoi( p );
	denominator -= Pow( 10, n );
	g = gcd( numerator, denominator );
	cout << numerator/g << "/" << denominator/g << endl;
	goto start;
}
