/**
	UVa 371 - Ackermann Functions
	by Rico Tiongson
	SubmittedL July 16, 2013
	Accepted 1.008s JAVA
	O(dp) time
*/
import java.util.*;
import java.io.*;
import java.math.*;
// note: no nextLine()
class BufferedScanner{
	private BufferedReader br;
	private String cur[], buf;
	private int id;
	private BufferedScanner Buffer(){
		try{
			if( ++id==cur.length ){
				do{
				if( (buf=br.readLine())==null ) return null;
				cur = buf.trim().split("\\s+");
				}
				while ( cur.length==1 && cur[0].equals("") );
				id = 0;
			}
		}
		catch( Exception e ){ e.printStackTrace(); }
		return this;
	}
	public BufferedScanner( InputStream _ ){
		br = new BufferedReader( new InputStreamReader( _ ) );
		cur = new String[0];
		id = -1;
	}
	public String next(){
		if( Buffer()==null ) return null;
		return cur[id];
	}
	public char[] nextCharArray(){
		if( Buffer()==null ) return null;
		return cur[id].toCharArray();
	}
	public Character nextCharacter(){
		if( Buffer()==null ) return null;
		return cur[id].charAt(0);
	}
	public Short nextShort(){
		if( Buffer()==null ) return null;
		return Short.parseShort( cur[id] );
	}
	public Integer nextInt(){
		if( Buffer()==null ) return null;
		return Integer.parseInt( cur[id] );
	}
	public Long nextLong(){
		if( Buffer()==null ) return null;
		return Long.parseLong( cur[id] );
	}
	public BigInteger nextBigInteger(){
		if( Buffer()==null ) return null;
		return new BigInteger( cur[id] );
	}
	public BigDecimal nextBigDecimal(){
		if( Buffer()==null ) return null;
		return new BigDecimal( cur[id] );
	}
	public Float nextFloat(){
		if( Buffer()==null ) return null;
		return Float.parseFloat( cur[id] );
	}
	public Double nextDouble(){
		if( Buffer()==null ) return null;
		return Double.parseDouble( cur[id] );
	}
}
public class Main{
	public static HashMap<Long, Long> ans = new HashMap<Long, Long>();
	public static long ackermann( long x ){
		if( ans.containsKey(x) ) return ans.get(x);
		if( x%2==0 ) ans.put( x, ackermann(x/2)+1 );
		else ans.put(x, ackermann(3*x+1)+1);
		return ans.get( x );
	}
	public static void main( String args[] ) throws IOException{
		BufferedScanner cin = new BufferedScanner( System.in );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		ans.put( 1L, 0L );
		long a, b=0, c, id;
		while( true ){
			a = cin.nextLong();
			b = cin.nextLong();
			if( a==0L && b==0L ) break;
			if( b<a ){
				c = a;
				a = b;
				b = c;
			}
			pw.printf( "Between %d and %d, ", a, b );
			id = a;
			c = ackermann( id );
			if( a==1L ) c = 3L;
			while( ++a<=b ){
				// try{
					if( ackermann(a)>c ){
						c = ans.get(a);
						id = a;
					}
				// }
				// catch( Exception e ){
					// e.printStackTrace();
					// System.out.println( a );
					// break;
				// }
			}
			pw.printf( "%d generates the longest sequence of %d values.\n", id, c );
		}
		pw.close();
	}
}