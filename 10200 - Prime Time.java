/**
	UVa 10200 - Prime Time
	by Rico Tiongson
	Submitted: May 2, 2013
	Accepted 2.558 Java
	O(n^2) time
*/
import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
	public static void main(String args[])throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		boolean[] x = new boolean[10001];
		x[0]=true;
		int i=1,A,B,c;
		BigInteger mx = new BigInteger("10001"),fortyone = new BigInteger("41");
		for(BigInteger a=BigInteger.ONE;i<10001;a=a.add(BigInteger.ONE),i++){
			// x[i]=x[i-1];
			if(a.pow(2).add(a).add(fortyone).isProbablePrime(1)){
				x[i]=true;
			}
		}
		String a;
		String[] s;
		while((a=br.readLine())!=null){
			s = a.split(" ");
			A = Integer.parseInt(s[0]);
			B = Integer.parseInt(s[1])+1;
			c=0;
			for(i=A;i<B;i++){
				if(x[i]) c++;
			}
			System.out.printf("%.2f\n",100.0*(float)(c)/(B-A));
			//sb.append(100.0*(float)(c)/(B-A)).append('\n');
		}
	}
}
