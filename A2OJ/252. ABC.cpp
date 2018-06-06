#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int v[3];

inline void add(int a, int b, int c) {
	printf("%d", v[a]);
	printf(" %d", v[b]);
	printf(" %d\n", v[c]);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < 3; ++i)
			scanf("%d", v + i);
		sort(v, v + 3);
		char s[10];
		scanf("%s", s);
		if (strcmp(s, "ABC") == 0)
			add(0, 1, 2);
		if (strcmp(s, "ACB") == 0)
			add(0, 2, 1);
		if (strcmp(s, "BAC") == 0)
			add(1, 0, 2);
		if (strcmp(s, "BCA") == 0)
			add(1, 2, 0);
		if (strcmp(s, "CAB") == 0)
			add(2, 0, 1);
		if (strcmp(s, "CBA") == 0)
			add(2, 1, 0);
	}
	return 0;
}
