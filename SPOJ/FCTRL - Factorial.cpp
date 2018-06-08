#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		int sum = 0, div = n / 5;
		while (div > 0) {
			sum += div;
			div /= 5;
		}
		printf("%d\n", sum);
	}
	return 0;
}
