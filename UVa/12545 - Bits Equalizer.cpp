#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
char a[N], b[N];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", a, b);
		int n = strlen(a), z = 0, o = 0, qZ = 0, qO = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] == '?') {
				if (b[i] == '0')
					++qZ;
				else
					++qO;
			} else if (a[i] != b[i]) {
				if (a[i] == '0')
					++z;
				else
					++o;
			}
		int res = 0;
		if (z + qO < o)
			res = -1;
		else
			res = max(o, z) + qO + qZ;
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
