/**
	UVa 1253 - Infected Land
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 1.272s C++
	O(n^4) time
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
typedef vector<string> state;
struct node{
	state s;
	int x, y, path;
	node(){}
	node(const node& N):
		s(N.s), x(N.x), y(N.y), path(N.path) {}
	node(const state& ST, int X, int Y, int p):
		s(ST), x(X), y(Y), path(p) {}
};
int n,dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
char buf[7];
state v;
set<state> visited;
bool inRange(int X, int Y){
	return X>=0 && X<n && Y>=0 && Y<n;
}
int count(const state& ST){
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ST[i][j]=='#') res++;
		}
	}
	return res;
}
int bfs(){
	int c = count(v);
	if(!c) return 0;
	queue<node> q;
	visited.clear();
	visited.insert(v);
	//find @
	int i, j;
	bool breaker=false;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(v[i][j]=='@'){
				breaker = true;
				break;
			}
		}
		if(breaker) break;
	}
	q.push(node(v,i,j,0));
	while(!q.empty()){
		node& E = q.front();
		E.path++;
		for(int k=0;k<8;k++){
			if(inRange(E.x+dx[k],E.y+dy[k]) && E.s[E.x+dx[k]][E.y+dy[k]]=='.'){
				E.s[E.x+dx[k]][E.y+dy[k]]='@';
				E.s[E.x][E.y] = '.';
				//make state
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						if(E.s[i][j]=='#'){
							//count two or three
							c=0;
							for(int l=0;l<8;l++){
								if(inRange(i+dx[l],j+dy[l]) && E.s[i+dx[l]][j+dy[l]]!='.') c++;
							}
							if(c==2 || c==3){ //infect
								v[i][j] = '#';
							}
							else v[i][j] = '.';
						}
						else if(E.s[i][j]=='.'){
							c=0;
							for(int l=0;l<8;l++){
								if(inRange(i+dx[l],j+dy[l]) && E.s[i+dx[l]][j+dy[l]]!='.') c++;
							}
							if(c==3){ //infect
								v[i][j] = '#';
							}
							else v[i][j] = '.';
						}
					}
				}
				//mark vehicle of new state
				v[E.x+dx[k]][E.y+dy[k]] = '@';
				c = count(v);
				if(!c) return E.path; //done!
				if(visited.insert(v).second) q.push(node(v,E.x+dx[k],E.y+dy[k],E.path)); //check if already in set :P
				E.s[E.x+dx[k]][E.y+dy[k]]='.'; //reinstate vehicle
				E.s[E.x][E.y] = '@';
			}
		}
		q.pop();
	}
	return -1;
}
int main(){
	while(scanf("%d",&n)!=EOF,n){
		v.clear();
		for(int i=0;i<n;i++){
			scanf("%s",buf);
			v.push_back(buf);
		}
		printf("%d\n",bfs());
	}
}
