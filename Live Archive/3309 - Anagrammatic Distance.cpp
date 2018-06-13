#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char a[111], b[111];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	getchar();
	while (t-- != 0) {
		gets(a);
		gets(b);
		int f[26][2] = { };
		for (int i = 0; a[i]; ++i)
			++f[a[i] - 'a'][0];
		for (int i = 0; b[i]; ++i)
			++f[b[i] - 'a'][1];
		int res = 0;
		for (int i = 0; i < 26; ++i)
			res += abs(f[i][0] - f[i][1]);
		printf("Case #%d:  %d\n", cas++, res);
	}
	return 0;
}
