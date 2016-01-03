/**
	UVa 11152 - Colourful Flowers
	by Rico Tiongson
	Submitted: September 22, 2013
	Accepted 0.112s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
int a, b, c;
double Area, inradius, circumradius;
double area(){
	double s = (a+b+c)/2.0;
	return sqrt( s*(s-a)*(s-b)*(s-c) );
}
int main(){
	cout.precision(4);
	cout << fixed;
	while( cin >> a >> b >> c ){
		Area = area();
		inradius = 2.0*Area/(a+b+c);
		circumradius = (double)a*b*c/(4.0*Area);
		cout << PI*circumradius*circumradius-Area << " " << Area-PI*inradius*inradius << " " << PI*inradius*inradius << endl;
	}
}
