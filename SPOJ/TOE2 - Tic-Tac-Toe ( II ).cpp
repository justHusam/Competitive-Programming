#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */
char g[3][3];

bool check(char ch) {
	char win = 'X', lose = ch;
	int cnt = 0;
	if (ch == 'X')
		win = 'O';
	for (int i = 0; i < 3; ++i) {
		if (g[i][0] == lose && g[i][1] == lose && g[i][2] == lose)
			return 0;
		if (g[i][0] == win && g[i][1] == win && g[i][2] == win)
			++cnt;
		if (g[0][i] == lose && g[1][i] == lose && g[2][i] == lose)
			return 0;
		if (g[0][i] == win && g[1][i] == win && g[2][i] == win)
			++cnt;
	}
	if (g[0][0] == lose && g[1][1] == lose && g[2][2] == lose)
		return 0;
	if (g[0][2] == lose && g[1][1] == lose && g[2][0] == lose)
		return 0;

	if (g[0][0] == win && g[1][1] == win && g[2][2] == win)
		++cnt;
	if (g[0][2] == win && g[1][1] == win && g[2][0] == win)
		++cnt;
	int dots = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			dots += g[i][j] == '.';
	return cnt > 0 || dots == 0;
}

int main(int argc, char **argv) {
	string s;
	while (cin >> s && s != "end") {
		int o = 0, x = 0;
		for (int i = 0, k = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j, ++k) {
				g[i][j] = s[k];
				if (g[i][j] == 'O')
					++o;
				if (g[i][j] == 'X')
					++x;
			}
		string res = "invalid";
		if (x == o + 1 && check('O'))
			res = "valid";
		if (x == o && check('X'))
			res = "valid";
		puts(res.c_str());
	}
	return 0;
}
