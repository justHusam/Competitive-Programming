#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[155];
vector<string> v, hs;
vector<int> vv;
int freq[100001];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	getchar();
	while (t-- != 0) {
		v.clear();
		hs.clear();
		while (gets(s) > 0 && strcmp(s, "END")) {
			string w = "";
			int n = strlen(s);
			for (int i = 0; i < n; ++i) {
				if (isalpha(s[i]))
					w += s[i];
				else {
					if (w.size() > 0) {
						v.push_back(w);
						hs.push_back(w);
					}
					w = "";
				}
			}
			if (w.size() > 0) {
				v.push_back(w);
				hs.push_back(w);
			}
		}
		sort(hs.begin(), hs.end());
		hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
		vv.clear();
		vv.resize(v.size());
		for (size_t i = 0; i < v.size(); ++i)
			vv[i] = lower_bound(hs.begin(), hs.end(), v[i]) - hs.begin();
		int need = hs.size(), sz = 0;
		for (int i = 0; i < need; ++i)
			freq[i] = 0;
		queue<pair<int, int> > qu;
		int len = 2e9, str = -1;
		for (size_t i = 0; i < v.size(); ++i) {
			qu.push(make_pair(vv[i], i));
			if (!freq[vv[i]])
				++sz;
			++freq[vv[i]];
			while (sz == need) {
				pair<int, int> fr = qu.front();
				if ((int) qu.size() < len) {
					len = qu.size();
					str = fr.second + 1;
				}
				qu.pop();
				--freq[fr.first];
				if (!freq[fr.first])
					--sz;
			}
		}
		printf("Document %d: %d %d\n", cas++, str, str + len - 1);
	}
	return 0;
}
