#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int r, s;
		scanf("%d%d", &r, &s);
		printf("%d\n", s * 2 - r);
	}
	return 0;
}
