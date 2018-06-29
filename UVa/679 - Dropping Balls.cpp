#include <bits/stdc++.h>
using namespace std;

int calc(int dep, int ball) {
	int res = 1, lev = 1;
	while (lev++ < dep) {
		if ((ball & 1) == 1) {
			res *= 2;
			ball = ball / 2 + 1;
			continue;
		}
		res = res * 2 + 1;
		ball /= 2;
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int dep, ball;
		scanf("%d%d", &dep, &ball);
		printf("%d\n", calc(dep, ball));
	}
	return 0;
}
