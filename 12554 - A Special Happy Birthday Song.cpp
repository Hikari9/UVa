/**
	UVa 12554 - A Special "Happy Birthday"
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<stdio.h>
const char* h[16] = {
	"Happy","birthday","to","you","Happy", 
	"birthday","to","you","Happy","birthday",
	"to","Rujia","Happy","birthday","to","you"
};
char buf[105][105];
int n, i, j, flag1=0;
int main(){
	scanf("%d",&n);
	getchar();
	for( i=0; i<n; ++i )
		gets( buf[i] );
	for( i=0, j=0; ; ++i, ++j ){
		if( j==n ){
			j=0;
			flag1 = 1;
		}
		if( i==16 ){
			i=0;
			if( flag1 ) break;
		}
		printf("%s: %s\n", buf[j], h[i]);
	}
}
