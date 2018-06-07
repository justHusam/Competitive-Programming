#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, n;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		if ((n & 1) == 1)
			printf("%d\n", n);
		else {
			int res = 0;
			string binary = "";
			while (n != 0) {
				binary += char((n & 1) + '0');
				n >>= 1;
			}
			int Pow = 1;
			for (int i = binary.length() - 1; i >= 0; i--, Pow <<= 1)
				if (binary[i] == '1')
					res += Pow;
			printf("%d\n", res);
		}
	}
	return 0;
}
