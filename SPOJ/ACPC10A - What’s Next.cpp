#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int a, b, c;
	while (true) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (b - a == c - b)
			printf("AP %d\n", (c + (b - a)));
		else
			printf("GP %d\n", (c * (b / a)));
	}
	return 0;
}
