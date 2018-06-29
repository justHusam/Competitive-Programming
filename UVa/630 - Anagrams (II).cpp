#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map<string, int> hs;
map<string, int>::iterator it;
vector<vector<string> > g;
char s[22];

inline int getIdx(string s) {
	sort(s.begin(), s.end());
	it = hs.find(s);
	if (it == hs.end()) {
		hs[s] = g.size();
		g.push_back(vector<string>());
		return g.size() - 1;
	}
	return it->second;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		hs.clear();
		g.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int at = getIdx(s);
			g[at].push_back(s);
		}
		while (scanf("%s", s) != EOF && s[0] != 'E') {
			string z = s;
			sort(z.begin(), z.end());
			it = hs.find(z);
			if (it == hs.end()) {
				printf("Anagrams for: %s\nNo anagrams for: %s\n", s, s);
				continue;
			}
			printf("Anagrams for: %s\n", s);
			for (size_t i = 0; i < g[it->second].size(); ++i)
				printf("%3d) %s\n", i + 1, g[it->second][i].c_str());
		}
		if (T != 0)
			puts("");
	}
	return 0;
}
