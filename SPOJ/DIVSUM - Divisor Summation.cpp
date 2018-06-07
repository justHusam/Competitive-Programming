#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i * i <= n; i++)
			if (n % i == 0)
				if (i * i == n)
					sum += i;
				else
					sum += i + n / i;
		printf("%d\n", sum - n);
	}
	return 0;
}
