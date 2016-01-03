/**
	UVa 10784 - Diagonal
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.348s Java
	O(logn) time
*/
import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	static long UPPER_BOUND = 44721362, lb, ub, mid;
	static long f(long x){
		return x*x - 3*x;
	}
	public static void main(String args[]) throws IOException {
		// System.out.println( f(UPPER_BOUND)/2 );
		long N;
		int tc = 0, id;
		String a;
		while(!(a=br.readLine()).equals("0")){
			N = (Long.parseLong(a)<<1);
			// equation: 2N = n^2 - 3n
			lb = 0;
			ub = UPPER_BOUND;
			while( lb < ub ){
				mid = (lb+ub)/2;
				if( f(mid) >= N ) ub = mid;
				else lb = mid + 1;
			}
			pw.println("Case " + (++tc) + ": " + ub);
		}
		pw.close();
	}
}
