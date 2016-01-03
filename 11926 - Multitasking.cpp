/**
	UVa 11926 - Multitasking
	by Rico Tiongson
	Submitted: September 6, 2013
	Accepted 0.029s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int n, m, x, y, z, X, Y;
bool conflict;
bool a[1000001];
int main(){
	while( scanf("%d %d", &n, &m)==2 && ( n||m ) ){
		memset(a,0,sizeof a);
		conflict = false;
		while(n--){
			scanf( "%d %d", &x, &y );
			if(conflict) continue;
			if(x<0) x=0;
			if(y>1000000) y=1000000;
			while( x<y ){
				if( a[x] ){
					conflict = true;
					break;
				}
				a[x++] = true;
			}
		}
		next:
		while(m--){
			scanf( "%d %d %d", &x, &y, &z );
			if(conflict) continue;
			for( X=x, Y=y; X<1000001; X+=z, Y+=z ){
				x = X;
				y = Y;
				if(x<0) x=0;
				if(y>1000000) y=1000000;
				while( x<y ){
					if( a[x] ){
						conflict = true;
						goto next;
					}
					a[x++] = true;
				}
			}
		}
		if(!conflict) printf("NO ");
		puts("CONFLICT");
	}
}
