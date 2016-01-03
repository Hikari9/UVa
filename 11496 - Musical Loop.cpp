/**
	UVa 11496 - Musical Loop
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.025s C++
	O(n+2) time
*/
#include<iostream>
using namespace std;
int n,x[10005],p,up;
int main(){
	while(cin >> n,n){
		p=0;
		for(int i=0;i<n;i++) cin >> x[i];
		if(x[n-1]>x[0]) up = 1;
		else if(x[n-1]<x[0]) up = -1;
		else up = 0;
		for(int i=1;i<n;i++){
			if(x[i-1]>x[i]){
				if(up==-1) p++;
				up = 1;
			}
			else if(x[i-1]<x[i]){
				if(up==1) p++;
				up = -1;
			}
		}
		if(x[n-1]>x[0]){
			if(up==-1) p++;
		}
		else if(x[n-1]<x[0]){
			if(up==1) p++;
		}
		cout << p << endl;
	}
}
