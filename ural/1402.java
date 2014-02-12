import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i, j, N;
		BigInteger c[][] = new BigInteger[22][22];
		for (i = 0; i < 22; ++i)
			for (j = 0; j < 22; ++j)
				c[i][j] = new BigInteger("0");
		BigInteger f[] = new BigInteger[22];
		for (i = 0; i < 22; ++i)
			f[i]= new BigInteger("0");
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		c[0][0] = BigInteger.ONE;
		f[0] = BigInteger.ONE;
		for (i = 1; i <= N; ++i) {
			c[i][0] = BigInteger.ONE;
			for (j = 1; j <= i; ++j)
				c[i][j] = c[i-1][j].add(c[i-1][j-1]);
			f[i]= f[i-1].multiply(BigInteger.valueOf(i)); 
		}
		BigInteger ans = BigInteger.ZERO;
		for (i = 2; i <= N; ++i)
			ans = ans.add(c[N][i].multiply(f[i]));
		System.out.println(ans);
	}
}
