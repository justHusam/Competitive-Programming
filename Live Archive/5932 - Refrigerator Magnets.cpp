#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	char s[61];
	while (gets(s) && strcmp(s, "END")) {
		bool res = true, vis[26] = { };
		for (int i = 0; s[i]; ++i)
			if (s[i] != ' ') {
				if (vis[s[i] - 'A'])
					res = false;
				vis[s[i] - 'A'] = true;
			}
		if (res)
			puts(s);
	}
	return 0;
}
