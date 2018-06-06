#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T, cas = 1;
	cin >> T;
	while (T-- != 0) {
		int n, k;
		cin >> n >> k;
		map<string, int> hs;
		while (n-- != 0) {
			string s, x, y, k;
			cin >> s;
			if (s[0] == 'l')
				cin >> y >> k;
			else
				cin >> x >> y >> k;
			++hs[y.substr(0, y.size() - 2)];
		}
		vector<pair<int, string> > v;
		map<string, int>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it)
			v.push_back(make_pair(-it->second, it->first));
		sort(v.begin(), v.end());
		printf("Case %d:\n", cas++);
		for (int i = 0; i < k; ++i)
			puts(v[i].second.c_str());
	}
	return 0;
}
