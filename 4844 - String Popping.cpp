/**
	UVa 1261 - String Popping
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.046s C++ 
	O(?) time
*/
#include<cstdio>
#include<list>
using namespace std;
int n;
char c;
list<pair<char,int> > l;
bool dfs(){
	if(l.empty()) return true;
	list<pair<char,int> >::iterator it,it2;
	pair<char,int> pr;
	int joined;
	for( it=l.begin(); it!=l.end(); ++it ){
		if(it->second>1){
			pr = *it;
			it2 = l.erase(it);
			joined = 0;
			if(it2!=l.begin() && it2!=l.end()){
				it = it2;
				--it;
				if(it->first==it2->first){
					joined = it2->second;
					it->second += joined;
					it2 = l.erase(it2);
				}
			}
			if(dfs()) return true;
			if(joined){
				it2 = l.insert(it2,pair<char,int>(it->first,joined));
				it->second -= joined;
			}
			it = l.insert(it2,pr);
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	getchar();
	while( n-- ){
		l.clear();
		c = getchar();
		l.push_back( pair<char,int>( c, 1 ) );
		while( (c=getchar())!='\n' ){
			if( c!=l.back().first ) l.push_back( pair<char,int>( c, 1 ) );
			else ++l.back().second;
		}
		if(dfs()) putchar('1');
		else putchar('0');
		putchar('\n');
	}
}
