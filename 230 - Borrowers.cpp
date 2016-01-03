/**
	UVa 230 - Borrowers
	by Rico Tiongson
	Submitted: May 12, 2013
	Accepted 0.015s C++
	O(logn) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
struct book{
	string Title;
	map<string,set<book> >::iterator Author;
	bool* state; //0:Shelf 1:Borrowed 2:Returned
	book(){}
	book(const char* a):
		Title(a),
		state(new bool(false)) {}
	bool operator<(const book& rhs) const{ return Title < rhs.Title; }
} temp;
struct cmp{
	bool operator()(const set<book>::iterator lhs, const set<book>::iterator rhs) const{
		int Cmp = lhs->Author->first.compare(rhs->Author->first);
		if(!Cmp) return lhs->Title > rhs->Title;
		return Cmp>0;
	}
};
map<string,set<book> > byAuthor;
map<string,set<book>::iterator> byTitle,Borrowed;
priority_queue<set<book>::iterator,vector<set<book>::iterator>,cmp> Returned;
map<string,set<book> >::iterator it;
set<book>::iterator it2,it4;
map<string,set<book>::iterator>::iterator it3;
char c[100],d[100];
bool getPrev(){
	it = it2->Author;
	it4 = it2;
	if(it4==it->second.begin() && it==byAuthor.begin()) return false;
	else if(it4==it->second.begin()){
		it--;
		it4 = it->second.end();
	}
	while(it4!=it->second.begin() || it!=byAuthor.begin()){
		if(it4==it->second.begin()){
			it--;
			it4 = it->second.end();
		}
		if(!*(--it4)->state) return true;
	}
	return false;
}
void printstates(){
	for(it = byAuthor.begin();it!=byAuthor.end();it++){
		cout << it->first << ":";
		for(it2 = it->second.begin();it2!=it->second.end();it2++){
			cout << ' ' << it2->Title << '(' << *it2->state << ')';
		}
		cout << endl;
	}
}
int main(){
	while(cin.get()!='E'){
		cin.getline(c,100,'"').getline(d,100);
		it = byAuthor.insert(pair<string,set<book> >(d+4,set<book>())).first;
		temp = book(c);
		temp.Author = it;
		it2 = it->second.insert(temp).first;
		byTitle[c] = it2;
	}
	cin.ignore().ignore().ignore();
	while(c[0]=cin.get()){
		switch(c[0]){
			case 'E': return 0; break;
			case 'B':
				cin.getline(c,10,'"').getline(d,100,'"').ignore();
				it2 = byTitle.find(d)->second;
				*it2->state = true;
				Borrowed[d] = it2;
				break;
			case 'R':
				cin.getline(c,10,'"').getline(d,100,'"').ignore();
				it3 = Borrowed.find(d);
				Returned.push(it3->second);
				Borrowed.erase(it3);
				break;
			case 'S':
				cin.getline(c,8);
				while(!Returned.empty()){	
					it2 = Returned.top();
					Returned.pop();
					*it2->state = false;
					if(getPrev()) cout << "Put \"" << it2->Title << "\" after \"" << it4->Title << '"' << endl;
					else cout << "Put \"" << it2->Title << "\" first" << endl;
				}
				cout << "END" << endl;
				break;
		}
	}
}
