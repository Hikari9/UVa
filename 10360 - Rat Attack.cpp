/**
	UVa 10360 - Rat Attack
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.252s C++
	O(nd) time
*/
#include<iostream>
#include<cstring>
using namespace std;
long long t,d,n,x,y,z,dx[2],dy[2],a[1025][1025],mx;
bool inRange(int X, int Y){
	return X>=0 && X<1025 && Y>=0 && Y<1025;
}
void bfs(long long depth){
	if(depth<=0) a[x][y]+=z;
	else{
		dx[0] = x-depth;
		dx[1] = x+depth;
		dy[0] = y-depth;
		dy[1] = y+depth;
		for(int i=dx[0];i<=dx[1];i++){
			if(inRange(i,dy[0])){
				a[i][dy[0]]+=z;
				if(a[i][dy[0]]>mx) mx=a[i][dy[0]];
			}
			if(inRange(i,dy[1])){
				a[i][dy[1]]+=z;
				if(a[i][dy[1]]>mx) mx=a[i][dy[1]];
			}
		}
		for(int i=dy[0]+1;i<dy[1];i++){
			if(inRange(dx[0],i)){
				a[dx[0]][i]+=z;
				if(a[dx[0]][i]>mx) mx=a[dx[0]][i];
			}
			if(inRange(dx[1],i)){
				a[dx[1]][i]+=z;
				if(a[dx[1]][i]>mx) mx=a[dx[1]][i];
			}
		}
		bfs(depth-1);
	}
}
int main(){
	cin >> t;
	while(t--){
		cin >> d >> n;
		memset(a,0,sizeof(a));
		mx=0;
		while(n--){
			cin >> x >> y >> z;
			bfs(d);
		}
		for(int i=0;i<1025&&mx!=-1;i++)
		for(int j=0;j<1025;j++)
		if(a[i][j]==mx){
			cout << i << ' ' << j << ' ' << mx << endl;
			mx = -1;
			break;
		}
	}
}
