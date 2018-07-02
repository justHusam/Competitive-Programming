#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int n, len;
vector<string> v;

inline bool calc(int i) {
	int res = 0;
	for (int j = 0; j < len; ++j)
		res += v[0][j] != v[i][j];
	return res == 1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &len) > 0) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		vector<string> res;
		vector<bool> vis(n);
		res.push_back(v[0]);
		while (true) {
			if (v[0] == v[1])
				break;
			for (int i = 0; i < n; ++i)
				if (!vis[i] && calc(i)) {
					vis[i] = true;
					res.push_back(v[i]);
					v[0] = v[i];
					break;
				}
		}
		for (size_t i = 0; i < res.size(); ++i)
			puts(res[i].c_str());
	}
	return 0;
}
