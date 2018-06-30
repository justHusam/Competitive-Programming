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
		int n;
		scanf("%d", &n);
		bool can = false;
		for (int i = 0; i * i <= n && !can; ++i)
			for (int j = i; j * j <= n && !can; ++j) {
				int need = n - (i * i + j * j);
				if (need < 0)
					break;
				int m = sqrt(need);
				if (m * m == need) {
					if (m <= i)
						printf("%d %d %d\n", m, i, j);
					else if (i >= m && j <= m)
						printf("%d %d %d\n", i, m, j);
					else
						printf("%d %d %d\n", i, j, m);
					can = true;
				}
			}
		if (!can)
			puts("-1");
	}
	return 0;
}