/**
    UVa 900 - Brick Wall Patterns
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.016s ANSI C
    O(n) time
*/
#include<stdio.h>
int n, f[51]={1,1};
int main(){
    for( n=2; n<51; ++n )
        f[n] = f[n-1] + f[n-2];
    scanf("%d",&n);
    while(n){
        printf("%d\n",f[n]);
        scanf("%d",&n);
    }
}
