/**
	UVa 10250 - The Other Two Trees
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.066s C++
	O(1) time
*/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double PI4(acos(0.)/2.), sqrt2(sqrt(2.));
double r,theta;
void convert(double dy, double dx){
	r = sqrt(dx*dx+dy*dy);
	theta = atan2(dy,dx);
}
int main(){
	double x1,y1,x2,y2;
	while(cin >> x1 >> y1 >> x2 >> y2){
		if(x1==x2 && y1==y2) cout << "Impossible." << endl;
		else{
			convert(y2-y1,x2-x1);
			r /= sqrt2;
			printf("%.10lf %.10lf %.10lf %.10lf\n",
				x1+r*cos(theta+PI4)+1e-12,
				y1+r*sin(theta+PI4)+1e-12,
				x1+r*cos(theta-PI4)+1e-12,
				y1+r*sin(theta-PI4)+1e-12
			);
		}
	}
}
