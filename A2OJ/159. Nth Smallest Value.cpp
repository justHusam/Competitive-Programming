#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int v[10];
		for (int i = 0; i < 10; ++i)
			scanf("%d", &v[i]);
		sort(v, v + 10);
		printf("%d\n", v[1]);
	}
	return 0;
}
