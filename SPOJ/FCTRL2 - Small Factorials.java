import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while (T-- != 0) {
			BigInteger res = BigInteger.ONE;
			int n = in.nextInt();
			for (byte i = 1; i <= n; ++i)
				res = res.multiply(BigInteger.valueOf(i));
			System.out.println(res);
		}
		in.close();
	}
}
