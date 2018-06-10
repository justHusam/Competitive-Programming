#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 51;
char s[N][N];
int n;
vector<int> g[N];
bitset<N> msk[N];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s", s[0]);
		n = strlen(s[0]);
		for (int i = 1; i < n; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			msk[i].reset();
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j] == 'Y') {
					g[i].push_back(j);
					msk[i][j] = 1;
				}
		int best = -1, at = -1;
		for (int i = 0; i < n; ++i) {
			bitset<N> bs = 0;
			for (size_t j = 0; j < g[i].size(); ++j)
				bs.operator |=(msk[g[i][j]]);
			msk[i].flip();
			bs.operator &=(msk[i]);
			bs[i] = 0;
			msk[i].flip();
			if ((int) bs.count() > best) {
				best = bs.count();
				at = i;
			}
		}
		printf("%d %d\n", at, best);
	}
	return 0;
}
