#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
char s[22];

bool check() {
	int o = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == '(')
			++o;
		else if (o == 0)
			return false;
		else
			--o;
	return o == 0;
}

void calc(int at) {
	if (at == n) {
		if (check())
			puts(s);
		return;
	}
	s[at] = '(';
	calc(at + 1);
	s[at] = ')';
	calc(at + 1);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		n *= 2;
		s[n] = '\0';
		calc(0);
	}
	return 0;
}
