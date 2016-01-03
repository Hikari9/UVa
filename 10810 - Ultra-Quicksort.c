/**
	UVa 10810 - Ultra-QuickSort
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.202s ANSI C
	O(nlogn) time
*/
#include<stdio.h>
#define INF 2147483647L
long a[3][500005], c;
int i, j, k, n, nl, nr;
void conquer( int l, int mid, int r ){
	for( i=l, nl=0; i<=mid; ++i, ++nl ) a[1][nl] = a[0][i];
	for( nr=0; i<=r; ++i, ++nr ) a[2][nr] = a[0][i];
	a[1][nl] = a[2][nr] = INF;
	i = j = 0;
	for( k=l; k<=r; ++k ){
		if( a[1][i] < a[2][j] ){
			a[0][k] = a[1][i];
			++i;
		}
		else{
			a[0][k] = a[2][j];
			++j;
			c += (long)(nl-i);
		}
	}
}
void divide( int l, int r ){
	if( l<r ){
		int mid = (l+r)/2;
		divide( l, mid );
		divide( mid+1, r );
		conquer( l, mid, r );
	}
}
int main(){
	scanf("%d",&n);
	while( n ){
		getchar();
		for( i=1; i<=n; ++i ){
			scanf("%ld",a[0]+i);
			getchar();
		}
		c = 0L;
		divide(1,n);
		printf("%ld\n",c);
		scanf("%d",&n);
	}
}
