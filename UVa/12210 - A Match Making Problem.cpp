#include <bits/stdc++.h>
using namespace std;

int n, m, freq[61];
vector<int> v;

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &m) > 0 && (n != 0 || m != 0)) {
		memset(freq, 0, sizeof freq);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = 0, x; i < m; ++i) {
			scanf("%d", &x);
			++freq[x];
		}
		sort(v.begin(), v.end());
		while (!v.empty()) {
			int at = v.back();
			int go = -1;
			for (int i = 2; i <= 60; ++i)
				if (freq[i] != 0 && (go == -1 || abs(i - at) <= abs(i - go)))
					go = i;
			if (go == -1)
				break;
			v.pop_back();
			--freq[go];
		}
		printf("Case %d: ", cas++);
		if (v.empty())
			puts("0");
		else
			printf("%d %d\n", (int) v.size(), v[0]);
	}
	return 0;
}
