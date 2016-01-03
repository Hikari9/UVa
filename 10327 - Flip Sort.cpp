/**
	UVa 10327 - Flip Sort
	by Rico Tiongson
	Submitted: May 26, 2013
	Accepted 0.062s C++
	O(n^2) time
*/
#include<cstdio>
#include<iostream>
using namespace std;
int x[10005],n,c,i,j;
int main(){
	while(cin >> n){
		c=0;
		for(i=0;i<n;i++){
			cin >> x[i];
			for(j=i-1;j>=0;j--){
				if(x[i]<x[j]) c++;
			}
		}
		printf("Minimum exchange operations : %d\n",c);
	}
}
