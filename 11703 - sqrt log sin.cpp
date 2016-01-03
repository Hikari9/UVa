/**
	UVa 11703 - sqrt log sin
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.349s C++
	O(n) pregen + O(1) time
*/
#include<iostream>
#include<vector>
#include<cmath>
#define mx 1000001
using namespace std;
typedef unsigned long long lag;
int main(){
	const long double e(2.7182818);
	long double X=e;
	vector<lag> Sqrt(mx), Log(mx), Sin2(mx), x(mx);
	x[0] = 1;
	for(lag i=0,k; (k=i*i)<mx; i++) Sqrt[k] = i;
	for(lag i=1;X<mx;i++,X*=e) Log[lag(ceil(X))] = i;
	for(lag i=1,j=0,k=0;i<mx;i++){
		X = sin(i);
		Sin2[i] = X*X*i;
		if(Sqrt[i]){
			j = Sqrt[i];
			Sqrt[i] = i-Sqrt[i];
		}
		else Sqrt[i] = i-j-1;
		if(Log[i]) k = Log[i];
		else Log[i] = k;
	}
	for(lag i=1;i<mx;i++) x[i] = (x[Sqrt[i]]+x[Log[i]]+x[Sin2[i]])%1000000;
	int n;
	while(cin >> n,n>-1) cout << x[n] << endl;
}
