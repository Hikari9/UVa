/**
	UVa 12049 - Network Connections
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.262s C++
	O(logn) time
*/
#include<iostream>
#include<sstream>
using namespace std;
int *f,t,n,a,b,correct,wrong;
int find(int x){
	return f[x]==x ? x: f[x] = find(f[x]);
}
int main(){
	char c,buf[20005];
	cin >> t;
	while(t--){
		cin >> n;
		correct=0, wrong = 0;
		f = new int[n+1];
		for(int i=1;i<=n;i++) f[i] = i;
		cin.ignore();
		while(cin.getline(buf,20005),buf[0]!='\0'){
			istringstream(buf).get(c) >> a >> b;
			if(c=='c') f[find(a)] = find(b);
			else{
				if(find(a)==find(b)){
					correct++;
				}
				else wrong++;
			}
		}
		cout << correct << ',' << wrong << endl;
		if(t) cout << endl;
		delete[] f;
	}
}
