/**
	UVa 208 - Firetruck
	by Rico Tiongson
	Submitted: May 5,2013
	Accepted: 0.012s C++
	O( |V| + E ) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int prev[22],n,a,b,c,r=0;
bool g[22][22],v[22],can[22];
void mark(int next){
	can[next]=true;
	for(int i=1;i<22;i++){
		if(g[next][i]&&!can[i]) mark(i);
	}
}
bool dfs(int next){
	if(next==n){
		cout << "1 ";
		next = prev[1];
		while(next!=n){
			cout << next << ' ';
			next = prev[next];
		}
		cout << next << endl;
		c++;
	}
	else{
		v[next]=true;
		for(int j=2;j<22;j++){
			if(can[j]&&!v[j]&&g[next][j]){
				prev[next]=j;
				dfs(j);
			}
		}
		v[next]=false;
	}
}
int main(){
	while(cin >> n){
		memset(g,false,sizeof(g));
		memset(v,false,sizeof(v));
		memset(can,false,sizeof(can));
		while(cin >> a >> b,a&&b){
			g[a][b]=true;
			g[b][a]=true;
		}
		cout << "CASE " << ++r << ':' << endl;
		c=0;
		mark(n);
		if(can[1]){
			for(int j=2;j<22;j++){
				if(can[j]&&g[1][j]){
					prev[1]=j;
					dfs(j);
				}
			}
		}
		cout << "There are " << c << " routes from the firestation to streetcorner " << n << '.' << endl;
	}
}
