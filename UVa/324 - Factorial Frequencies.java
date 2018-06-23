import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] freq = new int[10];
		while (true) {
			int N = in.nextInt();
			if (N == 0)
				break;
			for (int i = 0; i < 10; ++i)
				freq[i] = 0;
			String sFact = calc(N);
			for (int i = 0; i < sFact.length(); ++i)
				++freq[Character.getNumericValue(sFact.charAt(i))];
			System.out.println(N + "! --");
			for (int i = 0; i < 10; ++i) {
				System.out.print("   (" + i + ")    " + freq[i]);
				if (i == 4 || i == 9)
					System.out.println("");
			}
		}
		in.close();
	}

	public static String calc(int number) {
		BigInteger fact = new BigInteger("1"), bigNum;
		for (int i = 1; i <= number; ++i) {
			bigNum = new BigInteger(Integer.toString(i));
			fact = fact.multiply(bigNum);
		}
		return fact.toString();
	}
}