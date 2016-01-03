/**
	UVa 10419 - Sum-up the Primes
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.455s C++
	O(n^2*logn) goldbach + O(1) prime time
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int pm(61); //prime 2 removed
int primes[pm]={101,103,107,109,11,113,127,13,131,137,139,149,151,157,163,167,17,173,179,181,19,191,193,197,199,211,223,227,229,23,233,239,241,251,257,263,269,271,277,281,283,29,293,3,31,37,41,43,47,5,53,59,61,67,7,71,73,79,83,89,97};
int b[pm],Index[301],r=0,n,d,stak[15];
bool oneodd,found;
bool cmp(const int& a, const int& b){
	return Index[a]<Index[b];
}
void goldbach(int x,int k){
	if(found) return;
	if(x==d){
		if(!n){
			found = true;
			if(oneodd) sort(stak,stak+d,cmp);
			cout << stak[0];
			for(int i=1;i<d;i++) cout << '+' << stak[i];
			cout << endl;
		}
	}
    else for(int i=k;i<pm;i++){
		if(n-primes[i]>-1 && b[i]<2){
			n-=primes[i];
			stak[x]=primes[i];
			b[i]++; //visited
			goldbach(x+1,i);
			if(found) return;
			n+=primes[i];
			b[i]--;
		}
	}
}
int main(){
	fill(Index,Index+301,0);
	Index[2]=25;
	for(int i=0;i<25;i++) Index[primes[i]]=i;
	for(int i=25;i<pm;i++) Index[primes[i]]=i+1;
	while(cin >> n >> d,n||d){
		cout << "CASE " << ++r << ':' << endl;
		if(n==2 && d==1)
			cout << "2" << endl;
		else{
			found=0;
			fill(b,b+pm,0);
			if(n%2 xor d%2){ //one is odd
				oneodd=true;
				stak[0]=2;
				n-=2;
				goldbach(1,0);
			}
			else{
				oneodd=false;
				goldbach(0,0);
			}
			if(!found) cout << "No Solution." << endl;
		}
	}
}
