#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char g[8][20];

int calc(int n) {
	int res = 0;
	for (; n > 0; n >>= 1)
		if ((n & 1) == 1)
			res += 500;
		else
			res += 250;
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < 8; ++i)
			scanf("%s", g[i]);
		int A = 0, B = 0;
		vector<char> x, y;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				if (isalpha(g[i][j])) {
					A += calc(g[i][j]);
					x.push_back(g[i][j]);
				}
		for (int i = 0; i < 8; ++i)
			for (int j = 10; j < 18; ++j)
				if (isalpha(g[i][j])) {
					B += calc(g[i][j]);
					y.push_back(g[i][j]);
				}
		printf("Case %d:\n", cas++);
		if (A == B) {
			if (g[5][1] == '_' && g[5][11] == '_')
				puts("The figure is correct.");
			else {
				string s[] = { "........||........", ".../\\...||.../\\...", "../..\\..||../..\\..", "./....\\.||./....\\.", "/......\\||/......\\", "\\______/||\\______/", "........||........", "------------------" };
				for (size_t i = 0; i < x.size(); ++i)
					s[4][i + 1] = x[i];
				for (size_t i = 0; i < y.size(); ++i)
					s[4][i + 11] = y[i];
				for (int i = 0; i < 7; ++i)
					printf("%s\n", s[i].c_str());
			}
			continue;
		} else if (A < B) {
			if (g[0][3] == '/') {
				puts("The figure is correct.");
			} else {
				string s[] = { ".../\\...||........", "../..\\..||........", "./....\\.||.../\\...", "/......\\||../..\\..", "\\______/||./....\\.", "........||/......\\", "........||\\______/", "------------------" };
				for (size_t i = 0; i < x.size(); ++i)
					s[3][i + 1] = x[i];
				for (size_t i = 0; i < y.size(); ++i)
					s[5][i + 11] = y[i];
				for (int i = 0; i < 7; ++i)
					printf("%s\n", s[i].c_str());
			}
			continue;
		} else {
			if (g[0][13] == '/')
				puts("The figure is correct.");
			else {
				string s[] = { "........||.../\\...", "........||../..\\..", ".../\\...||./....\\.", "../..\\..||/......\\", "./....\\.||\\______/", "/......\\||........", "\\______/||........", "------------------" };
				for (size_t i = 0; i < x.size(); ++i)
					s[5][i + 1] = x[i];
				for (size_t i = 0; i < y.size(); ++i)
					s[3][i + 11] = y[i];
				for (int i = 0; i < 7; ++i)
					printf("%s\n", s[i].c_str());
			}
		}
	}
	return 0;
}
