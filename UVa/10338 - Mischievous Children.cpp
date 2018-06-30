#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ll f[21] = { };
	f[0] = 1;
	for (int i = 1; i <= 20; ++i)
		f[i] = f[i - 1] * i;
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[30];
		scanf("%s", s);
		int freq[26] = { }, n = strlen(s);
		for (int i = 0; i < n; ++i)
			++freq[s[i] - 'A'];
		ll res = f[n];
		for (int i = 0; i < 26; ++i)
			res /= f[freq[i]];
		printf("Data set %d: %lld\n", cas++, res);
	}
	return 0;
}