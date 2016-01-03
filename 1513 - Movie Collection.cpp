/**
	UVa 1513 - Movie collection
	by Rico Tiongson
	Submitted: May 21, 2013
	Accepted 0.192s C++
	O(3logn) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005],b[100005],c[300005],t,n,m,x,offset;
int LastBit(int y){
    return y&(-y);
}
int calc(int y){
    int sum=0;
    while(y>0){
        sum+=c[y];
        y-=LastBit(y);
    }
    return sum;
}
void insert(int y,int z){
    while(y<=offset){
        c[y]+=z;
        y+=LastBit(y);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
		offset = n+100000;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++) a[i]=i+100000;
        for(int i=100002;i<=offset;i++) insert(i,1);
        for(int i=1;i<=m;i++){
            scanf("%d",&x);
            b[i]=calc(a[x]);
            insert(a[x],-1);
            insert(100002-i,1);
            a[x]=100001-i;
        }
        for(int i=1;i<m;i++) printf("%d ",b[i]);
		printf("%d\n",b[m]);
    }
}
