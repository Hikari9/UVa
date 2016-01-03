/**
	UVa 993 - sqrt log sin
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.739s Java
	O(dp) time
*/
import java.util.*;
import java.io.*;

public class u11703 {
	static int[] dp = new int[1000001];
	static int DP( int x ){
		if( dp[x] != -1 ) return dp[x];
		dp[x] = DP( (int)( x - Math.sqrt(x) + 1e-7 ) );
		dp[x] += DP( (int)( Math.log(x) + 1e-7 ) );
		dp[x] %= 1000000;
		dp[x] += DP( (int)( x * Math.sin(x) * Math.sin(x) ) );
		dp[x] %= 1000000;
		return dp[x];
	}
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		Arrays.fill( dp, -1 );
		dp[0] = 1;
		
		String s;
		
		while( !(s=br.readLine()).equals("-1") ){
			pw.println( DP( Integer.parseInt(s) ) );
		}
		
		pw.close();
	}
}