#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d\n", &T);
	while (T-- != 0) {
		int n;
		scanf("%d\n", &n);
		map<string, string> hs;
		for (int i = 0; i < n; ++i) {
			char s[90], ss[90];
			gets(s);
			gets(ss);
			hs[s] = ss;
		}
		int m, mx = 0;
		scanf("%d\n", &m);
		map<string, int> freq;
		for (int i = 0; i < m; ++i) {
			char s[90];
			gets(s);
			++freq[s];
			mx = max(mx, freq[s]);

		}
		vector<string> v;
		map<string, int>::iterator it;
		for (it = freq.begin(); it != freq.end(); ++it)
			if (it->second == mx)
				v.push_back(hs[it->first]);
		string res = "tie";
		if (v.size() == 1)
			res = v[0];
		puts(res.c_str());
		if (T != 0)
			puts("");
	}
	return 0;
}
