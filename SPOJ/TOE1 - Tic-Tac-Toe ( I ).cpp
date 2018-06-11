#include <bits/stdc++.h>
using namespace std;

char g[3][3];

bool check(char ch) {
	for (int i = 0; i < 3; i++)
		if (g[i][0] == ch && g[i][1] == ch && g[i][2] == ch)
			return false;
	for (int j = 0; j < 3; j++)
		if (g[0][j] == ch && g[1][j] == ch && g[2][j] == ch)
			return false;
	if (g[0][0] == ch && g[1][1] == ch && g[2][2] == ch)
		return false;
	if (g[0][2] == ch && g[1][1] == ch && g[2][0] == ch)
		return false;
	return true;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int xC = 0, oC = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == 'X')
					++xC;
				else if (g[i][j] == 'O')
					++oC;
			}
		bool ok = true;
		if (xC - oC == 1 || xC - oC == 0) {
			if (xC - oC == 1) {
				if (!check('O'))
					ok = false;
			} else if (!check('X'))
				ok = false;
		} else
			ok = false;
		if (ok)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
