/**
	UVa 115 - Climbing Trees
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define INF 2147483647
using namespace std;

struct node{
	int path1, path2;
	vector<node*> children, parents;
	node(): children(), parents() {}
};

void dfs1( node * p, int depth = 0 ){
	if( p->path1 > depth ){
		p->path1 = depth;
		for( int i=0; i<p->parents.size(); ++i ){
			dfs1( p->parents[i], depth + 1 );
		}
	}
}

void dfs2( node * p, int depth = 0 ){
	if( p->path2 > depth ){
		p->path2 = depth;
		for( int i=0; i<p->parents.size(); ++i ){
			dfs2( p->parents[i], depth + 1 );
		}
	}
}

int abs( int x ){ return x < 0 ? -x : x; }

string p, q;
map<string, node> m;
map<string, node>::iterator it;

int main(){
	while( cin >> p >> q, p != "no.child" ){
		node& child = m[p];
		node& parent = m[q];
		child.parents.push_back( &parent );
		parent.children.push_back( &child );
	}
	while( cin >> p >> q ){
		node& a = m[p];
		node& b = m[q];
		for( it = m.begin(); it != m.end(); ++it ){
			it->second.path1 = INF;
			it->second.path2 = INF;
		}
		dfs1( &a );
		dfs2( &b );
		// check if a is child
		if( b.path1 != INF ){
			for( int i=2; i<b.path1; ++i ){
				cout << "great ";
			}
			if( b.path1 > 1 ) cout << "grand ";
			cout << "child" << endl;
			continue;
		}
		// check if a is parent
		if( a.path2 != INF ){
			for( int i=2; i<a.path2; ++i ){
				cout << "great ";
			}
			if( a.path2 > 1 ) cout << "grand ";
			cout << "parent" << endl;
			continue;
		}
		// get minimum ancestor
		int mn = INF;
		node * cur;
		for( it = m.begin(); it != m.end(); ++it ){
			int mx = max( it->second.path1, it->second.path2 );
			if( mn > mx ){
				mn = mx;
				cur = &it->second;
			}
		}
		if( mn == INF ){
			cout << "no relation" << endl;
			continue;
		}
		int n = cur->path1;
		int m = cur->path2;
		int k = min( n, m ) - 1;
		int j = abs( n-m );
		if( k == 0 && j == 0 ){
			cout << "sibling" << endl;
			continue;
		}
		cout << k << " cousin";
		if( j ) cout << " removed " << j;
		cout << endl;
	}
}
