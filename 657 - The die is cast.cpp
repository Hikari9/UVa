/**
	UVa 657 - The die is cast
	by Rico Tiongson
	Submitted: May 21, 2013
	Accepted 0.016s C++
	O(hw) time
*/

#include<cstdio>
#include<set>
using namespace std;

int w,h,count(0),clusters;
char c[55][55];
multiset<int> ans;
multiset<int>::iterator it;

void dfs(int x, int y){
	c[x][y] = '*';
	if(x>0){
		if(c[x-1][y]=='X') dfs(x-1,y);
	}
	if(x<h-1){
		if(c[x+1][y]=='X') dfs(x+1,y);
	}
	if(y>0){
		if(c[x][y-1]=='X') dfs(x,y-1);
	}
	if(y<w-1){
		if(c[x][y+1]=='X') dfs(x,y+1);
	}
}

void dfs2(int x, int y){
	c[x][y] = '.';
	if(x>0){
		if(c[x-1][y]=='X'){
			clusters++;
			dfs(x-1,y);
		}
		if(c[x-1][y]=='*') dfs2(x-1,y);
	}
	if(x<h-1){
		if(c[x+1][y]=='X'){
			clusters++;
			dfs(x+1,y);
		}
		if(c[x+1][y]=='*') dfs2(x+1,y);
	}
	if(y>0){
		if(c[x][y-1]=='X'){
			clusters++;
			dfs(x,y-1);
		}
		if(c[x][y-1]=='*') dfs2(x,y-1);
	}
	if(y<w-1){
		if(c[x][y+1]=='X'){
			clusters++;
			dfs(x,y+1);
		}
		if(c[x][y+1]=='*') dfs2(x,y+1);
	}
}

int main(){
	while(scanf("%d %d",&w,&h)!=EOF, w||h){
		ans.clear();
		for(int i=0;i<h;i++) scanf("%s",c[i]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(c[i][j]=='*'){
					clusters=0;
					dfs2(i,j);
					ans.insert(clusters);
				}
				else if(c[i][j]=='X'){
					clusters=1;
					dfs(i,j);
					dfs2(i,j);
					ans.insert(clusters);
				}
		printf("Throw %d\n",++count);
		it = ans.begin();
		if(it!=ans.end()){
			printf("%d",*it);
			while(++it!=ans.end()) printf(" %d",*it);
		}
		puts("\n");
	}
}
