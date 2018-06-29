#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50;
int n;
char s[N];

int calc() {
	int res = 0, j = n;
	for (int i = 0; i < n; ++i, --j)
		res += (s[i] - '0') * (pow(2, j) - 1);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0) {
		n = strlen(s);
		if (n == 1 && s[0] == '0')
			break;
		printf("%d\n", calc());
	}
	return 0;
}
