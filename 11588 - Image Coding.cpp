/**
	UVa 11588 - Image Coding
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.019s C++
	O(rc + 52) time
*/
#include<cstdio>
#include<iostream>
using namespace std;
int x,r,c,m,n,mx,ans;
char s[25][25];
int main(){
	scanf("%d",&x);
	for(int X=1;X<=x;X++){
		scanf("%d %d %d %d",&r,&c,&m,&n);
		for(int i=0;i<r;i++) scanf("%s",s[i]);
		int a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		a[s[i][j]-'A']++;
		mx = a[0];
		for(int i=1;i<26;i++){
			if(a[i]>mx) mx=a[i];
		}
		ans = 0;
		for(int i=0;i<26;i++){
			if(a[i]==mx) ans+=mx;
		}
		printf("Case %d: %d\n",X,ans*m + (r*c-ans)*n);
	}
}
