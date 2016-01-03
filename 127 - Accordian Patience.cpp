/**
	UVa 127 - "Accordian" Patience
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.816s C++
	O(>n^2) time
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
char c[2][80];
bool state;
vector<stack<const char*> > deck;
bool ok(const char* a, const char* b){
	return a[0]==b[0] || a[1]==b[1];
}
void validate(vector<stack<const char*> >::iterator Index){
	if(Index-deck.begin()>2){
		if( ok((Index-3)->top(),Index->top()) ){
			state = true;
			(Index-3)->push(Index->top());
			Index->pop();
			if(Index->empty()) deck.erase(Index);
			return;
		}
	}
	if(Index>deck.begin()){
		if( ok((Index-1)->top(),Index->top()) ){
			state = true;
			(Index-1)->push(Index->top());
			Index->pop();
			if(Index->empty()) deck.erase(Index);
		}
	}
}

int main(){
	vector<stack<const char*> >::iterator it;
	while(true){
		gets(c[0]);
		if(c[0][0]=='#') return 0;
		gets(c[1]);
		deck.clear();
		for(int i=0;i<2;i++){
			for(int j=0;j<26;j++){
				deck.push_back(stack<const char*>());
				deck.back().push(c[i]+3*j);
				state = false;
				validate(deck.end()-1);
				while(state){
					state = false;
					for(it = deck.begin();it!=deck.end();it++){
						validate(it);
						if(state) break;
					}
				}
			}
		}
		state = true;
		while(state){
			state = false;
			for(it=deck.begin();it!=deck.end();it++){
				validate(it);
				if(state) break;
			}
		}
		printf("%d pile",deck.size());
		if(deck.size()>1) putchar('s');
		printf(" remaining:");
		for(int i=0;i<deck.size();i++){
			printf(" %d",deck[i].size());
		}
		putchar('\n');
	}
}
