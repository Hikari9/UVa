/**
	UVa 11505 - Logo
	by Rico Tiongson
	Submitted: August 5, 2013
	Accepted 0.082s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
using namespace std;
int t, n;
double x, y, a, A, PI( acos(-1.) );
string cmd;
inline double RAD( double DEG ){
	return DEG * PI / 180.;
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		x = y = a = 0.;
		while( n-- ){
			cin >> cmd >> A;
			if( cmd=="fd" ){
				x += A*cos(RAD(a));
				y += A*sin(RAD(a));
			}
			else if( cmd=="bk" ){
				x -= A*cos(RAD(a));
				y -= A*sin(RAD(a));
			}
			else if( cmd=="lt" ){
				a += A;
				// a = fmod(a,360.);
			}
			else{
				a -= A;
				// a = fmod(a,360.) + 360.;
			}
			// cout << x << " " << y << " " << a << endl;
		}
		cout << (int)round(hypot(x,y)+1e-7) << endl;
	}
}
