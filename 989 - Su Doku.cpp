/**
	UVa 989 - Su Doku
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.019s C++
	O(n^3) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char C,one, c[10][20];
int grid[9][9], i, j, mx, subdiv;
bool col[9][10], row[9][10], sub[3][3][10], f(false);
bool dfs( int ro, int co ){
	if(co==mx){
		co = 0;
		++ro;
	}
	if(ro==mx) return true;
	if(grid[ro][co]){
		if(dfs(ro,co+1)) return true;
	}
	else{
		for( int k=1; k<=mx; ++k ){
			if( !row[ro][k] && !col[co][k] && !sub[ro/subdiv][co/subdiv][k] ){
				grid[ro][co] = k;
				row[ro][k] = col[co][k] = sub[ro/subdiv][co/subdiv][k] = true;
				if(dfs(ro,co+1)) return true;
				row[ro][k] = col[co][k] = sub[ro/subdiv][co/subdiv][k] = false;
				grid[ro][co] = 0;
			}
		}
	}
	return false;
}
void solve(){
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	memset(sub,0,sizeof(sub));
	for( i=0; i<mx; ++i ){
		gets(c[i]);
	}
	for( i=0; i<mx; ++i ){
		for( j=0; j<mx; ++j ){
			grid[i][j] = c[i][j<<1]-'0';
			if(grid[i][j]){
				if(sub[i/subdiv][j/subdiv][grid[i][j]] || col[j][grid[i][j]] || row[i][grid[i][j]]){
					puts("NO SOLUTION");
					return;
				}
				sub[i/subdiv][j/subdiv][grid[i][j]] = col[j][grid[i][j]] = row[i][grid[i][j]] = true;
			}
		}
	}
	if(dfs(0,0)){
		for( i=0; i<mx; ++i ){
			putchar(grid[i][0]+'0');
			for( j=1; j<mx; ++j ){
				putchar(' ');
				putchar(grid[i][j]+'0');
			}
			putchar('\n');
		}
	}
	else puts("NO SOLUTION");
}
int main(){
	while( cin >> C ){
		if(f) putchar('\n');
		else f = true;
		getchar();
		if(C=='1'){
			one = getchar();
			getchar();
			if(one=='0') putchar('1');
			else putchar(one);
			putchar('\n');
		}
		else if(C=='2'){
			mx = 4;
			subdiv = 2;
			solve();
		}
		else{
			mx = 9;
			subdiv = 3;
			solve();
		}
	}
}
