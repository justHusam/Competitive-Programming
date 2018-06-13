#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e4 + 9, M = 1e9 + 7;
char s[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int str = -1;
		vector<ll> v;
		for (int i = 0; s[i]; ++i) {
			if (str == -1) {
				if (s[i] == '?')
					str = i;
				continue;
			}
			if (s[i] == '?')
				continue;
			int pre = str - 1;
			if (pre >= 0 && s[pre] != s[i])
				v.push_back(i - pre);
			str = -1;
		}
		ll res = 1;
		for (size_t i = 0; i < v.size(); ++i, res %= M)
			res *= v[i];
		printf("%lld\n", res);
	}
	return 0;
}
