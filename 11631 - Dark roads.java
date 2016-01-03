/**
	UVa 11631 - Dark Roads
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 1.558s Java
	O(nlogn) time	
*/
import java.util.*;
import java.io.*;
public class Main {
	static int n, m, total;
	static PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
	
	static int[] f;
	static int find( int x ){
		if( f[x] == -1 ) return x;
		return f[x] = find( f[x] );
	}
	
	static int Kruskals(){
		f = new int[n];
		Arrays.fill( f, -1 );
		while( pq.size() != 0 ){
			Edge e = pq.poll();
			int a = find( e.i );
			int b = find( e.j );
			if( a != b ){
				f[a] = b;
				total -= e.w;
			}
		}
		return total;
	}
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String in, s[];
		int a, b, c;
		
		while( (in=br.readLine()) != null ){
			if( in.equals("0 0") ) break;
			pq.clear();
			total = 0;
			s = in.split(" ");
			n = Integer.parseInt( s[0] );
			m = Integer.parseInt( s[1] );
			for( int i=0; i<m; ++i ){
				s = br.readLine().split(" ");
				a = Integer.parseInt( s[0] );
				b = Integer.parseInt( s[1] );
				c = Integer.parseInt( s[2] );
				pq.offer( new Edge( a, b, c ) );
				total += c;
			}
			pw.println( Kruskals() );
		}
		
		pw.close();
	}
}
class Edge implements Comparable<Edge> {
	public int i, j, w;
	public Edge( int I, int J, int W ){
		i = I;
		j = J;
		w = W;
	}
	public int compareTo( Edge E ){
		return w - E.w;
	}
}
