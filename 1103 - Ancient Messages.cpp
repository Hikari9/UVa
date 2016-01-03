/**
	UVa 1103 - Ancient Messages
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.038s C++
	O(4n^2) time
*/
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int h,w,hexIndex,k;
int c[201][201];
set<int> Set;
void print(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(c[i][j]==-1) cout << '-';
			else cout << c[i][j];
		}
		cout << endl;
	}
}
bool isBackgroundDFS(int x,int y){
	c[x][y]=-1;
	bool left(false),right(false),up(false),down(false);
	if(x>0){
		if(!c[x-1][y]) left = isBackgroundDFS(x-1,y);
	}
	else left = true;
	if(x+1<h){
		if(!c[x+1][y]) right = isBackgroundDFS(x+1,y);
	}
	else right=true;
	if(y>0){
		if(!c[x][y-1]) up = isBackgroundDFS(x,y-1);
	}
	else up=true;
	if(y+1<w){
		if(!c[x][y+1]) down = isBackgroundDFS(x,y+1);
	}
	else down=true;
	return left||right||up||down;
}
void dfs(int x, int y){
	c[x][y]=k;
	if(x>0 && c[x-1][y]==-1) dfs(x-1,y);
	if(x+1<h && c[x+1][y]==-1) dfs(x+1,y);
	if(y>0 && c[x][y-1]==-1) dfs(x,y-1);
	if(y+1<w && c[x][y+1]==-1) dfs(x,y+1);
}
void dfs2(int x, int y){
	c[x][y]=0;
	if(x>0 && c[x-1][y]){
		if(c[x-1][y]==1) dfs2(x-1,y);
		else Set.insert(c[x-1][y]);
	}
	if(x+1<h && c[x+1][y]){
		if(c[x+1][y]==1) dfs2(x+1,y);
		else Set.insert(c[x+1][y]);
	}
	if(y>0 && c[x][y-1]){
		if(c[x][y-1]==1) dfs2(x,y-1);
		else Set.insert(c[x][y-1]);
	}
	if(y+1<w && c[x][y+1]){
		if(c[x][y+1]==1) dfs2(x,y+1);
		else Set.insert(c[x][y+1]);
	}
}
int main(){
	char Hex[51], symbol[]=" WAKJSD";
	int r=0;
	while(cin >> h >> w, h||w){
		cin.get();
		for(int i=0;i<h;i++){
			cin >> Hex;
			for(int j=0;j<w;j++){
				k = j*4+3;
				if(Hex[j]>'9') hexIndex = Hex[j]-'a'+10;
				else hexIndex = Hex[j]-'0';
				for(int l=0;l<4;l++){
					c[i][k--] = (hexIndex%2);
					hexIndex >>= 1;
				}
			}
		}
		//floodfill
		w*=4;
		k=2; //cluster
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(!c[i][j]){
					if(!isBackgroundDFS(i,j)){
						dfs(i,j);
						k++;
					}
				}
			}
		}
		//get number of neighbor clusters
		cout << "Case " << ++r << ": ";
		string ans;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(c[i][j]==1){
					Set.clear();
					dfs2(i,j);
					ans.push_back(symbol[Set.size()]);
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans << endl;
	}
}
