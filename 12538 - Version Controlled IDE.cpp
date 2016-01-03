/**
	UVa 12538 - Version Controlled IDE
	by Rico Tiongson
	Submitted: September 16, 2013
	Accepted 1.792s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<ext/rope>
#include<algorithm>
using namespace std;
using namespace __gnu_cxx;
crope ver[50005], r, str;
char in[205];
int n, cmd, p, d, c, v, i;
int main(){
	scanf( "%d", &n );
	while(n--){
		getchar();
		switch( getchar() ){
			case '1':
				scanf( "%d %s", &p, in );
				r.insert( p-d, in );
				ver[++i] = r;
				break;
			case '2':
				scanf( "%d %d", &p, &c );
				r.erase( p-d-1, c-d );
				ver[++i] = r;
				break;
			case '3':
				scanf( "%d %d %d", &v, &p, &c );
				v -= d;
				c -= d;
				p -= d;
				str = ver[v].substr( p-1, c );
				d += count( str.begin(), str.end(), 'c' );
				cout << str << '\n';
				break;
		}
	}
}
