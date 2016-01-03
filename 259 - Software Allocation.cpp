/**
	UVa 259 - Software Allocation
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.025s C++
	O(?) time
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
using namespace std;
char buf[150];
int cap[38][38], flow[38][38], prev[38], i, app, comp, tflow, cf;
bool augment(){
memset( prev, -1, sizeof( prev ) );
queue<int> q;
q.push( 36 ); // source
prev[36] = -2;
while( !q.empty() ){
for( i=0; i<38; ++i ){
if( flow[q.front()][i] < cap[q.front()][i] && prev[i]==-1 ){
prev[i] = q.front();

if( i==37 ) // found sink
goto FOUND;
q.push( i );
}
}
q.pop();
}
// not found
return false;
FOUND:
// track prev
i = 37;
while( i!=36 ){
++flow[ prev[i] ][ i ]; // default flow is one
--flow[ i ][ prev[i] ]; // reverse
i = prev[i];
}
return true;
}
int main(){
// freopen("input.txt","r",stdin);
// 0-9: computer
// 10-35: app
// 36 source 37 sink
// ifstream fin("input.txt");
while( cin.getline(buf,150) ){

// if( !buf[0] ) continue;
memset( cap, 0, sizeof( cap ) );
tflow = 0;
do{

app = buf[0]-'A' + 10;
for( i=3; buf[i]!=';'; ++i ){
if( isdigit(buf[i]) )
cap[buf[i]-'0'][app] = 1;
}
comp = buf[1]-'0';
// store flow to sink
cap[app][37] = comp;
tflow += comp;
// fin.getline(buf,150);
// } while( gets(buf), isupper(buf[0]) );

// } while( gets(buf), buf[0] );
} while( cin.getline(buf,150), isupper(buf[0]) );
for( i=0; i<10; ++i ){
// add capacity from source to all computers
cap[36][i] = 1;
}
memset( flow, 0, sizeof( flow ) );
cf = 0;
while( augment() ) ++cf;

if( cf==tflow ){
// retrieve flow
for( i=0; i<10; ++i ){
for( app=10; app<36; ++app ){
if( flow[i][app]==1 ){
putchar('A'+app-10);
break;
}
}
if( app==36 ) putchar('_');
}
}
else putchar('!');
putchar('\n');
}
}
