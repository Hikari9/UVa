/**
	UVa 11586 - Train Tracks
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.186s Java
	O(n) time
*/
import java.util.*;
import java.io.*;
public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		int n = Integer.parseInt( br.readLine() );
		while( n-- != 0 ){
			String[] s = br.readLine().split(" ");
			HashMap<String, Integer> hm = new HashMap<String, Integer>();
			for( String str : s ){
				Integer x = hm.get(str);
				if( x==null ) x = 0;
				hm.put(str, x+1);
			}
			int cnt = 0;
			if( hm.containsKey("MF") ) cnt += hm.get("MF");
			if( hm.containsKey("FM") ) cnt += hm.get("FM");
			if( ((cnt&1)==0) && hm.get("FF") == hm.get("MM") ) pw.println("LOOP");
			else pw.println("NO LOOP");
		}
		pw.close();
	}
}