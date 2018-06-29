#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char s[1111];

bool calc() {
	int f[10] = { }, sum = 0;
	for (int i = 0; s[i]; ++i)
		++f[s[i] - '0'], sum += s[i] - '0';
	bool res = 0;
	while (true) {
		int can = -1;
		for (int i = 0; i < 10 && can == -1; ++i)
			if ((sum - i) % 3 == 0 && f[i])
				can = i;
		if (can == -1)
			break;
		--f[can];
		sum -= can;
		res = !res;
	}
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		printf("Case %d: ", k++);
		if (calc())
			puts("S");
		else
			puts("T");
	}
	return 0;
}
