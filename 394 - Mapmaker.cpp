/**
	UVa 394 - Mapmaker
	by Rico Tiongson
	Submitted: May 22, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
int dim[11],sum,N,R;
string s;
struct node{
	int B,D,*L,*U,*C;
	node(){
		int arraySize;
		cin >> B >> arraySize >> D;
		L = new int[D+1];
		U = new int[D+1];
		C = new int[D+1];
		C[D] = arraySize;
		for(int i=1;i<=D;i++) cin >> L[i] >> U[i];
		for(int i=D-1;i>0;i--) C[i] = C[i+1]*( U[i+1]-L[i+1]+1 );
		C[0] = B;
		for(int i=1;i<=D;i++) C[0] -= C[i]*L[i];
	}
	void calc(){
		sum = 0;
		for(int i=1;i<=D;i++) cin >> dim[i];
		for(int i=0;i<=D;i++) sum += C[i]*dim[i];
		
		cout.put('[');
		cout << dim[1];
		for(int i=2;i<=D;i++) cout << ", " << dim[i];
		cout << "] = " << sum << endl;
	}
};
map<string,node> m;
int main(){
	dim[0] = 1;
	cin >> N >> R;
	for(int i=0;i<N;i++){
		cin >> s;
		m[s];
	}
	for(int i=0;i<R;i++){
		cin >> s;
		cout << s;
		m[s].calc();
	}
}
