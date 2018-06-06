#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
char s[N];

int main(int argc, char **argv) {
	int t;
	scanf("%i", &t);
	while (t-- != 0) {
		scanf(" %s", s);
		int n = strlen(s), c = 0;
		pair<int, int> pos(0, 0);
		for (int i = 0; i < n; ++i)
			if (s[i] == 'U')
				++pos.second;
			else if (s[i] == 'R')
				++pos.first;
			else if (s[i] == 'D')
				--pos.second;
			else if (s[i] == 'L')
				--pos.first;
			else
				++c;
		printf("%i %i %i %i\n", pos.first - c, pos.second - c, pos.first + c, pos.second + c);
	}
	return 0;
}
