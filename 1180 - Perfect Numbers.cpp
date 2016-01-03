/**
	UVa 1180 - Perfect Numbers
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.016s C++
	O(1) time
*/
#include<cstdio>
#include<cstring>
int n,len;
char buf[1000005],*p;
bool isPerfect(){
	len = strlen(p);
	switch(len){
		case 1:
			switch(p[0]){
				case '2': case '3': case '5': case '7': return true;
				break;
			}
			break;
		case 2:
			switch(p[0]){
				case '1':
					switch(p[1]){
						case '3': case '7': case '9': return true;
						break;
					}
				break;
			}
			break;
	}
	return false;
}
int main(){
	scanf("%d\n",&n);
	gets(buf);
	if(n){
		p = strtok(buf,",");
		do{
			if(isPerfect()) puts("Yes");
			else puts("No");
			p = strtok(NULL,",");
		} while(--n);
	}
}
