/**
	UVa 654 - Ratio
	by Rico Tiongson
	Submitted: September 12, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
using namespace std;
typedef long long lag;
lag ABS( lag x ){
	if( x<0 ) return -x;
	return x;
}
int gcd( int a, int b ){
	int temp;
	while( a ){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
int x, y, num, den;
int a, b, g;
lag n, d;
bool fi;
int main(){
	while( cin >> x >> y ){
		if(fi) cout << endl;
		else fi = true;
		g = gcd(x,y);
		x /= g;
		y /= g;
		a = 0;
		b = 5005;
		for( den=1; den<=y; ++den ){
			num = ( x * den + y/2 )/y;
			if( gcd(num,den)!=1 ) continue;
			if( num==1 ){
				cout << num << "/" << den << endl;
				a = num;
				b = den;
				continue;
			}
			n = ABS( (lag) b * ( num*y - x*den ) );
			d = ABS( (lag) den * ( x*b - a*y ) );
			if( n>=d ) continue;
			cout << num << "/" << den << endl;
			a = num;
			b = den;
		}
	}
}
