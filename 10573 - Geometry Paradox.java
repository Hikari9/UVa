/**
	UVa 10573 - Geometry Paradox
	by Rico Tiongson
	Submitted: August 28, 2013
	Accepted 0.199s Java
	O(1) time
*/
import java.util.*;
import java.io.*;
import static java.lang.Math.PI;
public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		int n = Integer.parseInt( br.readLine() );
		int t, ints, x = 0;
		double r[] = new double[3];
		String s[];
		while( n-- != 0 ){
			s = br.readLine().trim().split(" ");
			ints = 0;
			for( int i=0; i<s.length; ++i ){
				try{
					x = Integer.parseInt(s[i]);
					r[ints++] = (double)x;
					if( ints==2 ){
						break;
					}
				}
				catch( Exception e ){}
			}
			if( ints==1 ){
				t = x;
				if( t<=0 ){
					pw.println( "Impossible." );
					continue;
				}
				r[2] = t * 0.5;
				r[0] = r[1] = r[2] * 0.5;
			}
			else{
				if( r[0]<0 || r[1]<0 ){
					pw.println( "Impossible." );
					continue;
				}
				r[2] = ( (r[0]*2.0) + (r[1]*2.0) )*0.5;
			}
			pw.printf( "%.4f\n", (double)( r[2]*r[2] - r[0]*r[0] - r[1]*r[1] )*PI );
		}
		pw.close();
	}
}
