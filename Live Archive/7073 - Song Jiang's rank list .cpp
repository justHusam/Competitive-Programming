#include <bits/stdc++.h>
using namespace std;

int n, freq[301];
pair<int, string> v[200];
map<string, int> hs;
vector<string> at[301];

int main(int argc, char **argv) {
	while (cin >> n && n != 0) {
		for (int i = 0; i <= 300; ++i) {
			at[i].clear();
			freq[i] = 0;
		}
		hs.clear();
		for (int i = 0; i < n; ++i) {
			cin >> v[i].second >> v[i].first;
			++freq[v[i].first];
			hs[v[i].second] = v[i].first;
			at[v[i].first].push_back(v[i].second);
			v[i].first *= -1;
		}
		sort(v, v + n);
		for (int i = 0; i < n; ++i)
			printf("%s %d\n", v[i].second.c_str(), -v[i].first);
		for (int i = 1; i <= 300; ++i) {
			freq[i] += freq[i - 1];
			sort(at[i].begin(), at[i].end());
		}
		int q;
		cin >> q;
		string s;
		while (q-- != 0) {
			cin >> s;
			int k = hs[s];
			int mj = freq[300] - freq[k] + 1;
			int mn = lower_bound(at[k].begin(), at[k].end(), s) - at[k].begin() + 1;
			printf("%d", mj);
			if (mn > 1)
				printf(" %d", mn);
			puts("");
		}
	}
	return 0;
}
