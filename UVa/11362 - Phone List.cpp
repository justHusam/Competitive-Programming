#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

vector<vector<int> > g;
vector<int> p, e;

void add(char *s) {
	int cur = 0;
	for (int i = 0; s[i]; ++i) {
		if (g[cur][s[i] - '0'] == -1) {
			g.push_back(vector<int>(10, -1));
			g[cur][s[i] - '0'] = g.size() - 1;
			e.push_back(0);
			p.push_back(0);
		}
		cur = g[cur][s[i] - '0'];
		++p[cur];
	}
	++e[cur];
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		g.clear();
		e.clear();
		p.clear();
		g.push_back(vector<int>(10, -1));
		e.push_back(0);
		p.push_back(0);
		int n;
		scanf("%d", &n);
		while (n-- != 0) {
			char s[12];
			scanf("%s", s);
			add(s);
		}
		bool res = true;
		for (size_t i = 0; i < e.size() && res; ++i)
			if (e[i] && p[i] > 1)
				res = false;
		if (res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}