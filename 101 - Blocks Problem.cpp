/**
	UVa 101 - Blocks Problem
	by Rico Tiongson
	Submitted: October 23, 2013
	Accepted 0.022s C++
	O(?) time
*/
#include<iostream>
#include<stdexcept>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n, m[26];
vector<int> v[26];

void print();

vector<int>& Pile( int x ){
	return v[m[x]];
}

int get( int x ){
	for( int i=0; i<Pile(x).size(); ++i ){
		if( Pile(x)[i] == x ) return i;
	}
	throw out_of_range( "id not found" );
}

void ResetPile( int x ){
	int f = get(x);
	for( int i = Pile(x).size() - 1; i > f; --i ){
		int node = Pile(x).back();
		m[node] = node;
		v[node].push_back(node);
		Pile(x).pop_back();
	}
	Pile(x).resize(f+1);
}

void MovePile( int x, int y ){
	int f = get(x);
	vector<int>& oldPile = Pile(x);
	for( int i=f; i<oldPile.size(); ++i ){
		int node = oldPile[i];
		m[node] = m[y];
		Pile(y).push_back(node);
	}
	oldPile.resize(f);
}

void print(){
	for( int i=0; i<n; ++i ){
		cout << i << ':';
		for( int j=0; j<v[i].size(); ++j ){
			cout << ' ' << v[i][j] /*<< '(' << m[v[i][j]] << ')'*/;
		}
		cout << endl;
	}
}

int main(){
	
	string x, y;
	int a, b;

	cin >> n;
	
	for( int i=0; i<n; ++i ){
		m[i] = i;
		v[i].push_back(i);
	}
	
	while( cin >> x ){
		
		if( x == "quit" ) break;
		cin >> a >> y >> b;
		if( m[a] == m[b] ) continue;
		// cout << x << " " << a <<" " << y << " " << b << endl;
		if( x == "move" ){
			if( y == "onto" ){
				ResetPile(a);
				Pile(a).pop_back();
				m[a] = m[b];
				ResetPile(b);
				Pile(b).push_back(a);
			}
			else if( y == "over" ){
				ResetPile(a);
				Pile(a).pop_back();
				m[a] = m[b];
				Pile(b).push_back(a);
			}
		}
		else if( x == "pile" ){
			if( y == "onto" ){
				ResetPile(b);
				MovePile(a, b);
			}
			else if( y == "over" ){
				MovePile(a, b);
			}
		}
		// print();
	}
	
	print();
	
	
	
}
