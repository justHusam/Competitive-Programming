#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[80];
	while (scanf("%s", s) && s[0] != '#') {
		int y = 0, n = 0, a = 0;
		int len = strlen(s);
		for (int i = 0; i < len; ++i) {
			if (s[i] == 'Y')
				++y;
			else if (s[i] == 'N')
				++n;
			else if (s[i] == 'A')
				++a;
		}
		if (a * 2 >= len)
			puts("need quorum");
		else if (y > n)
			puts("yes");
		else if (n > y)
			puts("no");
		else
			puts("tie");
	}
	return 0;
}
