#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[101];
char arr[10][4] = { { 'A', 'B', 'C', '#' }, { 'D', 'E', 'F', '#' }, { 'G', 'H', 'I', '#' }, { 'J', 'K', 'L', '#' }, { 'M', 'N', 'O', '#' }, { 'P', 'Q', 'R', 'S' }, { 'T', 'U', 'V', '#' }, { 'W', 'X', 'Y', 'Z' } };
int sz[10] = { 3, 3, 3, 3, 3, 4, 3, 4 };

inline pair<int, int> get(char c) {
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < sz[i]; ++j)
			if (arr[i][j] == c)
				return make_pair(i, j);
	return make_pair(-1, -1);
}

int main(int argc, char **argv) {
	while (scanf("%s", s) && s[0] != '#') {
		string sol = "";
		int n = strlen(s);
		for (int i = 0; i < n; ++i) {
			char c = toupper(s[i]);
			pair<int, int> p = get(c);
			int mod = sz[p.first];
			int res = ((p.second - (i + 1)) % mod + mod) % mod;
			sol += arr[p.first][res];
			if (islower(s[i]))
				sol.back() = tolower(sol.back());
		}
		puts(sol.c_str());
	}
	return 0;
}
