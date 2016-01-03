/**
    UVa 10192 - Vacation
    by Rico Tiongson
    Submitted: September 7, 2013
    Accepted 0.019s C++
    O(n^2) time
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<set>
using namespace std;
string a, b;
int tc;
int dp[105][105];
bool v[256];
int dfs( int x, int y ){
    if( x==a.length() || y==b.length() ){
        return 0;
    }
    if( dp[x][y]!=-1 ) return dp[x][y];
    dp[x][y] = max( dfs(x+1,y), dfs(x,y+1) );
    if( a[x]==b[y] ){
        if( !v[a[x]] ){
            v[a[x]] = true;
            dp[x][y] = max( dp[x][y], dfs(x+1,y+1)+1 );
            v[a[x]] = false;
        }
        else{
            dp[x][y] = max( dp[x][y], dfs(x+1,y+1) );
        }
    }
    return dp[x][y];
}
int main(){
    while( getline(cin,a), a!="#" ){
        getline(cin,b);
        memset(dp,-1,sizeof dp);
        memset(v,0,sizeof v);
        cout << "Case #" << ++tc << ": you can visit at most " << dfs(0,0) << " cities." << endl;
    }
}
