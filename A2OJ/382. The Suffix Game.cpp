#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		char a[21], b[21];
		scanf("%s%s", a, b);
		string aa = a, bb = b;
		while (aa.size() > 1 && bb.size() > 1 && aa[aa.size() - 1] == bb[bb.size() - 1]) {
			aa.erase(aa.size() - 1);
			bb.erase(bb.size() - 1);
		}
		printf("Game #%d:\n", k++);
		printf("   The input words are %s and %s.\n", a, b);
		printf("   The words entered in the notebook are %s and %s.\n\n", aa.c_str(), bb.c_str());
	}
	return 0;
}
