import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static BigInteger[][] dp = new BigInteger[10005][3];
	static int n;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		for (int i = 0; i < 10005; ++i)
			for (int j = 0; j < 3; ++j)
				dp[i][j] = BigInteger.valueOf(-1);
		System.out.println(calc(0, 2));
		in.close();
	}

	static BigInteger calc(int c, int d) {
		if (c == n)
			return BigInteger.ONE;
		if (dp[c][d].compareTo(new BigInteger("-1")) == 1)
			return dp[c][d];
		BigInteger res = calc(c + 1, 1);
		if (d != 0)
			res = res.add(calc(c + 1, 0));
		return dp[c][d] = res;
	}
}