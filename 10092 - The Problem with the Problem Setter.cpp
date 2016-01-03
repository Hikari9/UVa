/**
	UVa 10092 - The Problem with the Problem Setter
	by Rico Tiongson
	Submtited: Feb 27, 2014
	Accepted 0.122s C++
	Edmonds-Karp (maxflow)
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#define INF 2147483647

using namespace std;

int nk, np;
map<int, int> flow[1024];
int cap[25];

const int s = 0;
const int t = 1;

int prev[1024], bottle[1024];

bool bfs(){
	memset( prev, -1, sizeof prev );
	queue<int> q;
	q.push( s );
	prev[s] = s;
	bottle[s] = INF;
	while( !q.empty() ){
		int u = q.front(); q.pop();
		for( map<int, int>::iterator it = flow[u].begin(); it != flow[u].end(); ++it ){
			int v = it->first;
			int fl = it->second;
			if( fl == 0 || prev[v] != -1 ) continue;
			bottle[v] = min( bottle[u], fl );
			prev[v] = u;
			if( v == t ) return true;
			q.push( v );
		}
	}
	return false;
}

int EdmondsKarp(){
	while( bfs() ){
		int b = bottle[t];
		int v = t;
		while( prev[v] != v ){
			int u = prev[v];
			flow[u][v] -= b;
			flow[v][u] += b;
			v = u;
		}
	}
	int maxFlow = 0;
	for( map<int, int>::iterator it = flow[t].begin(); it != flow[t].end(); ++it ){
		maxFlow += it->second;
	}
	return maxFlow;
}

int main(){
	while( cin >> nk >> np, nk || np ){
		for( int i=0; i<1024; ++i ) flow[i].clear();
		int sum = 0;
		for( int i=0; i<nk; ++i ){
			int x;
			cin >> x;
			flow[i+2][t] = x;
			sum += x;
		}
		for( int i=0; i<np; ++i ){
			flow[s][nk+2+i] = 1;
			int k;
			cin >> k;
			
			for( int j=0; j<k; ++j ){
				int cat;
				cin >> cat;
				flow[nk+2+i][cat+1] = 1;
			}
		}
		int fl = EdmondsKarp();
		if( fl != sum ){
			cout << "0" << endl;
		}
		else{
			cout << "1" << endl;
			for( int i=0; i<nk; ++i ){
				bool first = true;
				for( map<int, int>::iterator it = flow[i+2].begin(); it != flow[i+2].end(); ++it ){
					if( it->first >= nk + 2 && it->second > 0 ){
						if( first ) first = false;
						else cout << " ";
						cout << it->first - ( nk + 1 );
					}
				}
				cout << endl;
			}
		}
		
	}
}
