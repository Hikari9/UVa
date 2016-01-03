/**
	UVa 247 - Calling Circles
	by Rico Tiongson
	Submitted: September 18, 2013
	Accepted 0.023s C++
	O(V+|E|) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#define MX 30
using namespace std;

map<string,int> name;
map<string,int>::iterator it;
const string* str[MX];
char str1[MX], str2[MX];

stack<int> S;
int id[MX], low[MX];
bool inStack[MX];
bool adj[MX][MX];

int n, m, a, b, tc, ID, i, top;
bool f;

void dfs( int x ){
	id[x] = low[x] = ID++;
	S.push(x);
	inStack[x] = 1;
	for( int j=0; j<n; ++j ){
		if( adj[x][j] ){
			if( id[j]==-1 ){
				dfs(j);
				low[x] = min( low[x], low[j] );
			}
			else if( inStack[j] )
				low[x] = min( low[x], id[j] );
		}
	}
	if( id[x]==low[x] ){
		f = false;
		do{
			if(f) printf(", ");
			else f = true;
			top = S.top(); S.pop();
			inStack[top] = false;
			cout << *str[top];
		} while( top!=x );
		putchar('\n');
	}
}

void tarjan(){
	memset( id, -1, sizeof id );
	memset( low, -1, sizeof low );
	memset( inStack, 0, sizeof inStack );
	S = stack<int>();
	ID = 0;
	for( i=0; i<n; ++i ){
		if( id[i]==-1 ){
			dfs(i);
		}
	}
}

int main(){
	while( scanf( "%d %d", &n, &m )==2 && ( n || m ) ){
		name.clear();
		if(tc) putchar('\n');
		memset( adj, 0, sizeof adj );
		while(m--){
			scanf( "%s %s", str1, str2 );
			a = name.insert( make_pair(str1,name.size()) ).first->second;
			b = name.insert( make_pair(str2,name.size()) ).first->second;
			adj[a][b] = 1;
		}
		for( it=name.begin(); it!=name.end(); ++it )
			str[it->second] = &it->first;
		printf( "Calling circles for data set %d:\n", ++tc );
		tarjan();
	}
}
