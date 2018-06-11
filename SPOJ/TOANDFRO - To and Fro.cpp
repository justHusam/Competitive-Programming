#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char s[222], g[200][200];

int main(int argc, char **argv) {
	int m;
	while (scanf("%d", &m) && m) {
		scanf("%s", s);
		int n = strlen(s) / m, at = 0;
		for (int i = 0; i < n; ++i) {
			if ((i & 1) == 0)
				for (int j = m - 1; j >= 0; --j)
					g[i][j] = s[at++];
			else
				for (int j = 0; j < m; ++j)
					g[i][j] = s[at++];
		}
		for (int j = 0; j < m; ++j)
			for (int i = 0; i < n; ++i)
				printf("%c", g[i][j]);
		puts("");
	}
	return 0;
}
