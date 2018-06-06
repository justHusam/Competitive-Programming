#include <bits/stdc++.h>
using namespace std;

int n, a, b;
char s[201];
vector<int> g[3];

int main(int argc, char **argv) {
	scanf("%d%d%d%s", &n, &a, &b, s);
	for (int i = 0; i < n; ++i)
		g[s[i] - '0'].push_back(i);
	string ss = s;
	while ((int) g[0].size() > a) {
		int x = g[0].back();
		g[0].pop_back();
		ss[x] = '2';
		g[2].push_back(x);
	}
	while ((int) g[1].size() > b) {
		int x = g[1].back();
		g[1].pop_back();
		ss[x] = '2';
		g[2].push_back(x);
	}
	while ((int) g[0].size() < a && !g[2].empty()) {
		int x = g[2].back();
		g[2].pop_back();
		ss[x] = '0';
		g[0].push_back(x);
	}
	while ((int) g[1].size() < b && !g[2].empty()) {
		int x = g[2].back();
		g[2].pop_back();
		ss[x] = '1';
		g[1].push_back(x);
	}
	if ((int) g[0].size() != a || (int) g[1].size() != b)
		puts("-1");
	else {
		int need = 0;
		for (int i = 0; i < n; ++i)
			need += s[i] != ss[i];
		printf("%d\n%s\n", need, ss.c_str());
	}
	return 0;
}
