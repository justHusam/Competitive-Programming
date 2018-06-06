#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		int a, b, c;
		char x, y;
		scanf("%d %c%d %c%d", &a, &x, &b, &y, &c);
		printf("Case %d: ", it);
		if (x == '+') {
			if (a + b == c)
				puts("YES");
			else
				puts("NO");
		} else {
			if (a - b == c)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
