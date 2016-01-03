/**
	UVa 10685 - Nature
	by Rico Tiongson
	Submitted: June 11, 2013
	Accepted 0.139s C++
	O(logn) time
*/
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int f[5001], v[5001];
int find( int x ){
	return x==f[x] ? x : f[x] = find(f[x]);
}
map<string,int> I;
int c, r;
char buf[35], buf2[35];
int main(){
	scanf("%d %d", &c, &r);
	while( c || r ){
		I.clear();
		for( int i=0; i<c; ++i ){
			scanf("%s",buf);
			f[i] = I[ buf ] = i;
			v[i] = 0;
		}
		while( r ){
			scanf("%s %s",buf,buf2);
			f[ find(I[buf]) ] = find(I[buf2]);
			--r;
		}
		for( int i=0; i<c; ++i ){
			r = max(r,++v[ find(i) ]);
		}
		printf("%d\n", r);
		scanf("%d %d", &c, &r);
	}
}
