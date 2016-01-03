/**
	UVa 173 - Tribonacci
	by Rico Tiongson
	Submitted: September 14, 2013
	Accepted 0.022s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long lag;
lag mod = 1000000009;
lag trib[3][3] = {
	1, 1, 1,
	1, 0, 0,
	0, 1, 0
};
lag f[3] = { 2, 1, 0 };
lag sq[3][3], temp[3][3], bs[3][3];
lag n, ans;
int i, j, k;
lag tribonacci(){
	memset( sq, 0, sizeof sq );
	sq[0][0] = sq[1][1] = sq[2][2] = 1;
	memcpy( bs, trib, sizeof bs );
	while(n){
		if( n&1 ){
			memset( temp, 0, sizeof temp );
			for( i=0; i<3; ++i ){
				for( j=0; j<3; ++j ){
					for( k=0; k<3; ++k ){
						temp[i][j] = ( temp[i][j] + sq[i][k] * bs[k][j] )%mod;
					}
				}
			}
			memcpy( sq, temp, sizeof temp );
		}
		memset( temp, 0, sizeof temp );
		for( i=0; i<3; ++i ){
			for( j=0; j<3; ++j ){
				for( k=0; k<3; ++k ){
					temp[i][j] = ( temp[i][j] + bs[i][k] * bs[k][j] )%mod;
				}
			}
		}
		memcpy( bs, temp, sizeof temp );
		n >>= 1;
	}
	// i = 2; 
	// j = 0;
	ans = 0;
	for( k=0; k<3; ++k ){
		ans = ( ans + sq[2][k] * f[k] )%mod;
	}
	return ans;
}
int main(){
	scanf( "%lld", &n );
	while(n){
		--n;
		printf( "%lld\n", tribonacci() );
		scanf( "%lld", &n );
	}
}
