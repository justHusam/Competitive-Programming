#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
char s[N];

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0) {
		int n = strlen(s);
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			if (!isdigit(s[i]))
				continue;
			int sum = 0, mod[3] = { };
			while (i < n && isdigit(s[i])) {
				sum += s[i] - '0';
				if (sum % 3 == 0)
					++res;
				res += mod[sum % 3];
				++mod[sum % 3];
				++i;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
