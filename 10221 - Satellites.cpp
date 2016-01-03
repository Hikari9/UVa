/**
	UVa 10221 - Satellites
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.016s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
#define R 6440.0
using namespace std;
const long double PI( acos(-1.0) );
long double ia;
long double s, a, A, C;
string x;
int main(){
	cout.precision(6);
	cout << fixed;
	while( cin >> s >> ia >> x ){
		if(x=="min") ia/=60.0;
		while( ia>180.0 ) ia = 360.0-ia;
		a = ia*PI/180.0;
		s += R;
		A = s*a;
		C = ( s-s*cos(a) )/cos( (PI-a)*0.5 );
		cout << A << " " << C << endl;
	}
}
