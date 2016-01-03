/**
	UVa 722 - Lakes
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.055s C++
	O(dfs) time
*/
#include<iostream>
#include<vector>
using namespace std;
int t, x, y, c;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<string> g;
string in;

bool inRange( int a, int b ){
	return a >= 0 && a < g.size() && b >= 0 && b < g[a].size();
}

void dfs( int a, int b ){
	if( !inRange(a, b) || g[a][b] != '0' ) return;
	++c;
	g[a][b] = '1';
	for( int i=0; i<4; ++i ){
		dfs( a + dx[i], b + dy[i] );
	}
}

void trim( string& s ){
	int i, j;
	for( i=0; i<s.length(); ++i ){
		if( s[i] != ' ' ) break;
	}
	for( j=s.length()-1; j>i; --j ){
		if( s[j] != ' ' ) break;
	}
	s = s.substr(i, j-i+1);
}

int main(){
	bool first = true;
	cin >> t;
	while(t--){
		if(first) first = false;
		else cout << endl;
		cin >> x >> y;
		--x, --y;
		getline( cin, in );
		g.clear();
		while( getline( cin, in ) ){
			trim(in);
			if( in.empty() ) break;
			g.push_back(in);
		}
		c = 0;
		dfs(x, y);
		cout << c << endl;
	}
}
