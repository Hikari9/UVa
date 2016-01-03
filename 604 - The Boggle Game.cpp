/**
	UVa 604 - The Boggle Game
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.068s C++
	O(4*4*4!*2nlogn) time
*/
#include<cstdio>
#include<set>
#include<string>
using namespace std;
char buf[20], c[2][4][4];
int i, j, p, dx[] = {-1, 0, 1, -1, 1, -1, 0, 1 }, dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool flag(false);
set<string> s, s2;
set<string>::iterator it;
typedef void (*func)();
func f;
bool isvowel( char _ ){
	switch(_){
		case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': return true;
	}
	return false;
}
void inserter(){ s.insert(buf); }
void checker(){
	if( s.find(buf)!=s.end() ) s2.insert( buf );
}
bool inRange( int x, int y ){
	if( x>=0 && x<4 && y>=0 && y<4 ){
		return c[p][x][y] != '-';
	}
	return false;
}
void parse(){
	c[0][i][0] = buf[0];
	c[0][i][1] = buf[2];
	c[0][i][2] = buf[4];
	c[0][i][3] = buf[6];
	
	c[1][i][0] = buf[11];
	c[1][i][1] = buf[13];
	c[1][i][2] = buf[15];
	c[1][i][3] = buf[17];
}
void dfs( int x, int y, int d, int v ){
	if( isvowel(c[p][x][y]) ) ++ v;
	buf[d] = c[p][x][y];
	if( ++d==4 ){
		if( v==2 ) (*f)();
		return;
	}
	c[p][x][y] = '-';
	for( int k =0; k<8; ++k ){
		if( inRange( x+dx[k], y+dy[k] ) ){
			dfs( x+dx[k], y+dy[k], d, v );
		}
	}
	c[p][x][y] = buf[--d];
}
int main(){
	while( gets( buf ), buf[0]!='#' ){
		if(flag) putchar('\n');
		else flag = true;
		s.clear();
		s2.clear();
		i = 0;
		do{
			parse();
			gets( buf );
		} while( ++i < 4 );
		buf[4] = '\0';
		p = 0;
		f = &inserter;
		for( i=0; i<4; ++i )
			for( j=0; j<4; ++j )
				dfs( i, j, 0, 0 );
		p = 1;
		f = &checker;
		for( i=0; i<4; ++i )
			for( j=0; j<4; ++j )
				dfs( i, j, 0, 0 );
		if( s2.empty() ) puts("There are no common words for this pair of boggle boards.");
		else for( it=s2.begin(); it!=s2.end(); ++it ){
			for( i=0; i<4; ++i ) putchar( it->at(i) );
			putchar('\n');
		}
	}
}
