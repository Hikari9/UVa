/**
	UVa 10522 - Height to Area
	by Rico Tiongson
	Submitted: September 22, 2013
	Accepted 0.015s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
using namespace std;
int n;
double ha, hb, hc, abc;
double b1, b2, b3;
double h1, h2, h3, h4;
int main(){
	cout.precision(3);
	cout << fixed;
	cin >> n;
	while(n){
		cin >> ha >> hb >> hc;
		
		b1 = ha*hb;
		b2 = hb*hc;
		b3 = hc*ha;
		
		abc = ha*hb*hc;
		
		h1 = b1 + b2 + b3;
		h2 = -b1 + b2 + b3;
		h3 = b1 - b2 + b3;
		h4 = b1 + b2 - b3;
		
		if( ha<=0.0 || hb<=0.0 || hc<=0.0 || h1<=0.0 || h2<=0.0 || h3<=0.0 || h4<=0.0 ){
			cout << "These are invalid inputs!" << endl;
			--n;
		}
		else{
			cout << abc*abc / sqrt(h1) / sqrt(h2) / sqrt(h3) / sqrt(h4) << endl;
		}
	}
}
