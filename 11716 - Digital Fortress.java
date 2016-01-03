/**
	UVa 11716 - Digital Fortress
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.448s Java
	O(n) time
*/
import java.util.*;
import java.io.*;
public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		ArrayList<Integer> squares = new ArrayList<Integer>();
		
		for( int x=0; x*x <= 10000; ++x )
			squares.add( x*x );
		
		int n = Integer.parseInt( br.readLine() );
		String a;
		
		while( n-- != 0 ){
			a = br.readLine();
			int sz = Collections.binarySearch( squares, a.length() );
			if( sz<0 ){
				pw.println( "INVALID" );
				continue;
			}
			for( int i=0; i<sz; ++i ){
				for( int j=0; j<sz; ++j ){
					pw.print( a.charAt( j*sz + i ) );
				}
			}
			pw.print('\n');
		}
		
		pw.close();
	}
}
