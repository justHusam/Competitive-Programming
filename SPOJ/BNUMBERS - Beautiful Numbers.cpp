#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int k, v[5];

void calc(int i) {
	if (i == k) {
		for (int j = 0; j < k; ++j)
			printf("%d", v[j]);
		puts("");
		return;
	}
	for (int j = 1; j <= 3; ++j) {
		v[i] = j;
		calc(i + 1);
	}
}

int main(int argc, char **argv) {
	while (scanf("%d", &k) > 0) {
		calc(0);
		puts("");
	}
	return 0;
}
