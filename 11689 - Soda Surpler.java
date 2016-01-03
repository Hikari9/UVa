/**
	UVa 11689 - Soda Surpler
	by Rico Tiongson
	Submitted: November 1, 2013
	Accepted 0.156s Java
	O(?) time
*/
import java.util.*;
import java.io.*;
public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		int n = Integer.parseInt( br.readLine() );
		while( n-- != 0 ){
			String[] sp = br.readLine().split( " " );
			int e = Integer.parseInt( sp[0] );
			int f = Integer.parseInt( sp[1] );
			int c = Integer.parseInt( sp[2] );
			int ef = (e+f)/c;
			int mod = (e+f)%c;
			int ans = ef;
			while(ef > 0){
				int g = (ef+mod)/c;
				mod = (ef+mod)%c;
				ans += g;
				ef = g;
			}
			pw.println( ans );
		}
		pw.close();
	}
}
