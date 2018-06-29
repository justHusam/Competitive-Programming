#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 8;
int n, g[N][N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		vector<int> p;
		for (int i = 0; i < n; ++i)
			p.push_back(i);
		int res = 1e9;
		do {
			int can = 0;
			for (int i = 0; i < n; ++i)
				can += g[i][p[i]];
			res = min(res, can);
		} while (next_permutation(p.begin(), p.end()));
		printf("%d\n", res);
	}
	return 0;
}
