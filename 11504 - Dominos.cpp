/**
	UVa 11504 - Dominos
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.225s C++
	O(V+|E|) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define MX 100005
using namespace std;
struct node{
	int id, low;
	bool inStack;
	vector<node*> fr;
	node(): id(-1), low(-1), inStack(false), fr() {}
	inline void reset(){
		id = -1;
		low = 0;
		inStack = false;
		fr.clear();
	}
} G[MX];
stack<node*> S;
int SSC[MX];
bool side_effect[MX];
int t, n, m, i, j, J, x, y, ans, id, id2;
void dfs( node& v ){
	v.id = v.low = id++;
	S.push( &v );
	v.inStack = true;
	for( int k=0; k<v.fr.size(); ++k ){
		node& w = *v.fr[k];
		if( w.id==-1 ){
			dfs(w);
			v.low = min( v.low, w.low );
		}
		else if( w.inStack ){
			v.low = min( v.low, w.id );
		}
	}
	if( v.low==v.id ){
		// SSC[&v-G] = id2;
		while( !S.empty() ){
			S.top()->inStack = false;
			SSC[S.top()-G] = id2;
			if( S.top()==&v ){
				S.pop();
				break;
			}
			S.pop();
		}
		++id2;
	}
}
inline int tarjan(){
	
	id = id2 = 0;
	S = stack<node*>();
	for( i=1; i<=n; ++i ){
		if( G[i].id==-1 ){
			dfs( G[i] );
		}
	}
	// check for domino side effects
	memset( side_effect, 0, id2 );
	for( i=1; i<=n; ++i ){
		for( j=0; j<G[i].fr.size(); ++j ){
			// same component, ignore
			J = G[i].fr[j]-G;
			if( SSC[i]==SSC[J] ) continue;
			// is already visited
			if( side_effect[ SSC[J] ] ) continue;
			side_effect[ SSC[J] ] = true;
		}
	}
	ans = 0;
	for( i=0; i<id2; ++i ){
		if( !side_effect[i] ) ++ans;
	}
	return ans;
}
int main(){
	scanf( "%d", &t );
	while(t--){
		scanf( "%d %d", &n, &m );
		for( i=1; i<=n; ++i ){
			G[i].reset();
		}
		while(m--){
			scanf( "%d %d", &x, &y );
			G[x].fr.push_back(G+y);
		}
		printf( "%d\n", tarjan() );
	}
}
