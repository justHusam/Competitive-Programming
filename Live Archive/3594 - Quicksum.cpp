#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[260];
	while (gets(s) > 0 && s[0] != '#') {
		int res = 0, n = strlen(s);
		for (int i = 0; i < n; i++)
			if (s[i] != ' ')
				res += (s[i] - 'A' + 1) * (i + 1);
		printf("%d\n", res);
	}
	return 0;
}
