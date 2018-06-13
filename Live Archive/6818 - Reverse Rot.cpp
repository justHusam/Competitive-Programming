#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
char s[42];
char ch[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '.' };

int find(char c) {
	for (int i = 0;; ++i)
		if (c == ch[i])
			return i;
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		scanf("%s", s);
		int len = strlen(s);
		reverse(s, s + len);
		for (int i = 0; i < len; ++i) {
			int x = find(s[i]);
			s[i] = ch[(x + n) % 28];
		}
		puts(s);
	}
	return 0;
}
