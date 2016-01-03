/**
	UVa 11821 - High-Precision Number
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.152s Java
	O(n) time
*/
import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		StringBuilder sb = new StringBuilder();
		BigDecimal x;
		String buf;
		int n = Integer.parseInt( br.readLine() ),len;
		while( n-->0 ){
			x = BigDecimal.ZERO;
			while( !(buf=br.readLine()).equals("0") ){
				x = x.add( new BigDecimal(buf) );
			}
			//strip trailing
			buf = x.toString();
			len = buf.length()-1;
			while(len>-1 && buf.charAt(len)=='0') len--;
			if(len>-1 && buf.charAt(len)=='.') len--;
			sb.append(buf.substring(0,len+1)).append('\n');
		}
		System.out.print(sb);
	}
}
