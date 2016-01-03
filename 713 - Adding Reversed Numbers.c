/**
	UVa 713 - Adding Reversed Number
	by Rico Tiongson
	Submitted: May 14, 2013
	Accepted 0.009s C
	O(n) time
*/
#include<stdio.h>
#include<string.h>
int n,carry,i,alen,blen;
char a[100005],b[100005];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",a,b);
		alen = strlen(a);
		blen = strlen(b);
		carry = 0;
		if(alen<blen){
			for(i=0;i<alen;i++){
				b[i] += a[i]-'0'+carry;
				if(b[i]>'9'){
					b[i]-=10;
					carry = 1;
				}
				else carry = 0;
			}
			for(;i<blen;i++){
				if(carry){
					b[i]++;
					carry = (b[i]==':');
					if(carry) b[i]='0';
				}
				else break;
			}
			if(carry){
				b[blen++] = '1';
				b[blen] = 0;
			}
			for(i=blen-1;b[i]=='0';i--) b[i]=0;
			for(i=0;b[i]=='0';i++);
			puts(b+i);
		}
		else{
			for(i=0;i<blen;i++){
				a[i] += b[i]-'0'+carry;
				if(a[i]>'9'){
					a[i]-=10;
					carry = 1;
				}
				else carry = 0;
			}
			for(;i<alen;i++){
				if(carry){
					a[i]++;
					carry = (a[i]==':');
					if(carry) a[i]='0';
				}
				else break;
			}
			if(carry){
				a[alen++] = '1';
				a[alen] = 0;
			}
			for(i=alen-1;a[i]=='0';i--) a[i]=0;
			for(i=0;a[i]=='0';i++);
			puts(a+i);
		}
	}
}
