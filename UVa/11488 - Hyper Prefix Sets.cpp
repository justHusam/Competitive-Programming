#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[201];

struct Node {
	int freq;
	Node *next[2];
	Node() {
		freq = 0;
		for (int i = 0; i < 2; ++i)
			next[i] = NULL;
	}
}*Trie;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		Trie = new Node();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int m = strlen(s);
			Node *cur = Trie;
			for (int j = 0; j < m; ++j) {
				int c = s[j] - '0';
				if (cur->next[c] == NULL)
					cur->next[c] = new Node();
				cur = cur->next[c];
				++cur->freq;
				res = max(res, cur->freq * (j + 1));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
