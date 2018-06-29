#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[7];
	for (int caseN = 1; scanf("%s", &s) != EOF && s[0] != '*'; ++caseN)
		if (s[0] == 'H')
			printf("Case %d: Hajj-e-Akbar\n", caseN);
		else
			printf("Case %d: Hajj-e-Asghar\n", caseN);
	return 0;
}
