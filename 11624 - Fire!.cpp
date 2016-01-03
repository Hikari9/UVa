/**
	UVa 11624 - Fire!
	by Rico Tiongson
	Submitted: May 9, 2013
	Accepted 0.546s C++
	O(8n) time
*/
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> Point;
typedef pair<Point,int> edge;
int t,n,m,BFS,dx[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char c[1001][1001];
bool inRange(const Point& P){
	return !(P.first==-1 || P.second==-1 || P.first==n || P.second==m);
}
bool notFire(const Point& P){
	if(inRange(P)){
		if(c[P.first][P.second]=='.'||c[P.first][P.second]=='J'){
			c[P.first][P.second] = 'F';
			return true;
		}
	}
	return false;
}
bool notJoe(const Point& P){
	if(c[P.first][P.second] == '.'){
		c[P.first][P.second] = 'J';
		return true;
	}
	return false;
}
int bfs(){
	queue<edge> joe,fire;
	bool flagj=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(flagj && c[i][j]=='J'){
				joe.push(edge(Point(i,j),1));
				flagj=false;
			}
			if(c[i][j]=='F'){
				fire.push(edge(Point(i,j),1));
			}
		}
	}
	edge f;
	Point temp;
	int currentDepth=1;
	while(!joe.empty()){
		//spread fire
		while(!fire.empty()){
			f = fire.front();
			if(f.second!=currentDepth) break;
			for(int i=0;i<4;i++){
				temp = Point(f.first.first+dx[i][0],f.first.second+dx[i][1]);
				if(notFire(temp)){
					fire.push(edge(temp,currentDepth+1));
				}
			}
			fire.pop();
		}
		//animate joe
		while(!joe.empty()){
			f = joe.front();
			if(f.second!=currentDepth) break;
			for(int i=0;i<4;i++){
				temp = Point(f.first.first+dx[i][0],f.first.second+dx[i][1]);
				if(!inRange(temp)) return currentDepth;
				if(notJoe(temp)) joe.push(edge(temp,currentDepth+1));
			}
			joe.pop();
		}
		currentDepth++;
	}
	return -1;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		cin.get();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> c[i][j];
			}
		}
		BFS = bfs();
		if(BFS==-1) cout << "IMPOSSIBLE" << endl;
		else cout << BFS << endl;
	}
}
