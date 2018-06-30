#include <bits/stdc++.h>
using namespace std;

char s[500];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	while (t-- != 0) {
		vector<string> v;
		while (gets(s) > 0 && strlen(s))
			v.push_back(s);
		map<string, set<pair<int, int> > > f;
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t j = 0; j < v.size(); ++j)
				if (i != j)
					f[v[i] + v[j]].insert(make_pair(min(i, j), max(i, j)));
		map<string, set<pair<int, int> > >::iterator it;
		string res = "";
		for (it = f.begin(); it != f.end(); ++it)
			if (it->second.size() >= v.size() / 2) {
				res = it->first;
				break;
			}
		puts(res.c_str());
		if (t != 0)
			puts("");
	}
	return 0;
}
