#include <bits/stdc++.h>
using namespace std;

int sH, sM, dH, dM, eH, eM;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &sH, &sM, &dH, &dM);
		eM = sM + dM;
		eH = sH + dH;
		if (eM >= 60) {
			eM %= 60;
			++eH;
		}
		puts("------+---------");
		puts(" time | elapsed");
		puts("------+---------");
		printf("%2d:XX | XX", sH++);
		int at = 0;
		if (sM != 0) {
			printf(" - %d", sM);
			at -= sM;
		}
		puts("");
		int need = eH - sH + 1;
		while (need-- > 0) {
			if (sH == 13)
				sH = 1;
			at += 60;
			printf("%2d:XX | XX + %d\n", sH++, at);
		}
	}
	return 0;
}
