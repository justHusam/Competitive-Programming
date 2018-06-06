#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[111];
		scanf("%s", s);
		map<char, int> hs;
		for (int a = 0; s[a]; ++a)
			++hs[s[a]];
		int mx = 0;
		map<char, int>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it)
			mx = max(mx, it->second);
		printf("%d ", mx);
		for (it = hs.begin(); it != hs.end(); ++it)
			if (it->second == mx)
				printf("%c", it->first);
		puts("");
	}
	return 0;
}
