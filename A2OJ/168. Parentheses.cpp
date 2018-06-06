#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
string s;

bool check() {
	int cnt = 0;
	for (int a = 0; a < n; ++a)
		if (s[a] == '(')
			++cnt;
		else if (cnt)
			--cnt;
		else
			return 0;
	return cnt == 0;
}

void calc(int with) {
	if (with == n) {
		if (check())
			puts(s.c_str());
		return;
	}
	s += '(';
	calc(with + 1);
	s.erase(s.length() - 1);
	s += ')';
	calc(with + 1);
	s.erase(s.length() - 1);
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	n <<= 1;
	calc(0);
	return 0;
}
