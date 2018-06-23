#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	cin.ignore();
	cin.ignore();
	while (T-- != 0) {
		vector<string> v;
		char s[30];
		while (gets(s) > 0 && strlen(s))
			v.push_back(s);
		int g[26][26] = { };
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t j = 0; j < v[i].size(); ++j)
				g[i + 1][j + 1] = (v[i][j] - '0') + g[i][j + 1] + g[i + 1][j] - g[i][j];
		int res = 0, n = v.size();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = i; k <= n; ++k)
					for (int l = j; l <= n; ++l) {
						int c = g[k][l] - g[k][j - 1] - g[i - 1][l] + g[i - 1][j - 1];
						int a = (k - i + 1) * (l - j + 1);
						if (c == a)
							res = max(res, a);
					}
		printf("%d\n", res);
		if (T != 0)
			puts("");
	}
	return 0;
}
