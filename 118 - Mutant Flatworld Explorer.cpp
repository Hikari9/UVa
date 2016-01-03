/** 
	UVa 118 - Mutant Flatworld Explorer
	by Rico Tiongson
	Submitted: May 3, 2013
	Accepted: 0.009s C++
	O(n) time
*/
#include<iostream>
#define Lost if(!v[x][y]){v[x][y] = true;lost = true;}
using namespace std;
bool v[52][52],lost; //denotes visited
int	X,Y,x,y;
char dir,c[105];
int main(){
	cin >> X >> Y;
	for(int i=0;i<=X;i++) for(int j=0;j<=Y;j++) v[i][j]=false;
	while(cin >> x >> y){
		cin >> dir;
		switch(dir){
			case 'N': dir=0; break;
			case 'E': dir=1; break;
			case 'S': dir=2; break;
			case 'W': dir=3; break;
		}
		cin >> c;
		lost=false;
		for(int i=0;c[i]!='\0'&&!lost;i++){
			switch(c[i]){
				case 'R':
					dir++;
					if(dir==4) dir=0;
					break;
				case 'L':
					dir--;
					if(dir==-1) dir=3;
					break;
				case 'F':
					switch(dir){
						case 0: //North
							if(y==Y){
								Lost
							}
							else y++;
							break;
						case 1: //East
							if(x==X){
								Lost
							}
							else x++;
							break;
						case 2: //South
							if(y==0){
								Lost
							}
							else y--;
							break;
						case 3: //West
							if(x==0){
								Lost
							}
							else x--;
							break;
					}
					break;
			}
		}
		switch(dir){
			case 0: dir='N'; break;
			case 1: dir='E'; break;
			case 2: dir='S'; break;
			case 3: dir='W'; break;
		}
		cout << x << ' ' << y << ' ' << dir;
		if(lost) cout << " LOST";
		cout << endl;
	}
}
