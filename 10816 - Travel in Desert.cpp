/**
	UVa 10816 - Travel in Desert
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.189s C++
	O(2n^3) time
*/
#include<iostream>
#include<cmath>
#define INF HUGE_VAL
#define eps 1e-6 //precision
using namespace std;
int n,e,a,b,s[10001],t[10001],prev[101][101];
float r[10001],adj[101][101],d[10005],mn;
float floydwarshall(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
			}
		}
	}
	return adj[a][b];
}
void floydwarshall2(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
					prev[i][j] = k;
				}
			}
		}
	}
}
void getPrev(int i,int j, bool p) {
	if(!prev[i][j]){
		if(!p) cout << i << ' ';
		cout << j;
		if(j!=b) cout << ' ';
	}
	else{
		getPrev(i,prev[i][j],p);
		getPrev(prev[i][j],j,true);
    }
}
int main(){
	cout.precision(1);
	cout << fixed;
	while(cin >> n >> e){
		cin >> a >> b;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				adj[i][j] = INF;
			}
		}
		for(int i=0;i<e;i++){
			cin >> s[i] >> t[i] >> r[i] >> d[i];
			adj[s[i]][t[i]] = min(adj[s[i]][t[i]],r[i]);
			adj[t[i]][s[i]] = min(adj[t[i]][s[i]],r[i]);
		}
        mn = floydwarshall();
		//re-floydwarshall
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				adj[i][j] = INF;
				prev[i][j] = 0;
			}
		}
		for(int i=0;i<e;i++){
			if(r[i]<mn+eps){
				//get min
				adj[s[i]][t[i]] = min(adj[s[i]][t[i]],d[i]);
				adj[t[i]][s[i]] = min(adj[t[i]][s[i]],d[i]);
			}
		}
		floydwarshall2();
		getPrev(a,b,false);
        cout << endl;
		cout << adj[a][b] << ' ' << mn << endl;
    }
}
