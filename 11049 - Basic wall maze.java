/**
	UVa 11049 - Basic Wall Maze
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.186s Java
	O(?) time
*/
import java.util.*;
import java.io.*;
public class Main {
	static String a, s[];
	static int sx, sy, ex, ey;
	static int ax, ay, bx, by;
	static int[] dx = new int[]{ 0, 1, 0, -1 };
	static int[] dy = new int[]{ -1, 0, 1, 0 };
	static int[][] prev = new int[14][14];
	static boolean[][] wall = new boolean[14][14];
	static boolean[][] v = new boolean[14][14];
	static boolean inRange( int x, int y ){
		return x > 0 && x < 14 && y > 0 && y < 14 && !v[x][y];
	}
	static char[] ans = new char[]{ 'N', 'E', 'S', 'W' };
	static void bfs(){
		for( int i=0; i<v.length; ++i ){
			Arrays.fill(v[i],false);
			Arrays.fill(prev[i],-1);
		}
		Queue<Edge> q = new LinkedList<Edge>();
		v[sx][sy] = true;
		q.offer( new Edge(sx,sy) );
		while( q.size() != 0 ){
			Edge e = q.poll();
			if( e.x==ex && e.y==ey ) return;
			for( int k=0; k<dx.length; ++k ){
				if( inRange( e.x + 2*dx[k], e.y + 2*dy[k] ) ){
					// if( e.x + 2*dx[k]==ex &&  e.y + 2*dy[k] == ey ){
						// System.out.println(wall[e.x+dx[k]][e.y+dy[k]]);
					// }
					if( wall[e.x+dx[k]][e.y+dy[k]] ) continue;
					v[e.x + 2*dx[k]][e.y + 2*dy[k]] = true;
					prev[e.x + 2*dx[k]][e.y + 2*dy[k]] = k;
					q.offer( new Edge(e.x + 2*dx[k], e.y + 2*dy[k]) );
				}
			}
		}
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	public static void main(String args[]) throws IOException {
		while( !(a=br.readLine()).equals("0 0") ){
			s = a.split(" ");
			sx = Integer.parseInt(s[0]);
			sy = Integer.parseInt(s[1]);
			s = br.readLine().split(" ");
			ex = Integer.parseInt(s[0]);
			ey = Integer.parseInt(s[1]);
			sx *= 2;
			sy *= 2;
			ex *= 2;
			ey *= 2;
			for( int i=0; i<wall.length; ++i ){
				Arrays.fill(wall[i],false);
			}
			readWall();
			readWall();
			readWall();
			bfs();
			// printAll();
			Stack<Character> printThis = new Stack<Character>();
			int p = prev[ex][ey];
			while( p != -1 ){
				printThis.push(ans[p]);
				ex -= 2*dx[p];
				ey -= 2*dy[p];
				p = prev[ex][ey];
			}
			while( printThis.size() != 0 ) pw.print( printThis.pop() );
			pw.println();
		}
		pw.close();
	}
	static void printAll(){
		for( int j=1; j<14; ++j ){
			for( int i=1; i<14; ++i ){
				if( i==sx && j==sy ) System.out.print('s');
				else if( i==ex && j==ey ) System.out.print('e');
				else if( wall[i][j] ) System.out.print('1');
				else if( prev[i][j]==-1 ) System.out.print('-');
				else System.out.print(prev[i][j]);
			}
			System.out.println();
		}
	}
	
	static void readWall() throws IOException {
		s = br.readLine().split(" ");
		ax = Integer.parseInt(s[0]);
		ay = Integer.parseInt(s[1]);
		bx = Integer.parseInt(s[2]);
		by = Integer.parseInt(s[3]);
		int temp;
		if( ax==bx ){
			if( by < ay ){
				temp = ay;
				ay = by;
				by = temp;
			}
			for( int i=ay; i<=by; ++i ){
				if( i != ay ) wall[ax*2+1][i*2] = true;
				wall[ax*2+1][i*2+1] = true;
				// wall[ax*2+1][i*2] = true;
			}
		}
		else if( ay==by ){
			if( bx < ax ){
				temp = ax;
				ax = bx;
				bx = temp;
			}
			for( int i=ax; i<=bx; ++i ){
				if( i != ax ) wall[i*2][ay*2+1] = true;
				wall[i*2+1][ay*2+1] = true;
				// wall[i*2][ay*2+1] = true;
			}
		}
	}
}

class Edge {
	public int x, y;
	public Edge(int X, int Y){
		x = X;
		y = Y;
	}
}
