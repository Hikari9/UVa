/**
	UVa 12150 - Pole Position
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.019s C++
	O( nlogn ) time
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n, i, total;
pair<int,int> a[1001];
bool cmp( const pair<int,int>& lhs, const pair<int,int>& rhs ){
	return lhs.second < rhs.second;
}
void print(){
	printf("%d", a[0].first );
	for( i=1; i<n; ++i ) printf(" %d", a[i].first);
	putchar('\n');
}
bool mali(){
	if( total ) return true;
	total = n;
	make_heap( a, a+total, cmp );
	while( total ){
		pop_heap( a, a+total, cmp );
		if( --total!=a[total].second ) return true;
	}
	return false;
}
int main(){
	scanf ("%d", &n );
	while( n ){
		total = 0;
		for( i=0; i<n; ++i ){
			scanf("%d %d", &a[i].first, &a[i].second);
			total += a[i].second;
			a[i].second += i;
		}
		if( mali() ) puts("-1");
		else print();
		scanf ("%d", &n );
	}
}
