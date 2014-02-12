import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
	public static void main(String[] args) {
		int i, j, k, N, u, v;
		BigInteger f[][][][] = new BigInteger[33][33][33][3];
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		f[0][0][0][0] = BigInteger.ONE;
		for (i = 0; i <= N; ++i)
			for (j = 0; j <= N; ++j)
				for (k = 0; k <= N; ++k)
					for (u = 0; u < 3; ++u)
					{
						if (i==0&&j==0&&k==0&&u==0) continue;
						f[i][j][k][u] = BigInteger.ZERO;
						if (i>1&&u!=0) f[i][j][k][u] = f[i][j][k][u].add(f[i-1][j][k][0].multiply(BigInteger.valueOf((i-1))));
						else if (i!=0&&u!=0) f[i][j][k][u] = f[i][j][k][u].add(f[i-1][j][k][0].multiply(BigInteger.valueOf(i)));
						if (j!=0&&u!=1) f[i][j][k][u] = f[i][j][k][u].add(f[i][j-1][k][1].multiply(BigInteger.valueOf(j)));
						if (k!=0&&u!=2) f[i][j][k][u] = f[i][j][k][u].add(f[i][j][k-1][2].multiply(BigInteger.valueOf(k)));
					}
		System.out.println(f[N][N][N][0].divide(BigInteger.valueOf(2)));
	}
}
