/**
	UVa 10336 - Rank the Languages
	by Rico Tiongson
	Submitted: September 27, 2013
	Accepted 0.019s C++
	O(n^2) time
*/
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, tc;
int r, c, i, j;
char **s, S;
map<char,int> m;
vector<pair<char,int> > v;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool cmp( const pair<char,int>& a, const pair<char,int>& b ){
	if( a.second==b.second ) return a.first < b.first;
	return a.second > b.second;
}
bool inRange( int x, int y ){
	return x>=0 && x<r && y>=0 && y<c;
}
void dfs( int x, int y ){
	if( !inRange(x,y) || s[x][y]!=S ) return;
	s[x][y] = '.';
	for( int k=0; k<4; ++k ){
		dfs(x+dx[k],y+dy[k]);
	}
}
int main(){
	scanf("%d",&n);
	while(tc<n){
		scanf("%d %d",&r,&c);
		s = new char*[r];
		for( i=0; i<r; ++i ){
			s[i] = new char[c+2];
			scanf("%s",s[i]);
		}
		m.clear();
		for( i=0; i<r; ++i ){
			for( j=0; j<c; ++j ){
				S = s[i][j];
				if( S!='.' ){
					++m[S];
					dfs(i,j);
				}
			}
		}
		v.assign(m.begin(),m.end());
		sort( v.begin(), v.end(), cmp );
		printf("World #%d\n",++tc);
		for( i=0; i<v.size(); ++i ){
			printf("%c: %d\n",v[i].first,v[i].second);
		}
		for( i=0; i<r; ++i ){
			delete[] s[i];
		}
		delete[] s;
	}
}
