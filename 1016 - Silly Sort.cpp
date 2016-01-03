/**
	UVa 1016 - Silly Sort
	by Rico Tiongson
	Submitted: June 14, 2013
	Accepted 0.049s C++
	O(2nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define mx 100001
using namespace std;
int a[mx], pos[mx], n, i, r=0, ans, mn, x, sum, j, mini, y, z;
map<int,int> m;
map<int,int>::iterator it;
bool v[mx];
int main(){
	scanf("%d",&n);
	while( n ){
		memset(v,0,n);
		m.clear();
		for( i=0; i<n; ++i ){
			getchar();
			scanf("%d",a+i);
			m[ a[i] ] = i;
		}
		for( i=0, it=m.begin(); it!=m.end(); ++it, ++i ) pos[it->second] = i;
		mini = m.begin()->first;
		ans = 0;
		for( i=0; i<n; ++i ){
			if( !v[i] ){
				if( pos[i]==i ) v[i] = true;
				else{
					x = -1;
					sum = 0;
					j = i;
					mn = a[i];
					while( !v[j] ){
						++x;
						sum += a[j];
						if( a[j]<mn ) mn = a[j];
						v[j] = true;
						j = pos[j];
					}
					sum -= mn; // double count
					ans += sum + mn*(x);
					// try use very min val
					y = (mini+mn)<<1;
					z = x*(mn-mini);
					if( y<z ) ans -= z-y;
				}
			}
		}
		getchar();
		printf( "Case %d: %d\n\n", ++r, ans );
		scanf("%d",&n);
	}
}
