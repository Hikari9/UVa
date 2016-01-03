/**
	UVa 1196 - Tiling Up Blocks
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.016s C++
	O(nlogn) time
*/
#include<cstdio>
#include<algorithm>
#define MX 10001
using namespace std;
struct block{
	int l, m;
	block() {}
	block( int L, int M ): l(L), m(M) {}
	bool operator<( const block& _ ) const{
		return l < _.l || ( l==_.l && m < _.m );
	}
	bool operator<=( const block& _ ) const{
		return l <= _.l && m <= _.m;
	}
} b[MX];
int n, i, j;
int seq[MX], size;
int main(){
	while( scanf("%d",&n)==1 && n ){
		for( i=0; i<n; ++i ){
			scanf( "%d %d", &b[i].l, &b[i].m );
		}
		sort( b, b+n );
		size = 0;
		for( i=0; i<n; ++i ){
			j = upper_bound( seq, seq+size, b[i].m ) - seq;
			if( j==size )
				++size;
			seq[j] = b[i].m;
		}
		printf("%d\n",size);
	}
	puts("*");
}
