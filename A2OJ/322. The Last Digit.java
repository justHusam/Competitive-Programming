import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int t = in.nextInt();
		for (int k = 1; k <= t; ++k) {
			BigInteger a = new BigInteger(in.next());
			BigInteger b = new BigInteger(in.next());
			a = a.subtract(new BigInteger("1"));
			BigInteger res = calc(b);
			res = res.subtract(calc(a));
			res = res.mod(new BigInteger("10"));
			System.out.println("Case " + k + ": " + res);
		}
	}

	static BigInteger calc(BigInteger n) {
		BigInteger res = n;
		BigInteger N = n.add(BigInteger.ONE);
		res = res.multiply(N);
		n = n.multiply(new BigInteger("2"));
		n = n.add(BigInteger.ONE);
		res = res.multiply(n);
		res = res.divide(new BigInteger("6"));
		return res;
	}
}