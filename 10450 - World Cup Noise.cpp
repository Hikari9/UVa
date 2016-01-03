/**
    UVa 10450 - World Cup Noise
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.016s C++
    O(n) pregen + O(1) time
*/
#include<iostream>
using namespace std;
int t, tc, n;
long long f[51] = {0,2,3};
int main(){
    for( n=3; n<51; ++n )
        f[n] = f[n-1]+f[n-2];
    cin >> t;
    while(tc<t){
        cin >> n;
        cout << "Scenario #" << ++tc << ":" << endl;
        cout << f[n] << endl << endl;
        
    }
}
