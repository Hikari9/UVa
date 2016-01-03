/**
	UVa 104 - Arbitrage
	by Rico Tiongson
	Submitted: May 3, 2013
	Accepted: 0.112s C++
	O(n^4) time
*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,path[22][22][22],temp; //for floyd-warshall
double d[22][22][22],x;
bool b;
stack<int> s;
void floydwarshall2(){
	for(int l=1;l<n;l++){
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					x = d[i][k][l-1]*d[k][j][0];
					if(d[i][j][l] < x){
						d[i][j][l] = x;
						path[i][j][l] = k; //depth
					}
				}
			}
		}
	}
	//get prevs
	b=false;
	for(int l=1;l<n&&!b;l++){
		for(int i=0;i<n;i++){
			if(d[i][i][l]>1.01){
				s.push(path[i][i][l]);
				for(int j=l-1;j>-1;j--) s.push(path[i][s.top()][j]);
				temp = s.top();
				while(!s.empty()){
					cout << s.top()+1 << ' ';
					s.pop();
				}
				cout << temp+1;
				b=true;
				break;
			}
		}
	}
	if(!b) cout << "no arbitrage sequence exists";
	cout << endl;
}
int main(){
	while(cin >> n){
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				cin >> d[i][j][0];
				path[i][j][0]=i;
			}
			d[i][i][0]=1.;
			path[i][i][0]=i;
			for(int j=i+1;j<n;j++){
				cin >> d[i][j][0];
				path[i][j][0]=i;
			}
		}
		floydwarshall2();
	}
}
