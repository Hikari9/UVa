/**
	UVa 314 - Robot
	by Rico Tiongson
	Submitted: May 13, 2013
	Accepted 0.032s C++
	O(4n^2) time
*/
#include<iostream>
#include<queue>
using namespace std;
int n,m,bx,by,ex,ey,dir;
char buf[120];
bool b[60][60];
bool v[60][60][4];
struct edge{
	int x,y,path,d;
	edge(){}
	edge(int x_, int y_, int path_, int d_):
		x(x_), y(y_), path(path_), d(d_) {}
}*E;
int bfs(){
	if(b[bx][by]) return -1;
	if(bx==ex&&by==ey) return 0;
	queue<edge> q;
	v[bx][by][dir] = true;
	q.push(edge(bx,by,0,dir));
	while(!q.empty()){
		E = &q.front();
		E->path++;
		//left
		dir = (E->d==0?3:E->d-1);
		if(!v[E->x][E->y][dir]){
			v[E->x][E->y][dir] = true;
			q.push(edge(E->x,E->y,E->path,dir));
		}
		//right
		dir = (E->d==3?0:E->d+1);
		if(!v[E->x][E->y][dir]){
			v[E->x][E->y][dir] = true;
			q.push(edge(E->x,E->y,E->path,dir));
		}
		//straight
		switch(E->d){
			case 0: //n x--
				E->x--;
				for(int i=0;i<3;i++,E->x--){
					if(b[E->x][E->y]) break;
					if(!v[E->x][E->y][E->d]){
						if(E->x==ex&&E->y==ey) return E->path;
						v[E->x][E->y][E->d] = true;
						q.push(*E);
					}
				}
				break;
			case 1: //e y++
				E->y++;
				for(int i=0;i<3;i++,E->y++){
					if(b[E->x][E->y]) break;
					if(!v[E->x][E->y][E->d]){
						if(E->x==ex&&E->y==ey) return E->path;
						v[E->x][E->y][E->d] = true;
						q.push(*E);
					}
				}
				break;
			case 2: //s x++
				E->x++;
				for(int i=0;i<3;i++,E->x++){
				if(b[E->x][E->y]) break;
					if(!v[E->x][E->y][E->d]){
						if(E->x==ex&&E->y==ey) return E->path;
						v[E->x][E->y][E->d] = true;
						q.push(*E);
					}
				}
				break;
			case 3: //w y--
				E->y--;
				for(int i=0;i<3;i++,E->y--){
					if(b[E->x][E->y]) break;
					if(!v[E->x][E->y][E->d]){
						if(E->x==ex&&E->y==ey) return E->path;
						v[E->x][E->y][E->d] = true;
						q.push(*E);
					}
				}
		}
		q.pop();
	}
	return -1;
}
int main(){
	for(int i=0;i<60;i++){
		b[i][0] = true;
		b[0][i] = true;
	}
	while(cin >> n >> m,n||m){
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				b[i][j] = false;
			}
		}
		for(int i=0;i<=n;i++) b[i][m] = true;
		for(int j=0;j<=m;j++) b[n][j] = true;
		cin.ignore();
		for(int i=0;i<n;i++){
			cin.getline(buf,120);
			for(int j=0;j<m;j++){
				if(buf[j*2]=='1'){
					b[i+1][j+1] = true;
					b[i+1][j] = true;
					b[i][j+1] = true;
					b[i][j] = true;
				}
			}
		}
		cin >> bx >> by >> ex >> ey >> buf;
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				for(int k=0;k<4;k++){
					v[i][j][k] = false;
				}
			}
		}
		switch(buf[0]){
			case 'n': dir=0; break;
			case 'e': dir=1; break;
			case 's': dir=2; break;
			case 'w': dir=3;
		}
		cout << bfs() << endl;
	}
}
