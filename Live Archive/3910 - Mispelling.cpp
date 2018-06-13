#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char word[81];
	int T, m;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		scanf("%d%s", &m, word);
		memmove(&word[m - 1], &word[m], strlen(word) - (m - 1));
		printf("%d %s\n", it, word);
	}
	return 0;
}
