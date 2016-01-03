/**
	UVa 10037 - Bridge
	by Rico Tiongson
	Submitted: June 14, 2013
	Accepted 0.019s C++
	O(n/2) time
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int t, n, i, sum, mn[2], mx[2], r, x, y, B2, pq[1005], ans[15005], n2;
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d",&n);
		n2 = 0;
		if(!n) puts("0");
		else if(n==1){
			scanf("%d",&sum);
			printf("%d\n%d\n",sum,sum);
		}
		else{
			sum=0;
			scanf("%d%d",pq,pq+1);
			if( pq[0] < pq[1] ){
				mn[0] = 0;
				mn[1] = 1;
			}
			else{
				mn[1] = 0;
				mn[0] = 1;
			}
			for( i=2; i<n; ++i ){
				scanf("%d",pq+i);
				if( pq[i] < pq[mn[0]] ){
					mn[1] = mn[0];
					mn[0] = i;
				}
				else if( pq[i] < pq[mn[1]] ) mn[1] = i;
			}
			swap( pq[--n], pq[mn[0]] );
			if( n==mn[1] ) mn[1] = mn[0];
			mn[0] = pq[n];
			swap( pq[--n], pq[mn[1]] );
			mn[1] = pq[n];
			B2 = (pq[n]<<1);
			make_heap( pq, pq+n );
			while( n>1 ){
				mx[0] = pq[0];
				pop_heap( pq, pq+n );
				--n;
				mx[1] = pq[0];
				pop_heap( pq, pq+n );
				--n;
				if( mx[1]+mn[0] < B2 ){
					ans[n2] = mn[0]; ans[++n2] = mx[0];
					ans[++n2] = mn[0]; ans[++n2] = -1;
					ans[++n2] = mn[0]; ans[++n2] = mx[1];
					ans[++n2] = mn[0]; ans[++n2] = -1;
					++n2;
					sum += 2*mn[0] + mx[0] + mx[1];
				}
				else{
					ans[n2] = mn[0]; ans[++n2] = mn[1];
					ans[++n2] = mn[0]; ans[++n2] = -1;
					ans[++n2] = mx[1]; ans[++n2] = mx[0];
					ans[++n2] = mn[1]; ans[++n2] = -1;
					++n2;
					sum += B2 + mn[0] + mx[0];
				}
			}
			ans[n2] = mn[0]; ans[++n2] = mn[1];
			++n2;
			sum += mn[1];
			if(n==1){
				sum += mn[0]+pq[0];
				ans[n2] = mn[0]; ans[++n2] = -1;
				ans[++n2] = mn[0]; ans[++n2] = pq[0];
				++n2;
			}
			ans[n2] = -1;
			printf("%d\n",sum);
			for( i=0; i<n2; ++i ){
				printf("%d",ans[i]);
				if( ans[++i]!=-1 ) 
				printf(" %d",ans[i]);
				putchar('\n');
			}
		}
		if(--t) putchar('\n');
	}
}
