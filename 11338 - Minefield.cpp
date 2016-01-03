/**
	UVa 11338 - Minefield
	by Rico Tiongson
	Submitted: June 3, 2013
	Accepted 0.229s C++
	O(n(n+1)/2) dist + O(E) prune + O((m+n)logn) dijkstra
*/
#include<iostream>
#include<vector>
#include<set>
#include<cstdlib>
#include<cmath>
using namespace std;
struct node{
	double x, y,Path;
	bool v,isIn,mark;
	vector<pair<node*,double> > fr;
	struct cmp{
		bool operator()( const node* lhs, const node* rhs ) const{
			return lhs->Path < rhs->Path;
		}
	};
	set<node*,cmp>::iterator itself;
	void reset(){
		Path = HUGE_VAL;
		mark = v = isIn = false;
	}
	void clear(){
		fr.clear();
	}
} G[10005];
char buf[100];
int w, h, n;
double d, DIST;
double dist( const node& a, const node& b ){
	double x = a.x-b.x,
		y = a.y-b.y;
	return (x*x+y*y);
}
double dijkstra( node* Source, node* Target){

	if( !Source->mark ) return HUGE_VAL;
	set<node*,node::cmp> q;

	Source->Path = 0;
	Source->v = false;
	q.insert( Source );
	
	while( !q.empty() ){
		Source = *q.begin();
		q.erase(q.begin());
		if(Source==Target) return Target->Path;

		if( !Source->v ){
			Source->v = true;
			for(int i=0; i < Source->fr.size(); i++){
				pair<node*,double>& E = Source->fr[i];
				if(!E.first->v && E.first->mark){
					if(E.first->Path > Source->Path + E.second){
						//E.node->prev = Source;
						E.first->Path = Source->Path + E.second;
						
						if( E.first->isIn ) q.erase( E.first->itself );
						else E.first->isIn = true;
						E.first->itself = q.insert( E.first ).first;
						
					}
				}
			}
		}
	}
	
	return HUGE_VAL;
	
}
void prune( node* x ){
	x->mark = true;
	for( int i=0; i<x->fr.size(); ++i ){
		if( !x->fr[i].first->mark ) prune( x->fr[i].first );
	}
}
int main(){
	G[0].x = 0;
	G[0].y = 0;
	while( cin >> buf, buf[0]!='*' ){
		w = atoi(buf);
		cin >> h >> n;
		G[0].clear();
		for( int i=1;i<=n;++i ){
			cin >> G[i].x >> G[i].y;
			G[i].reset();
			G[i].clear();
		}
		++n;
		G[n].x = w;
		G[n].y = h;
		G[n].reset();
		G[n].clear();
		cin >> d;
		// d*=d;
		for( int i=1;i<=n;++i ){
			for( int j=0;j<i;++j ){
				DIST = dist( G[i], G[j] );
				if( DIST< 2.26 ){
					DIST = sqrt(DIST);
					G[i].fr.push_back( make_pair(&G[j],DIST) );
					G[j].fr.push_back( make_pair(&G[i],DIST) );
				}
			}
		}
		//prune
		prune(&G[n]);
		// cout << dijkstra(&G[0],&G[n]) << endl;
		if( dijkstra(&G[0],&G[n])<=d ) cout << "I am lucky!" << endl;
		else cout << "Boom!" << endl;
	}
}
