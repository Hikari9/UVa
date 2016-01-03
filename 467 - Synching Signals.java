/**
	UVa 467 - Synching Signals
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 1.246s Java
	O(n^3) time
*/
import java.util.*;
import java.io.*;

public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String in, s[];
		
		int set = 0;
		int[] a;
		int[] b = new int[5000];
		
		while( ( in = br.readLine() ) != null ){
		
			s = in.trim().split("\\s+");
			a = new int[s.length];
			
			for( int i=0; i<s.length; ++i )
				a[i] = Integer.parseInt( s[i] );
			
			Arrays.sort( a );
			
			Arrays.fill( b, 0 );
			boolean updated = true;
			int found = -1;
			
			outer:
			for( int i=0; updated; ++i ){
				updated = false;
				for( int j=0; j<a.length; ++j ){
					int offset = (i<<1) * a[j];
					int lim = Math.min( offset + a[j] - 5, b.length );
					// System.out.println( j + ": " + a[j] + "(" + i + ") " + offset + " " + lim );
					for( int k=offset; k<lim; ++k ){
						updated = true;
						if( ++b[k] == a.length && i != 0 ){
							found = k;
							break outer;
						}
					}
				}
				
			}
			
			if( found != -1 && ((found/60) > 60 || ((found/60)==60 && (found%60) > 0)) ) found = -1;
			
			if( found == -1 )
				pw.println( "Set " + (++set) + " is unable to synch after one hour." );
			else{
				pw.println( "Set " + (++set) + " synchs again at " + (found/60) + " minute(s) and " + (found%60) + " second(s) after all turning green." );
			}
			
			// for( int i=0; i<60; ++i ){
				// for( int j=0; j<60; ++j ){
					// if( b[i*60 + j] != 0 )
					// System.out.printf( "%02d:%02d %d\n", i, j, b[i*60 + j] );
				// }
			// }
		}
		
		pw.close();
	}
}