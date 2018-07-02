#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char s[10001];

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		map<string, int> hs;
		while (n-- != 0) {
			char s[50];
			int u;
			scanf("%s%d", s, &u);
			hs[s] = u;
		}
		getchar();
		while (m-- != 0) {
			int res = 0;
			while (gets(s) > 0) {
				if (strlen(s) == 1 && s[0] == '.')
					break;
				stringstream ss(s);
				string temp;
				while (ss >> temp)
					res += hs[temp];
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
