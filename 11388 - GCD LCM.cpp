/**
    UVa 11388 - GCD LCM
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.019s C++
    O(1) time
*/
#include<cstdio>
using namespace std;
int t, l, g;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&g,&l);
        if( l<g || l%g!=0 ){
            puts("-1");
            continue;
        }
        printf("%d %d\n",g,l);
    }
}
