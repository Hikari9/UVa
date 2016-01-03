/**
	UVa 790 - Head Judge Headache
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.086s C++
	O(nlogn) time
*/
#include<iostream>
#include<sstream>
#include<set>
#include<cstdio>
#include<algorithm>
#define INF 2147483647
using namespace std;
int mxid;
// int ID(0);
struct team{
	int id,time,solved,subs;
	set<int> wrongs[7];
	int Sub[7];
	bool ok;
	// team():id(ID++),time(0),solved(0),subs(0),ok(false){
		// for(int i=0;i<7;i++)
			// Sub[i][0] = Sub[i][1] = 0;
	// }
	void reset(int i){
		id = i;
		time = solved = subs = 0;
		ok = false;
		
		for(i=0;i<7;i++){
			Sub[i] = INF;
			wrongs[i].clear();
		}
	}
	void update(){
		for(int i=0;i<7;i++){
			if(Sub[i]!=INF){
				solved++;
				int j=0;
				for(set<int>::iterator it=wrongs[i].begin();it!=wrongs[i].end();it++,j++){
					if(*it>Sub[i]) break;
				}
				subs+=j+1;
				time+=Sub[i]+20*j;
			}
		}
	}
	bool operator<(const team& rhs)const{
		// if(!ok) return false;
		// if(!rhs.ok) return true;
		if(solved==rhs.solved){
			if(time==rhs.time){
				return id<rhs.id;
			}
			return time<rhs.time;
		}
		return solved>rhs.solved;
	}
	bool rank(const team& rhs)const{
		if(time==rhs.time&&solved==rhs.solved) return false;
		return true;
	}
} t[26];
int main(){
	int n,id,h,m,rank;
	char p,v,buf[50];
	scanf("%d\n\n",&n);
	while(n--){
		for(int i=1;i<26;i++) t[i].reset(i);
		while(cin.getline(buf,50),buf[0]!='\0'){
			sscanf(buf,"%d %c %d:%d %c",&id,&p,&h,&m,&v);
			t[id].ok = true;
			m+=60*h;
			if(v=='Y'){
				if(t[id].Sub[p-'A']>m) t[id].Sub[p-'A'] = m;
			}
			else t[id].wrongs[p-'A'].insert(m);
		}
		for(int i=25;i>0;i--){
			if(t[i].ok){
				mxid = i;
				break;
			}
		}
		printf("RANK TEAM PRO/SOLVED TIME\n");
		for(int i=1;i<=mxid;i++) t[i].update();
		sort(t+1,t+mxid+1);
		printf("%4d %4d",1,t[1].id);
		if(t[1].solved) printf("    %-7d %4d\n",t[1].solved,t[1].time);
		else putchar('\n');
		rank = 1;
		for(int i=2;i<=mxid;i++){
			if(t[i].rank(t[i-1])) rank = i;
			printf("%4d %4d",rank,t[i].id);
			if(t[i].solved) printf("    %-7d %4d\n",t[i].solved,t[i].time);
			else putchar('\n');
		}
		if(n) putchar('\n');
	}
}
