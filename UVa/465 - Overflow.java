import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String number1 = "", number2 = "", sign = "", temp;
		while (in.hasNext()) {
			String s = in.nextLine();
			boolean flag1 = true, flag2 = true, flag3 = true;
			System.out.println(s);
			for (int i = 0, j; i < s.length(); ++i) {
				temp = "";
				for (j = i; j < s.length() && s.charAt(j) != ' '; ++j)
					temp += s.charAt(j);
				i = j;
				if (flag1 && temp != "") {
					flag1 = false;
					number1 = temp;
				} else if (flag2 && temp != "") {
					flag2 = false;
					sign = temp;
				} else if (flag3 && temp != "") {
					flag3 = false;
					number2 = temp;
				}
				if (!flag1 && !flag2 && !flag3)
					break;
			}
			BigInteger x = new BigInteger(number1), y = new BigInteger(number2), res;
			System.out.println(s);
			if (x.compareTo(new BigInteger("2147483647")) == 1)
				System.out.println("first number too big");
			if (y.compareTo(new BigInteger("2147483647")) == 1)
				System.out.println("second number too big");
			if (sign.charAt(0) == '+')
				res = x.add(y);
			else
				res = x.multiply(y);
			if (res.compareTo(new BigInteger("2147483647")) == 1)
				System.out.println("result too big");
		}
		in.close();
	}
}