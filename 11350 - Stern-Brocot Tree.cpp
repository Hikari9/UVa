/**
	UVa 11350 - Stern-Brocot Tree
	by Rico Tiongson
	Submitted: October 18, 2013
	Accepted 0.022s C++
	O(logn) time
*/
#include<cstdio>
using namespace std;

int t;
char buf[100];

long long nlo, dlo, nhi, dhi, n, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", buf);
		nlo = 0;
		dlo = 1;
		nhi = 1;
		dhi = 0;
		n = 1;
		d = 1;
		for( int i=0; buf[i]; ++i ){
			if( buf[i] == 'L' ){
				nhi = n;
				dhi = d;
			}
			else{
				nlo = n;
				dlo = d;
			}
			n = nlo + nhi;
			d = dlo + dhi;
		}
		printf("%lld/%lld\n", n, d);
	}
}
