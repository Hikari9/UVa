/**
	UVa 10462 - Is There A Second Way Left?
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.052s C++
	O(m logn) kruskals + O(n^3) second way
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<list>
#define INF 2147483647
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{
		return w < _.w;
	}
} backup;
int t, n, m, a, b, c, i, j, ans, r=0, f[101];
int find( int x ){
	return f[x]==-1 ? x : f[x] = find( f[x] );
}
list<edge> pq;
list<edge>::iterator it;
vector<edge> used;
void kruskals(){
	pq.sort();
	used.clear();
	memset( f, -1, sizeof(f) );
	c = 0;
	for( it=pq.begin(); it!=pq.end(); ){
		a = find( it->i );
		b = find( it->j );
		if( a!=b ){
			f[a] = b;
			c += it->w;
			used.push_back( *it );
			it = pq.erase( it );
			if( --n==1 ) break;
		}
		else ++it;
	}
	if( n>1 ){
		// no mst
		puts("No way");
		return;
	}
	// find substitute
	// cout << c << endl;
	if( !pq.empty() ){
		ans = INF;
		for( i=used.size()-1; i>=0; --i ){
			memset( f, -1, sizeof(f) );
			for( j=0; j<i; ++j ){
				f[ find(used[j].i) ] = find( used[j].j );
			}
			for( j=i+1; j<used.size(); ++j ){
				f[ find(used[j].i) ] = find( used[j].j );
			}
			for( it=pq.begin(); it != pq.end(); ++it ){
				if( find(it->i) != find(it->j) ){
					// use this
					ans = min( c-used[i].w + it->w , ans );
					// cout << ans << endl;
				}
			}
		}
		if( ans!=INF ){
			printf("%d\n",ans);
			return;
		}
	}
	puts("No second way");
}
int main(){
	scanf("%d", &t);
	while( r<t ){
		scanf("%d %d", &n, &m);
		pq.clear();
		while( m-- ){
			scanf("%d %d %d", &a, &b, &c);
			pq.push_back( edge(a,b,c) );
		}
		
		printf("Case #%d : ", ++r);
		kruskals();
	}
}
