/**
	UVa 820 - Internet Bandwidth
	by Rico Tiongson
	Submitted: May 22, 2013
	Accepted 0.036s C++
	O(Ef) time
*/
#include<iostream>
#include<queue>
#define INF 2147483647
#define mx 101
using namespace std;
int flow[mx][mx],prev[mx],n,Source,Sink,A,B,C,c,r=0;
//int cap[mx][mx]
int bfs(){
	for(int i=1;i<=n;i++) prev[i] = -2;
	prev[Source] = -1;
	int fr;
	queue<int> q;
	q.push(Source);
	while(!q.empty()){
		fr = q.front();
		q.pop();
		if(fr==Sink){
			int cf = INF;
			for(int i=Sink; prev[i]!=-1; i=prev[i])
				cf = min(cf,flow[prev[i]][i]);
			return cf;
		}
		for(int i=1;i<=n;i++){
			if(flow[fr][i] && prev[i]==-2){
				q.push(i);
				prev[i] = fr;
			}
		}
	}
	return 0; //no path found
}
int fordfulkerson(){
	int cf,tot(0);
	while((cf=bfs())){
		tot += cf;
		for(int i=Sink; prev[i]!=-1; i=prev[i]){
			flow[i][prev[i]] += cf;
			flow[prev[i]][i] -= cf; //reverse flow
		}
	}
	return tot;
}
void Connect(int a, int b, int w){
	flow[a][b] += w;
	flow[b][a] += w;
	//cap[a][b] += w;
	//cap[b][a] += w;
}
int main(){
	while(cin >> n,n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				flow[i][j] = 0;
		cin >> Source >> Sink >> c;
		while(c--){
			cin >> A >> B >> C;
			Connect(A,B,C);
		}
		cout << "Network " << ++r << endl << "The bandwidth is " << fordfulkerson() << '.' << endl << endl;
	}	
}
