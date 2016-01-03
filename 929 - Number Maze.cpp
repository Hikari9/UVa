/**
	UVa 929 - Number Maze
	by Rico Tiongson
	Submitted: May 1, 2013
	Accepted 0.792s C++
	O(n^2) time
*/
#include<cstdio>
#include<list>
#include<algorithm>
//#include<ctime>
#define flag puts("Flag")
const int INF=1<<30;
using namespace std;
struct node{
	int path,w;
	int x,y;
	bool visited;
	list<node*>::iterator it;
	void reset(const int& W){
		w=W;
		path=INF;
		visited=false;
	}
} G[1005][1005],*p,*p2,*dest;
bool cmp(const node* a, const node* b){
	return a->path < b->path;
}
int n,m,t;
int dijstra(){
	list<node*> l;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			G[i][j].it = l.insert(l.end(),&G[i][j]);
		}
	}
	if(l.empty()) return 0;
	p = l.front();
	l.pop_front();
	p->path=p->w;
	p->visited=true;
	if(n>1){
		p2 = &G[p->x+1][p->y];
		p2->path = p->path + p2->w;
	}
	if(m>1){
		p2 = &G[p->x][p->y+1];
		p2->path = p->path + p2->w;
	}
	l.sort(cmp);
	dest = &G[n-1][m-1];
	while(!l.empty()){
		p = l.front();
		l.pop_front();
		if(p->path==INF||p==dest) break;
		p->visited=true;
		if(p->x>0){
			p2 = &G[p->x-1][p->y];
			if(!p2->visited){
				if(p2->path > p->path + p2->w){
					p2->path = p->path + p2->w;
					l.erase(p2->it);
					p2->it = l.insert(lower_bound(l.begin(),l.end(),p2,cmp),p2);
				}
			}
		}
		if(p->x<n-1){
			p2 = &G[p->x+1][p->y];
			if(!p2->visited){
				if(p2->path > p->path + p2->w){
					p2->path = p->path + p2->w;
					l.erase(p2->it);
					p2->it = l.insert(lower_bound(l.begin(),l.end(),p2,cmp),p2);
				}
			}
		}
		if(p->y>0){
			p2 = &G[p->x][p->y+1];
			if(!p2->visited){
				if(p2->path > p->path + p2->w){
					p2->path = p->path + p2->w;
					l.erase(p2->it);
					p2->it = l.insert(lower_bound(l.begin(),l.end(),p2,cmp),p2);
				}
			}
		}
		if(p->y<m-1){
			p2 = &G[p->x][p->y-1];
			if(!p2->visited){
				if(p2->path > p->path + p2->w){
					p2->path = p->path + p2->w;
					l.erase(p2->it);
					p2->it = l.insert(lower_bound(l.begin(),l.end(),p2,cmp),p2);
				}
			}
		}
	}
	return dest->path;
}
int main(){
	scanf("%d",&t);
	for(int i=0;i<1004;i++){
		for(int j=0;j<1004;j++){
			G[i][j].x=i;
			G[i][j].y=j;
		}
	}
	char c[3000];
	while(t--){
		scanf("%d\n%d\n",&n,&m);
		for(int i=0;i<n;i++){
			gets(c);
			for(int j=0;j<m;j++){
				G[i][j].reset(c[j*2]-'0');
			}
		}
		printf("%d\n",dijstra());
	}
	//printf("%d\n",clock());
}
