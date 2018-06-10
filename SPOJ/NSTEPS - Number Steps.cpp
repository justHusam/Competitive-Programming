#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, x, y;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &x, &y);
		if (x % 2 == 0 && y % 2 == 0 && (x == y || y == x - 2))
			printf("%d\n", x + y);
		else if (x % 2 != 0 && y % 2 != 0 && (x == y || y == x - 2))
			printf("%d\n", x + y - 1);
		else
			printf("No Number\n");
	}
	return 0;
}
