/**
	ACM-ICPC 5402 - Prime Factors
	by Rico Tiongson
	Submitted: July 21, 2013
	Accepted 0.258s C++
	O(nsqrtn) time
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define mx 46340
using namespace std;
vector<int> pr;
int i, j, lim, x;
bool f;
void addprime(){
	lim = sqrt( i )+1;
	for( j=1; pr[j] < lim; ++j ){
		if( i%pr[j]==0 ) return;
	}
	pr.push_back( i );
}
int main(){
	pr.push_back( 2 );
	pr.push_back( 3 );
	for( i=5; i<mx; i+=4 ){
		addprime();
		i+=2;
		addprime();
	}
	start:
	scanf("%d", &x);
	if( !x ) return 0;
	printf("%d =",x);
	f = false;
	if( x<0 ){
		x = -x;
		printf(" -1");
		f = true;
	}
	for( i=0; x>1 && i<pr.size(); ++i ){
		while( x%pr[i]==0 ){
			if( f ){
				putchar(' ');
				putchar('x');
			}
			else f=true;
			printf(" %d",pr[i]);
			x/=pr[i];
		}
	}
	if( x>1 ){
		if( f ){
			putchar(' ');
			putchar('x');
		}
		printf(" %d",x);
	}
	putchar('\n');
	goto start;
}
