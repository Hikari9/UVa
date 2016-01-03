#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t[5][11],suit(0),id(0),r=0,ind[5]={10,10,10,5,4};
const char *w[]={"","DONG","NAN","XI","BEI"}, *d[]={"","ZHONG","FA","BAI"};
char buf[60],c[]={'T','S','W'};
bool hasWait;
void addtile(){
	if(isdigit(buf[0])){
		id = buf[0]-'0';
		if(buf[1]=='T') suit = 0;
		else if(buf[1]=='S') suit = 1;
		else if(buf[1]=='W') suit = 2;
	}
	else{
		hasWait = true;
		for(int i=1;i<5;i++){
			if(!strcmp(buf,w[i])){
				suit = 3;
				id = i;
				hasWait = false;
				break;
			}
		}
		if(hasWait){
			for(int i=1;i<4;i++){
				if(!strcmp(buf,d[i])){
					suit = 4;
					id = i;
					break;
				}
			}
		}
	}
	t[suit][id]++;
}
bool dfs(int melds){
	if(melds==4) return true;
	for(int i=0;i<5;i++){
		for(int j=1;j<ind[i];j++){
			if(t[i][j]>2){
				t[i][j]-=3;
				if(dfs(melds+1)){
					t[i][j]+=3;
					return true;
				}
				t[i][j]+=3;
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=1;j<8;j++){
			if(t[i][j]>0 && t[i][j+1]>0 && t[i][j+2]>0){
				t[i][j]--, t[i][j+1]--, t[i][j+2]--;
				if(dfs(melds+1)){
					t[i][j]++, t[i][j+1]++, t[i][j+2]++;
					return true;
				}
				t[i][j]++, t[i][j+1]++, t[i][j+2]++;
			}
		}
	}
	return false;
}
bool dfs(){
	for(int i=0;i<5;i++){
		for(int j=1;j<ind[i];j++){
			if(t[i][j]>1){
				t[i][j]-=2; //mark eye
				if(dfs(0)){
					t[i][j]+=2;
					return true;
				}
				t[i][j]+=2;
			}
		}
	}
	return false;
}
void getWaits(){
	hasWait=false;
	for(int i=0;i<5;i++){
		for(int j=1;j<ind[i];j++){
			if(t[i][j]<4){
				t[i][j]++;
				if( dfs() ){
					hasWait = true;
					cout << ' ';
					if(i<3) cout << j << c[i];
					else if(i==3) cout << w[j];
					else cout << d[j];
				}
				t[i][j]--;
			}
		}
	}
	if(!hasWait) cout << " Not ready";
	cout << endl;
}
int main(){
	while(cin >> buf, buf[0]!='0'){
		memset(t,0,sizeof(t));
		addtile();
		for(int i=1;i<13;i++){
			cin >> buf;
			addtile();
		}
		cout << "Case " << ++r << ":";
		getWaits();
	}
}
