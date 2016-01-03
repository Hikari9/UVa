/**
	UVa 10141 - Request for Proposal
	by Rico Tiongson
	Submitted: June 17, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n, t, r=0, mxint;
bool ns(false);
double mnfloat, f;
char buf[105];
string mnstr;
int main(){
	scanf("%d %d", &n, &t);
	while( n||t ){
		if(ns) putchar('\n');
		else ns = true;
		mxint = 0;
		mnfloat = HUGE_VAL;
		mnstr.clear();
		getchar();
		do{
			while( n ){
				gets( buf );
				--n;
			}
			gets( buf );
			scanf( "%f %d", &f, &n );
			getchar();
			if( n > mxint ){
				mxint = n;
				mnfloat = f;
				mnstr = buf;
			}
			else if( n==mxint && mnfloat > f ){
				mxint = n;
				mnfloat = f;
				mnstr = buf;
			}
		} while( --t );
		while( n ){
			gets(buf);
			--n;
		}
		printf("RFP #%d\n", ++r);
		cout << mnstr << endl;
		scanf("%d %d", &n, &t);
	}
}
