/**
	UVa 11474 - Dying Tree
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.042s C++
	O(n^2) time
*/
// #include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct point{
	int x, y;
} p[1200];

int t, n, m, o, f[1200];

int d, k, dx, dy;
int i, j, sz, T;

int find( int x ){
	return f[x]==x ? x : f[x]=find(f[x]);
}

int dist( int I, int J ){
	dx = p[I].x-p[J].x;
	dy = p[I].y-p[J].y;
	return dx*dx + dy*dy;
}

bool saveTree(){
	// connect adj trees
	for( i=m; i<sz; ++i ){
		for( j=i+1; j<sz; ++j ){
			if( find(i) != find(j) ){
				if( dist( i, j ) <= k ){
					f[ find(i) ] = find(j);
					// if( hasDoctor() ) return true;
				}
			}
		}
	}
	// getDoctors
	for( i=0; i<m; ++i ){
		for( j=m; j<sz; ++j ){
			if( find(i)!=find(j) ){
				if( dist( i, j ) <= d ){
					f[ find(i) ] = find(j);
					if( find(i)==find(m) ) return true; // conn with sick already
				}
			}
		}
	}
	
	return false;
}
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d %d %d", &n, &m, &k, &d );
		k *= k;
		d *= d;
		for( i=0; i<m; ++i ) f[i] = i;
		for( i=0; i<m; ++i ){
			scanf( "%d %d", &p[i].x, &p[i].y );
		}
		// sick tree is p[m]
		for( T=0; T<n; ++T ){
			scanf( "%d", &o );
			for( j=0; j<o; ++j ){
				scanf( "%d %d", &p[i+j].x, &p[i+j].y );
				f[i+j] = i;
			}
			i += o;
		}
		// cout << i << endl;
		sz = i;
		if( saveTree() ) puts( "Tree can be saved :)" );
		else puts( "Tree can't be saved :(" );
	}
}
