/**
	UVa 11040 - Add bricks in the wall
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.309s Java
	O(n^2) time
*/
import java.util.*;
import java.io.*;
public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		int n = Integer.parseInt( br.readLine() );
		double[][] array = new double[9][];
		for( int i=0; i<array.length; ++i ){
			array[i] = new double[i+1];
		}
		while( n-- != 0 ){
			for( int i=0; i<array.length; ++i ){
				Arrays.fill( array[i], 0 );
			}
			for( int i=0; i<array.length; i+=2 ){
				String[] s = br.readLine().split(" ");
				for( int j=0; j<s.length; ++j ){
					array[i][j<<1] = Double.parseDouble( s[j] );
				}
			}
			// for( int i=0; i<array.length; ++i ){
				// pw.println( Arrays.toString(array[i]) );
			// }
			for( int i=array.length-1; i>=0; i-=2 ){
				for( int j=2; j<array[i].length; j+=2 ){
					array[i][j-1] = ( array[i-2][j-2] - array[i][j-2] - array[i][j] )/2.0;
				}
			}
			for( int i=array.length-1; i>=0; i-=2 ){
				for( int j=1; j<array[i].length; ++j ){
					array[i-1][j-1] = array[i][j-1] + array[i][j];
				}
			}
			for( int i=0; i<array.length; ++i ){
				for( int j=0; j<array[i].length; ++j ){
					if( j != 0 ) pw.print(' ');
					if( (int)Math.round( array[i][j] + 1e-7 ) == (int)( array[i][j] + 1e-7 ) ){
						pw.print( (int)( array[i][j] + 1e-7 ) );
					}
					else{
						pw.print( array[i][j] );
					}
				}
				pw.println();
			}
		}
		pw.close();
	}
}
