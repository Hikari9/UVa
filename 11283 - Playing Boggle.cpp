/**
	UVa 11283 - Playing Boggle
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int t,n,score,len;
bool ok;
char c[5][5],word[18];
bool dfs(int x, int y, int depth){
	if(++depth>=len) return true;
	c[x][y]='.'; //visit
	bool flag[4]={ (x>0), (x<3), (y>0), (y<3) };
	if(flag[0]){
		if(c[x-1][y]==word[depth]){ if(dfs(x-1,y,depth)){ c[x][y] = word[--depth]; return true; }}
		if(flag[2] && c[x-1][y-1]==word[depth]){ if(dfs(x-1,y-1,depth)){ c[x][y] = word[--depth]; return true; }}
		if(flag[3] && c[x-1][y+1]==word[depth]){ if(dfs(x-1,y+1,depth)){ c[x][y] = word[--depth]; return true; }}
	}
	if(flag[2] && c[x][y-1]==word[depth]){ if(dfs(x,y-1,depth)){ c[x][y] = word[--depth]; return true; }}
	if(flag[3] && c[x][y+1]==word[depth]){  if(dfs(x,y+1,depth)){ c[x][y] = word[--depth]; return true; }}
	if(flag[1]){
		if(c[x+1][y]==word[depth]){ if(dfs(x+1,y,depth)){ c[x][y] = word[--depth]; return true; }}
		if(flag[2] && c[x+1][y-1]==word[depth]){ if(dfs(x+1,y-1,depth)){ c[x][y] = word[--depth]; return true; }}
		if(flag[3] && c[x+1][y+1]==word[depth]){ if(dfs(x+1,y+1,depth)){ c[x][y] = word[--depth]; return true; }}
	}
	c[x][y] = word[--depth]; //unvisit
	return false;
}
int main(){
	cin >> t;
	for(int r=1;r<=t;r++){
		cin >> c[0] >> c[1] >> c[2] >> c[3] >> n;
		score=0;
		while(n--){
			cin >> word;
			len = strlen(word);
			ok = false;
			for(int i=0;i<4&&!ok;i++){
				for(int j=0;j<4;j++){
					if(c[i][j]==word[0]){
						if(dfs(i,j,0)){
							switch(len){
								case 3: score++; break;
								case 4: score++; break;
								case 5: score+=2; break;
								case 6: score+=3; break;
								case 7: score+=5; break;
								default: score+=11;
							}
							ok = true;
							break;
						}
					}
				}
			}
		}
		cout << "Score for Boggle game #" << r << ": " << score << endl;
	}
}
