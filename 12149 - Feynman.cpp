/**
	UVa 12149 - Feynman
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted 0.016s C++
	O(1) time
*/
#include<iostream>
using namespace std;
int main(){
	int x[101],n;
	x[0]=0;
	x[1]=1;
	for(int i=2;i<101;i++)
		x[i]=x[i-1]+i*i;
	while(cin>>n,n) cout << x[n] << endl;
}
