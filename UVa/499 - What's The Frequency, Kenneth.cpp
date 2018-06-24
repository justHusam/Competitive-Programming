#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[1000];
	while (gets(s) > 0) {
		int freq[52] = { };
		int mx = 0, n = strlen(s);
		for (int i = 0; i < n; ++i)
			if (isupper(s[i]))
				++freq[s[i] - 'A'];
			else
				++freq[s[i] - 'a' + 26];
		for (int i = 0; i < 52; ++i)
			mx = max(mx, freq[i]);
		if (mx != 0) {
			for (int i = 0; i < 52; ++i)
				if (freq[i] == mx) {
					if (i < 26)
						printf("%c", 'A' + i);
					else
						printf("%c", 'a' + i - 26);
				}
			printf(" %d\n", mx);
		}
	}
	return 0;
}
