/**
	UVa 11827 - Maximum GCD
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted: 0.009s C++
	O(n^2) time
*/
#include<iostream>
#include<sstream>
using namespace std;
int gcd(int a, int b){
	while(b!=0){
		int temp = b;
		b = a%b;
		a=temp;
	}
	return a;
}
int main(){
	int n,m,x[101],mx;
	char c[1024];
	cin >> n;
	cin.get();
	while(n--){
		cin.getline(c,1024);
		istringstream str(c);
		mx=0;
		for(m=0;str >> x[m];m++);
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				mx = max(mx,gcd(x[i],x[j]));
			}
		}
		cout << mx << endl;
	}
}
