#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, change, res[3];
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		scanf("%d", &change);
		res[0] = change / 25;
		change %= 25;
		res[1] = change / 10;
		change %= 10;
		res[2] = change / 5;
		change %= 5;
		res[3] = change / 1;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", it, res[0], res[1], res[2], res[3]);
	}
	return 0;
}
