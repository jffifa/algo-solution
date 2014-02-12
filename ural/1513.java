import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i, j, k, N, K;
		BigInteger f[] = new BigInteger[10100];
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		K = in.nextInt();
		K++;
		f[0] = BigInteger.ONE;
		for (i = 1; i <= N; ++i)
		{
			f[i] = f[i-1].multiply(BigInteger.valueOf(2));
			if (i==K) f[i] = f[i].subtract(BigInteger.ONE);
			else if (i>K) f[i] = f[i].subtract(f[i-K-1]);
		}
		System.out.println(f[N]);
	}

}
