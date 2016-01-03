/**
	UVa 10264 - The Most Potent Corner
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.489s Java
	O(nlogn) time
*/
import java.util.*;
import java.io.*;
public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		int dim, mask, adj, i, j, mx, p, d[], pot[];
		String a;
		while( (a=br.readLine())!=null ){
			dim = Integer.parseInt(a);
			mask = ( 1 << dim );
			d = new int[mask];
			pot = new int[mask];
			for( i=0; i<mask; ++i )
				d[i] = Integer.parseInt( br.readLine() );
			for( i=0; i<mask; ++i ){
				pot[i] = d[i];
				for( adj=1; adj<mask; adj<<=1 ){
					pot[i] += d[i^adj];
				}
			}
			// partner up potencies, only if they are adjacent
			mx = 0;
			for( i=0; i<mask; ++i ){
				for( adj=1; adj<mask; adj<<=1 ){
					mx = Math.max( pot[i] + pot[i^adj] - d[i] - d[i^adj], mx );
				}
			}
			pw.println( mx );
		}
		pw.close();
	}
}
