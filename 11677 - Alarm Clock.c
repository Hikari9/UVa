/**
	UVa 11677 - Alarm Clock
	by Rico Tiongson
	Submitted: May 27, 2013
	Accepted 0.012s C
	O(1) time
*/
#include<stdio.h>
unsigned h1,h2,m1,m2;
int main(){
	scanf("%u %u %u %u",&h1,&m1,&h2,&m2);
	while(h1||h2||m1||m2){
		m1 += h1*60u;
		m2 += h2*60u;
		if(m2<m1) m2+=1440u;
		printf("%u\n",m2-m1);
		scanf("%u %u %u %u",&h1,&m1,&h2,&m2);
	}
}
