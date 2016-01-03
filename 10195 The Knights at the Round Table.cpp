/**
    UVa 10195 - The Knights at the Round Table
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.019s C++
    O(1) time
*/
#include<cstdio>
#include<cmath>
using namespace std;
double a, b, c, p, A;
int main(){
    while( scanf("%lf %lf %lf",&a,&b,&c)==3 ){
        p = (a+b+c)*0.5;
        A = sqrt(abs(p)) * sqrt(abs(p-a)) * sqrt(abs(p-b)) * sqrt(abs(p-c));
        printf( "The radius of the round table is: %.3lf\n", (a+b+c!=0 ? 2.0*A/(a+b+c) : 0.0 ) );
    }
}
