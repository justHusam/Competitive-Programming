#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e5 + 1;
char s[N];

int main(int argc, char **argv) {
	int T, cas = 1;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s", s);
		int n = strlen(s);
		bool can = false;
		for (int k = 1; k < n && !can; ++k) {
			int l = 0, r = n - k;
			can = true;
			while (r < n && can)
				can &= s[l++] == s[r++];
		}
		printf("Case %d: ", cas++);
		if (can)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
