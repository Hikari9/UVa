/**
	UVa 11309 - Counting Chaos
	by Rico Tiongson
	Submitted: September 22, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<cstdio>
using namespace std;
int n, hh, mm, i;
bool palindrome( int x ){
	int y = x, rev = 0;
	while( x ){
		rev = (rev*10) + (x%10);
		x /= 10;
	}
	return y==rev;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d:%d",&hh,&mm);
		i = hh * 100 + mm;
		do{
			if( (++i)%100==60 ){
				i += 40;
				if( i==2400 ) i = 0;
			}
		} while( !palindrome(i) );
		printf( "%02d:%02d\n", i/100, i%100 );
	}
}
