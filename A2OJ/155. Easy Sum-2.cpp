#include <bits/stdc++.h>
using namespace std;

const int M = 33554431;

int main(int argc, char **argv) {
	int cum[25] = { };
	cum[0] = pow(2, 0);
	for (int a = 1; a < 25; a++)
		cum[a] = cum[a - 1] + pow(2, a);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, r;
		scanf("%d", &n);
		printf("%d\n", cum[n % 25] % M);
	}
	return 0;
}
