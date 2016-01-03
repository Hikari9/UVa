/**
	UVa 1237 - Expert Enough?
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.029 C++
	O(n) time
*/
#include<cstdio>
struct car{
	char data[25];
	int lo, hi;
	void in(){
		scanf("%s %d %d",data,&lo,&hi);
		getchar();
	}
} D[10001];
int t, d, a, b, i, I;
int Intersect(){
	I = -1;
	for( i=0; i<d; ++i ){
		if( b<=D[i].hi && b>=D[i].lo ){
			if(I!=-1) return -1;
			I = i;
		}
	}
	return I;
}
int main(){
	scanf("%d",&t);
	getchar();
	while(t--){
		scanf("%d",&d);
		getchar();
		for( i=0; i<d; ++i ) D[i].in();
		scanf("%d",&a);
		getchar();
		while(a--){
			scanf("%d",&b);
			getchar();
			if(Intersect()==-1) puts("UNDETERMINED");
			else puts(D[I].data);
		}
		if(t) putchar('\n');
	}
}
