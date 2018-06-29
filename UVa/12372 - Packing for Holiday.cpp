#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("Case %d: ", k++);
		if (a <= 20 && b <= 20 && c <= 20)
			puts("good");
		else
			puts("bad");
	}
	return 0;
}
