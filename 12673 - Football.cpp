/**
	UVa 12673 - Football
	by Rico Tiongson
	Submitted: Feb 3, 2014
	Accepted 0.129s C++
	O(nlogn) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, g, diff[100001];

int main(){
	while( fscanf( stdin, "%d %d", &n, &g ) != EOF ){
		int me, you, points = 0;
		for( int i=0; i<n; ++i ){
			fscanf( stdin, "%d %d", &me, &you );
			diff[i] = you - me;
			if( diff[i] < 0 ){
				points += 3;
				--i, --n;
			}
		}
		make_heap( diff, diff + n, greater<int>() );
		while( g > 0 && n > 0 ){
			if( g >= diff[0] + 1 ){
				g -= diff[0] + 1;
				points += 3;
			}
			else if( g >= diff[0] ){
				g -= diff[0];
				++points;
			}
			pop_heap( diff, diff+(n--), greater<int>() );
		}
		for( int i=0; i<n; ++i )
			if( diff[i] == 0 ) ++points;
		fprintf( stdout, "%d\n", points );
	}
}
