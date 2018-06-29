#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int goL(int x, int y) {
	int res = 0;
	while (x != y) {
		--x;
		if (x == -1)
			x = 99;
		++res;
	}
	return res;
}

int goR(int x, int y) {
	int res = 0;
	while (x != y) {
		++x;
		if (x == 100)
			x = 0;
		++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int x, y;
	while (scanf("%d%d", &x, &y) > 0 && x != -1)
		printf("%d\n", min(goL(x, y), goR(x, y)));
	return 0;
}
