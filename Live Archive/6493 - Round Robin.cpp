#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[100];

int main(int argc, char **argv) {
	int n, t;
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &t);
		int cnt = 0;
		vector<int> v;
		for (int i = 0; i < n; ++i)
			v.push_back(i);
		memset(freq, 0, sizeof freq);
		int pos = 0;
		while (true) {
			++cnt;
			for (int i = 0; i < t; ++i) {
				++freq[v[pos]];
				if (i + 1 != t)
					pos = (pos + 1) % v.size();
			}
			v.erase(v.begin() + pos);
			bool ok = true;
			for (size_t i = 0; i < v.size() && ok; ++i)
				ok &= freq[v[i]] == freq[v[0]];
			if (ok)
				break;
		}
		printf("%d %d\n", (int) v.size(), freq[v[0]]);
	}
	return 0;
}
