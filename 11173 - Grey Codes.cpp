/**
    UVa 11173 - Grey Codes
    by Rico Tiongson
    Submitted: September 5, 2013
    Accepted 0.926s C++
    O(logn) time
*/
#include<iostream>
using namespace std;
int i, j, t;
int ans( int n, int k ){
    if(n==1) return k;
    int mask = (1<<(n-1))&k;
    if(mask){
        // flip
        //cout << ans( n-1, (1<<n) - k  ) << endl;
        return mask | ans( n-1, ~k & (mask-1)  );
    }
    return ans( n-1, k );
}
int main(){
    //solve();
    cin >> t;
    while( t-- ){
        cin >> i >> j;
        cout << ans(i,j) << endl;
    }
}