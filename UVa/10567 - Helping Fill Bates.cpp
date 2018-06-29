#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1000001], z[110];
vector<int> Next[52];

inline int getIndex(char c) {
	if (isupper(c))
		return c - 'A';
	return c - 'a' + 26;
}

int main(int argc, char **argv) {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		Next[getIndex(s[i])].push_back(i);
	int q;
	scanf("%d", &q);
	while (q-- != 0) {
		int pos = -1, from = -1;
		scanf("%s", z);
		int m = strlen(z);
		for (int i = 0; i < m; ++i) {
			int index = getIndex(z[i]);
			size_t goTo = upper_bound(Next[index].begin(), Next[index].end(), pos) - Next[index].begin();
			if (goTo == Next[index].size()) {
				from = pos = -1;
				break;
			}
			if (pos == -1)
				from = Next[index][goTo];
			pos = Next[index][goTo];
		}
		if (pos == -1)
			puts("Not matched");
		else
			printf("Matched %d %d\n", from, pos);
	}
	return 0;
}
