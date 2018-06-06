#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[222];
		scanf("%s", s);
		int n = strlen(s);
		sort(s, s + n);
		do
			puts(s);
		while (next_permutation(s, s + n));
	}
	return 0;
}
