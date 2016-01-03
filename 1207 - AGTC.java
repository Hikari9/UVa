/**
	UVa 1207 - AGTC
	by Rico Tiongson
	Submitted: January 21, 2013
	Accepted 0.288s Java
	O(n^2) time
*/
import java.util.*;
import java.io.*;

public class Main {
	static String a, b;
	static int dp[][];
	
	static int DP( int i, int j ){
		if( dp[i][j] != -1 ) return dp[i][j];
		if( i == a.length() ) return dp[i][j] = b.length() - j;
		if( j == b.length() ) return dp[i][j] = a.length() - i;
		int value = Integer.MAX_VALUE;
		if( a.charAt(i) == b.charAt(j) ){
			value = DP( i+1, j+1 );
		}
		else{
			value = DP( i+1, j+1 ) + 1;
		}
		value = Math.min( value, DP( i+1, j ) + 1 );
		value = Math.min( value, DP( i, j+1 ) + 1 );
		return dp[i][j] = value;
	}
	
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String in;
		
		while( (in = br.readLine()) != null ){
			a = in.trim().split( "\\s+" )[1];
			in = br.readLine();
			if( in == null ) break;
			b = in.trim().split( "\\s+" )[1];
			// pw.println( a + " " + b );
			dp = new int[ a.length() + 1 ][ b.length() + 1 ];
			for( int i=0; i<dp.length; ++i ){
				for( int j=0; j<dp[i].length; ++j ){
					dp[i][j] = -1;
				}
			}
			pw.println( DP(0, 0) );
		}
		
		pw.close();
	}
}