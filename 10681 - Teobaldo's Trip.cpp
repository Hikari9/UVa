/**
	UVa 10681 - Teobaldo's Trip
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted: 0.022s C++
	O(nD) time
*/
#include<iostream>
#include<cstring>
using namespace std;
bool a[103][103],d[203][103];
int C,L,A,B,S,E,D;
int main(){
	while(cin >> C >> L, C||L){
		memset(a,false,sizeof(a));
		memset(d,false,sizeof(d));
		for(int i=0;i<L;i++){
			cin >> A >> B;
			a[A][B]=true;
			a[B][A]=true;
		}
		cin >> S >> E >> D;
		d[0][S]=true;
		for(int i=0;i<D;i++){
			for(int j=1;j<=C;j++){
				if(d[i][j]){
					for(int k=1;k<=C;k++){
						if(a[j][k]){
							d[i+1][k]=true;
						}
					}
				}
			}
		}
		if(d[D][E]) cout << "Yes, Teobaldo can travel." << endl;
		else cout << "No, Teobaldo can not travel." << endl;
	}
}
