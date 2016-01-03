/**
	UVa 10347 - Medians
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.019s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout.precision(3);
	cout << fixed;
	double a,b,c,d;
	while(cin >> a >> b >> c){
		a*=a;
		b*=b;
		c*=c;
		d = 2.*(a*b + b*c + a*c) - (a*a+b*b+c*c);
		if(d<=0.) cout << "-1.000" << endl;
		else cout << sqrt(d)/3. << endl;
	}
}
