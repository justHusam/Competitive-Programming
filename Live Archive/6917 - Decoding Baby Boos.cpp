#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
char s[N], st[26];
vector<int> at[26];
int n, m;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%d", s, &m);
		n = strlen(s);
		for (int i = 0; i < 26; ++i) {
			at[i].clear();
			at[i].push_back(i);
		}
		while (m-- != 0) {
			char a, b;
			scanf(" %c %c", &a, &b);
			a -= 'A';
			b -= 'A';
			while (!at[b].empty()) {
				at[a].push_back(at[b].back());
				at[b].pop_back();
			}
		}
		for (int i = 0; i < 26; ++i)
			for (size_t j = 0; j < at[i].size(); ++j)
				st[at[i][j]] = char(i + 'A');
		for (int i = 0; i < n; ++i)
			if (s[i] == '_')
				printf("_");
			else
				printf("%c", st[s[i] - 'A']);
		puts("");
	}
	return 0;
}
