/**
	UVa 10855 - Rotated square
	by Rico Tiongson
	Submitted: January 23, 2014
	Accepted 0.345s Java
	O(n^4) time
*/
import java.util.*;
import java.io.*;

public class Main {
	static char[][] rotate( char[][] c ){
		char[][] d = new char[c.length][c.length];
		for( int i=0; i<c.length; ++i ){
			for( int j=0; j<c.length; ++j ){
				d[i][j] = c[c.length-j-1][i];
			}
		}
	
		return d;
	}
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String in;
		while( !(in = br.readLine()).equals("0 0") ){
			String[] sp = in.trim().split( "\\s+" );
			int N = Integer.parseInt( sp[0] );
			int n = Integer.parseInt( sp[1] );
			char[][]  a = new char[N][], b = new char[n][];
			for( int i=0; i<N; ++i ){
				a[i] = br.readLine().toCharArray();
			}
			for( int i=0; i<n; ++i ){
				b[i] = br.readLine().toCharArray();
			}
			for( int i=0; i<4; ++i ){
				if( i != 0 ){
					pw.print( ' ' );
					b = rotate(b);
				}
				int count = 0;
				for( int j=0; j<=N-n; ++j ){
					for( int k=0; k<=N-n; ++k ){
						outer:
						for( int l=0; l<n; ++l ){
							for( int m=0; m<n; ++m ){
								if( a[j+l][k+m] != b[l][m] ){
									count--;
									break outer;
								}
							}
						}
						count++;
					}
				}
				pw.print( count );
			}
			pw.println();
		}
		
		pw.close();
	}
}
