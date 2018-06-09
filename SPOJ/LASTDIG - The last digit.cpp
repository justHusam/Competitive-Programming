#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b == 0)
			printf("1\n");
		else {
			int Pow;
			if (b % 4 == 0)
				Pow = 4;
			else
				Pow = b % 4;
			printf("%d\n", (int(pow(a, Pow))) % 10);
		}
	}
	return 0;
}
