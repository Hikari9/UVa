/**
    UVa 1108 - Meta-Loopless Sorts
    by Rico Tiongson
    Submitted: September 5, 2013
    Accepted 0.379s C++
    O(n!) time
*/
#include<iostream>
#include<cstring>
using namespace std;
string TAB( int x ){
    string ans;
    while( x-- ) ans.push_back(' ');
    return ans;
}
int t, n, i;
char ans[8];
//bool v[8];
void dfs( int x, int tabs ){
    if( (tabs>>1)==n ){
        cout << TAB(tabs) << "writeln(";
        for( i=0; i<n; ++i ){
            if(i) cout << ',';
            cout << ans[i];
        }
        cout << ")" << endl;
        return;
    }
    if(x==0) return;
    char orig[x+1];
    memcpy( orig, ans, x+1 );
    for( int j=x-1; j>=0; --j ){
        cout << TAB(tabs);
        if( j!=x-1 ) cout << "else ";
        cout << "if " << ans[j] << " < " << ans[j+1] << " then" << endl;
        dfs( x+1, tabs+2 );
        swap( ans[j], ans[j+1] );
    }
    cout << TAB(tabs) << "else" << endl;
    dfs( x+1, tabs+2 );
    // swap( ans[0], ans[x] );
    memcpy( ans, orig, x+1 );
}
int main(){
    cin >> t;
    while( t-- ){
        cin >> n;
        for( i=0; i<n; ++i ) ans[i] = 'a'+i;
        
        cout << "program sort(input,output);" << endl;
        cout << "var" << endl;
        cout << 'a';
        for( i=1; i<n; ++i ){
            cout.put(',').put( 'a' + i );
        }
        cout << " : integer;" << endl;
        cout << "begin" << endl;
        // tabs = 2;
        cout << TAB(2) << "readln(a";
        for( i=1; i<n; ++i ){
            cout.put(',').put( 'a' + i );
        }
        cout << ");" << endl;
        //( v, 0, sizeof v );
       // v[0] = true;
        dfs(1,2);
        cout << "end." << endl;
        if(t) cout << endl;
    }
}
