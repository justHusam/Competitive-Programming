#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1001];
vector<vector<int> > g;
vector<char> ch, res;
bool ans;

bool check(bitset<20> msk, int i) {
	bool can = true;
	for (size_t j = 0; j < g[i].size() && can; ++j)
		can &= msk[g[i][j]];
	return can;
}

bool calc(bitset<20> msk, int len) {
	if (len == (int) ch.size()) {
		for (int i = 0; i < len; ++i)
			printf("%s%c", i ? " " : "", res[i]);
		puts("");
		return true;
	}
	bool can = false;
	for (size_t i = 0; i < ch.size(); ++i)
		if (!msk[i] && check(msk, i)) {
			msk[i] = 1;
			res.push_back(ch[i]);
			can |= calc(msk, len + 1);
			msk[i] = 0;
			res.pop_back();
		}
	return can;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	getchar();
	while (T-- != 0) {
		gets(s);
		gets(s);
		ch.clear();
		for (int i = 0; s[i]; ++i)
			if (isalpha(s[i]))
				ch.push_back(s[i]);
		map<char, int> hs;
		for (size_t i = 0; i < ch.size(); ++i)
			hs[ch[i]] = i;
		g.clear();
		g.resize(ch.size());
		gets(s);
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
			g[hs[z[2]]].push_back(hs[z[0]]);
		if (!calc(0, 0))
			puts("NO");
		if (T)
			puts("");
	}
	return 0;
}
