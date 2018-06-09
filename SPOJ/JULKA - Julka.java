import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigDecimal a = new BigDecimal(in.next());
			BigDecimal b = new BigDecimal(in.next());
			BigDecimal kA = a.add(b).divide(new BigDecimal("2")).stripTrailingZeros();
			BigDecimal nA = a.subtract(kA).stripTrailingZeros();
			System.out.println(kA.toPlainString());
			System.out.println(nA.toPlainString());
		}
		in.close();
	}
}