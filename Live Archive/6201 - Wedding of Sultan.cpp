#include <bits/stdc++.h>
using namespace std;

char s[100];
int n, res[26], at;
bool w[26];

void DFS(int p) {
	if (at != 1)
		++res[p];
	if (at == n)
		return;
	while (at < n) {
		if (p == s[at] - 'A') {
			++at;
			break;
		}
		++res[p];
		DFS(s[at++] - 'A');
	}
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < 26; ++i) {
			res[i] = 0;
			w[i] = false;
		}
		for (int i = 0; i < n; ++i)
			w[s[i] - 'A'] = true;
		at = 1;
		DFS(s[0] - 'A');
		printf("Case %d\n", cas++);
		for (int i = 0; i < 26; ++i)
			if (w[i])
				printf("%c = %d\n", char(i + 'A'), res[i]);
	}
	return 0;
}
