/**
	UVa 10698 - Football Sort
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.016s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
struct team{
	map<string,team>::iterator itself;
	int points,numGames,goals,sufGoals,goalDif;
	double perc;
	team():points(0),numGames(0),goals(0),sufGoals(0),goalDif(0),perc(0){}
	void update(int up, int down){
		numGames++;
		if(up>down) points+=3;
		else if(up==down) points++;
		goalDif += up-down;
		goals += up;
		sufGoals += down;
	}
	void print(int rank){
		if(rank!=-1) printf("%2d.",rank);
		else printf("   ");
		cout.width(16);
		cout.fill(' ');
		cout << itself->first;
		printf("%4d%4d%4d%4d%4d",points,numGames,goals,sufGoals,goalDif);
		if(numGames){
			cout.width(7);
			cout.fill(' ');
			cout << (100.*points)/(3.*numGames) << endl;
		}
		else puts("    N/A");
	}
};
bool cmp(const team* a, const team* b){
	if(a->points!=b->points) return a->points>b->points;
	if(a->goalDif!=b->goalDif) return a->goalDif>b->goalDif;
	if(a->goals!=b->goals) return a->goals>b->goals;
	const string &A = a->itself->first, &B = b->itself->first;
	//lex compare lower_case
	char c,d;
	for(int i=0;i<A.size() && i<B.size();i++){
		c = tolower(A[i]);
		d = tolower(B[i]);
		if(c==d){
			if(isupper(A[i]) xor isupper(B[i])) return isupper(A[i]);
		}
		else return c<d;
	}
}
bool cmp2(const team* a, const team* b){
	return a->points==b->points && a->goalDif==b->goalDif && a->goals==b->goals;
}
int main(){
	cout.precision(2);
	cout << fixed;
	map<string,team> m;
	map<string,team>::iterator it;
	int a,b,x,y;
	string s;
	char tm[2][20];
	bool f=false;
	while(cin >> a >> b,a||b){
		if(f) putchar('\n');
		else f = true;
		m.clear();
		for(int i=0;i<a;i++){
			cin >> s;
			it = m.insert( pair<string,team>(s,team()) ).first;
			it->second.itself = it;
		}
		for(int i=0;i<b;i++){
			scanf("%s %d - %d %s", tm[0], &x, &y, tm[1]);
			m[tm[0]].update(x,y);
			m[tm[1]].update(y,x);
		}
		vector<team*> v;
		for(it=m.begin();it!=m.end();it++) v.push_back(&it->second);
		sort(v.begin(),v.end(),cmp);
		if(!v.empty()){
			v[0]->print(1);
			for(int i=1;i<v.size();i++){
				if(cmp2(v[i-1],v[i])) v[i]->print(-1);
				else v[i]->print(i+1);
			}
		}
	}
}
