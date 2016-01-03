/**
    UVa 10066 - The Twin Towers
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.019s C++
    O(n^2) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int n1, n2, i, tc;
int dp[105][105];
int a[105], b[105];
int dfs( int x, int y ){
    if( x==n1 || y==n2 )
        return 0;
    if( dp[x][y]!=-1 ) return dp[x][y];
    dp[x][y] = max( dfs(x+1,y), dfs(x,y+1) );
    if( a[x]==b[y] ){
        dp[x][y] = max( dp[x][y], dfs(x+1,y+1)+1 );
    }
    return dp[x][y];
}
int main(){
    while( cin >> n1 >> n2, (n1||n2) ){
        memset( dp, -1, sizeof dp );
        for( i=0; i<n1; ++i ){
            cin >> a[i];
        }
        for( i=0; i<n2; ++i ){
            cin >> b[i];
        }
        cout << "Twin Towers #" << ++tc << endl;
        cout << "Number of Tiles : " << dfs(0,0) << endl << endl;
    }
}
