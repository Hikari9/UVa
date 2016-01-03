/**
	UVa 11281 - Triangular Pegs in Round Holes
	by Rico Tiongson
	Submitted: June 29, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<cstdio>
#include<cmath>
int m, n, i, j;
bool f;
double hole[101], a, b, c, aa, bb, cc, p;
int main(){
	scanf( "%d", &m );
	for( i=0; i<m; ++i ) scanf("%lf", hole+i);
	scanf( "%d", &n );
	n += 'A';
	for( i='A'; i<n; ++i ){
		scanf("%lf %lf %lf",&a,&b,&c);
		aa = a*a;
		bb = b*b;
		cc = c*c;
		// obtuse
		if( bb + cc < aa ) p = a;
		else if( aa + cc < bb ) p = b;
		else if( aa + bb < cc ) p = c;
		else{
			p = (a+b+c)/2.0;
			p = (a*b*c) / (2.0*sqrt( p*(p-a)*(p-b)*(p-c) ) );
		}
		f = false;
		printf("Peg %c will ",i);
		for( j=0; j<m; ++j ){
			if( p<=hole[j] ){
				if( f ) printf(" %d",j+1);
				else{
					f = true;
					printf("fit into hole(s): %d",j+1);
				}
			}
		}
		if( !f ) printf("not fit into any holes");
		putchar('\n');
	}
}
