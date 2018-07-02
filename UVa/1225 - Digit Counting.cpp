#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;


int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int freq[10] = { }, n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			for (int j = i; j != 0; j /= 10)
				++freq[j % 10];
		for (int i = 0; i < 10; ++i)
			printf("%s%d", i ? " " : "", freq[i]);
		puts("");
	}
	return 0;
}
