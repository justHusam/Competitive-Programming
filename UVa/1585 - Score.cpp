#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[100];
		scanf("%s", s);
		int n = strlen(s), res = 0, cur = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'X')
				cur = 0;
			else
				res += ++cur;
		printf("%d\n", res);
	}
	return 0;
}
