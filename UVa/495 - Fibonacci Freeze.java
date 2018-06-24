import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[5005];
		dp[0] = BigInteger.ZERO;
		dp[1] = BigInteger.ONE;
		for (int i = 2; i <= 5001; ++i)
			dp[i] = (dp[i - 1]).add(dp[i - 2]);
		while (input.hasNext()) {
			int n = input.nextInt();
			System.out.println("The Fibonacci number for " + n + " is " + dp[n]);
		}
		input.close();
	}
}