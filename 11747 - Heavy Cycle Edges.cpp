/**
	UVa 11747 - Heavy Cycle Edges
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.022s C++
	O( m logm ) time
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	void in(){
		scanf("%d %d %d",&i,&j,&w);
	}
	bool operator<( const edge& _ )const{
		return w < _.w;
	}
} E[25001];
int n, m, i, a, b, f[1001];
bool F;
int find( int x ){
	return f[x]==-1 ? x : f[x] = find( f[x] );
}
void kruskals(){
	F = false;
	memset( f, -1, n<<2 );
	sort( E, E+m );
	for( i=0; i<m; ++i ){
		a = find( E[i].i );
		b = find( E[i].j );
		if( a!=b )
			f[a] = b;
		else{
			if( F ) putchar(' ');
			else F = true;
			printf("%d",E[i].w);
		}
	}
	if( F ) putchar('\n');
	else puts("forest");
}
int main(){
	scanf("%d %d",&n,&m);
	while( n||m ){
		for( i=0; i<m; ++i )
			E[i].in();
		kruskals();
		scanf("%d %d",&n,&m);
	}
}
