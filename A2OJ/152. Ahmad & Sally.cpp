#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, p = 999999;
		scanf("%d", &n);
		p -= n;
		++p;
		printf("%d", p++);
		for (int i = 1; i < n; ++i)
			printf(" %d", p++);
		puts("");
	}
	return 0;
}
