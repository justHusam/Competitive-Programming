#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int v[5];

char calc() {
	int cnt = 0, idx;
	for (int i = 0; i < 5; ++i)
		if (v[i] <= 127) {
			++cnt;
			idx = i;
		}
	if (cnt != 1)
		return '*';
	return idx + 'A';
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0)
		while (n-- != 0) {
			for (int i = 0; i < 5; ++i)
				scanf("%d", v + i);
			printf("%c\n", calc());
		}
	return 0;
}
