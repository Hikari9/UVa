/**
	UVa 587 - There's treasure everywhere!
	by Rico Tiongson
	Submitted: August 29, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<string>
using namespace std;
const double sqrt2 = sqrt(2.)*0.5;
pair<string,pair<double,double> > mArray[8] = {
	make_pair( "N", make_pair( 0., 1. ) ),
	make_pair( "NE", make_pair( sqrt2, sqrt2 ) ),
	make_pair( "E", make_pair( 1., 0. ) ),
	make_pair( "SE", make_pair( sqrt2, -sqrt2 ) ),
	make_pair( "S", make_pair( 0., -1. ) ),
	make_pair( "SW", make_pair( -sqrt2, -sqrt2 ) ),
	make_pair( "W", make_pair( -1., 0. ) ),
	make_pair( "NW", make_pair( -sqrt2, sqrt2 ) )
};
map<string,pair<double,double> > m( mArray, mArray+8 );
char buf[205], *p, dir[5];
int l, tc;
double x, y;
int main(){
	while( gets(buf) ){
		if( strcmp(buf,"END")==0 ) return 0;
		x = y = 0.;
		for( p=strtok(buf," ,."); p!=NULL; p=strtok(NULL," ,.") ){
			sscanf( p, "%d%s", &l, dir );
			const pair<double,double>& pt = m[dir];
			x += pt.first * l;
			y += pt.second * l;
		}
		
		printf( "Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n", ++tc, x, y, sqrt(x*x+y*y) );
	}
}
