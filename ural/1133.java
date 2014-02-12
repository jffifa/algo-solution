import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		int i, j, N, M, K;
		BigInteger xN, xM, xK = new BigInteger("0");
		BigInteger f[] = new BigInteger[2020];
		for (i = 0; i < 2020; ++i)
			f[i] = new BigInteger("0");
		f[0] = BigInteger.valueOf(0);
		f[1] = BigInteger.valueOf(1);
		for (i = 2; i < 2020; ++i)
			f[i] = f[i-1].add(f[i-2]);
		Scanner in = new Scanner(System.in);
		M = in.nextInt();
		xM = in.nextBigInteger();
		N = in.nextInt();
		xN = in.nextBigInteger();
		K = in.nextInt();
		int tmp;
		BigInteger tb;
		if (M>N)
		{
			tmp = M;
			M = N;
			N = tmp;
			tb = xM;
			xM = xN;
			xN = tb;
		}
		N -= M;
		K -= M;
		xN = (xN.subtract(f[N-1].multiply(xM))).divide(f[N]);
		if (K>0)
		{
			for (i = 1; i <= K; ++i)
			{
				xK = xN;
				xN = xM.add(xN);
				xM = xK;
			}
		}
		else
		{
			for (i = 0; i >= K; --i)
			{
				xK = xM;
				xM = xN.subtract(xM);
				xN = xK;
			}
		}
		System.out.println(xK);
	}
}
