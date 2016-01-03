/**
	UVa 10957 - So Doku Checker
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.082s C++
	O(n^3) time
*/
#include<cstdio>
#include<cstring>
char c[20],buf[20];
int grid[9][9], i, j, r=0;
bool col[9][10], row[9][10], sub[3][3][10], flag;
bool dfs( int ro, int co ){
	if(co==9){
		co = 0;
		++ro;
	}
	if(ro==9){
		if(flag) return true;
		else{
			flag = true;
			return false;
		}
	}
	if(grid[ro][co]){
		if(dfs(ro,co+1)) return true;
	}
	else{
		for( int k=1; k<10; ++k ){
			if( !row[ro][k] && !col[co][k] && !sub[ro/3][co/3][k] ){
				grid[ro][co] = k;
				row[ro][k] = col[co][k] = sub[ro/3][co/3][k] = true;
				if(dfs(ro,co+1)) return true;
				row[ro][k] = col[co][k] = sub[ro/3][co/3][k] = false;
				grid[ro][co] = 0;
			}
		}
	}
	return false;
}
const char* solve(){
	if(!flag) return "Illegal.";
	flag = false;
	if(dfs(0,0)) return "Ambiguous.";
	if(flag) return "Unique.";
	return "Impossible.";
}
int main(){
	while( gets(c) ){
		flag = true;
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		memset(sub,0,sizeof(sub));
			for( j=0; j<9; ++j ){
				grid[0][j] = c[j<<1]-'0';
				if(grid[0][j]){
					if(grid[0][j]<0 || grid[0][j]>9){
						flag = false;
						break;
					}
					if(sub[0][j/3][grid[0][j]] || col[j][grid[0][j]] || row[0][grid[0][j]]){
						flag = false;
						break;
					}
					sub[0][j/3][grid[0][j]] = col[j][grid[0][j]] = row[0][grid[0][j]] = true;
				}
			}
		for( i=1; i<9; ++i ){
			gets(c);
			if(flag){
				for( j=0; j<9; ++j ){
					grid[i][j] = c[j<<1]-'0';
					if(grid[i][j]){
						if(grid[i][j]<0 || grid[i][j]>9){
							flag = false;
							break;
						}
						if(sub[i/3][j/3][grid[i][j]] || col[j][grid[i][j]] || row[i][grid[i][j]]){
							flag = false;
							break;
						}
						sub[i/3][j/3][grid[i][j]] = col[j][grid[i][j]] = row[i][grid[i][j]] = true;
					}
				}
			}
		}
		printf( "Case %d: %s\n", ++r, solve() );
		gets(buf);
	}
}
