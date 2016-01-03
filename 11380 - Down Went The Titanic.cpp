/**
	UVa 11380 - Down Went The Titanic
	by Rico Tiongson
	Submitted: July 6, 2014
	Accepted 0.199s C++
	MaxFlow
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#define INF 2147483647
using namespace std;

char board[35][35];
int id[35][35];
map<int, map<int, int> > flow;
int X, Y, P, n, prev[1805];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inRange( int x, int y ){
	return x >= 0 && x < X && y >= 0 && y < Y;
}

int bfs( int source, int sink ){
	queue<int> q;
	q.push(source);
	memset( prev, -1, sizeof prev );
	prev[source] = -2;
	while( !q.empty() ){
		int x = q.front(); q.pop();
		if( x == sink ){
			int cf = INF;
			for( int i = sink; prev[i] != -2; i = prev[i] ){
				cf = min( cf, flow[prev[i]][i] );
			}
			return cf;
		}
		map<int, int>& node = flow[x];
		for( map<int, int>::iterator it = node.begin(); it != node.end(); ++it ){
			if( it->second > 0 && prev[it->first] == -1 ){
				prev[it->first] = x;
				q.push( it->first );
			}
		}
	}
	return 0;
}

int maxFlow( int source, int sink ){
	int cf, tot=0;
	while( cf = bfs(source, sink) ){
		for( int i=sink; prev[i] != -2; i = prev[i] ){
			flow[prev[i]][i] -= cf;
			flow[i][prev[i]] += cf;
		}
		tot += cf;
	}
	return tot;
}

int main(){
	while( cin >> X >> Y >> P ){
		n = 2;
		for( int i=0; i<X; ++i ){
			for( int j=0; j<Y; ++j ){
				cin >> board[i][j];
				id[i][j] = n++;
			}
		}
		flow.clear();
		int source = 0, sink = 1;
		for( int i=0; i<X; ++i ){
			for( int j=0; j<Y; ++j ){
				int I = id[i][j];
				// capacity
				switch( board[i][j] ){
					case '*': 
						flow[source][I] = 1;
					case '.': 
						flow[I][I+n] = 1;
						break;
					case '#':
						flow[I+n][sink] = P;
						flow[I][I+n] = INF;
						break;
					case '@':
						flow[I][I+n] = INF;
						break;
				}
				// outward flow
				for( int k=0; k<4; ++k ){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if( inRange(nx, ny) ){
						int J = id[nx][ny];
						switch( board[i][j] ){
							case '*': case '.':
								if( board[nx][ny] != '*' && board[nx][ny] != '~' )
									flow[I+n][J] = 1;
								break;
							case '@': case '#':
								if( board[nx][ny] != '*' && board[nx][ny] != '~' )
									flow[I+n][J] = INF;
								break;
						}
					}
				}
			}
		}
		cout << maxFlow( source, sink ) << endl;
	}
}
