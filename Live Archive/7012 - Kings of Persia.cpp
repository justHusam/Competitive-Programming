#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) && (a || b || c || d)) {
		printf("%d %d\n", c - b, d - a);
	}
	return 0;
}
