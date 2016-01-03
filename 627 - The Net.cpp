/**
	UVa 627 - The Net
	by Rico Tiongson
	Submitted: October 17, 2013
	Accepted 0.026s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#define INF 2000000000

using namespace std;
typedef pair<int, int> edge;

int n, m, a, b;
char buf[999999], *p;
int path[305], prev[305];
vector<int> adj[305];
map<int, int> id;
int GetId[305];

void bfs(){
	for( int i=0; i<n; ++i ){
		path[i] = INF;
		prev[i] = -1;
	}
	queue<edge> q;
	path[b] = 0;
	if( a == b ) goto done;
	q.push( edge(b, 0) );
	while( !q.empty() ){
		edge E = q.front(); q.pop();
		for( int i=0; i<adj[E.first].size(); ++i ){
			int next = adj[E.first][i];
			if( E.second + 1 < path[next] ){
				path[next] = E.second + 1;
				prev[next] = E.first;
				if( next == a ) goto done;
				q.push( edge(next, path[next]) );
			}
		}
	}
	cout << "connection impossible" << endl;
	return;
	done:
	int p = a;
	while( p != -1 )
	{
		if( p!=a ) cout << ' ';
		cout << GetId[p];
		p = prev[p];
	}
	cout << endl;
}

int main(){
	while( cin >> n ){
		cout << "-----" << endl;
		id.clear();
		for( int i=0; i<305; ++i ) adj[i].clear();
		for( int i=0; i<n; ++i ){
			scanf( "%d-", &a );
			gets(buf);
			// cout << a << " " << buf << endl;
			a = id.insert( make_pair( a, id.size() ) ).first->second;
			for( p=strtok(buf, ","); p; p=strtok(NULL, ",") ){
				sscanf( p, "%d", &b );
				b = id.insert( make_pair( b, id.size() ) ).first->second;
				adj[b].push_back(a);
			}
		}
		for( map<int, int>::iterator it = id.begin(); it != id.end(); ++it ){
			GetId[it->second] = it->first;
		}
		for( int i=0; i<n; ++i )
			sort( adj[i].begin(), adj[i].end() );
		n = id.size();
		cin >> m;
		while(m--){
			cin >> a >> b;
			a = id[a];
			b = id[b];
			bfs();
		}
	}
}
