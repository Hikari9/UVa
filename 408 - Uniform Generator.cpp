/**
	UVa 408 - Uniform Generator
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.022s C++
	O(logn) time
*/
#include<iostream>
using namespace std;
long long x, y;
long long gcd( long long a, long long b ){
	long long temp;
	while( b ){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main(){
	while( cin >> x >> y ){
		cout.width(10);
		cout << right << x;
		cout.width(10);
		cout << right << y;
		cout << "    ";
		if( gcd(x,y)==1 ){
			cout << "Good Choice" << endl;
		}
		else{
			cout << "Bad Choice" << endl;
		}
		cout << endl;
	}
}
