/**
	UVa 1180 - Perfect Numbers
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.009s C
	O(1) time
*/
#include<stdio.h>
#include<string.h>
int n,len;
char buf[1000005],*p;
int isPerfect(){
	len = strlen(p);
	switch(len){
		case 1:
			switch(p[0]){
				case '2': case '3': case '5': case '7': return 1;
				break;
			}
			break;
		case 2:
			if(p[0]=='1'){
				switch(p[1]){
					case '3': case '7': case '9': return 1;
				}
			}
			break;
	}
	return 0;
}
int main(){
	scanf("%d\n",&n);
	gets(buf);
	p = strtok(buf,",");
	do{
		if(isPerfect()) puts("Yes");
		else puts("No");
		p = strtok(NULL,",");
	} while(--n);
}
