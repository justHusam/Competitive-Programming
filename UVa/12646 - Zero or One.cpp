#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char calc(int a, int b, int c) {
	int o = 0, z = 0;
	o = a + b + c;
	z = !a + !b + !c;
	if (o == 1) {
		if (a == 1)
			return 'A';
		if (b == 1)
			return 'B';
		return 'C';
	}
	if (z == 1) {
		if (a == 0)
			return 'A';
		if (b == 0)
			return 'B';
		return 'C';
	}
	return '*';
}

int main(int argc, char **argv) {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) > 0) {
		printf("%c\n", calc(a, b, c));
	}
	return 0;
}
