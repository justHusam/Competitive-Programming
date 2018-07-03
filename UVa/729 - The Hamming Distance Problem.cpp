#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, h;
string s;

void calc(int idx, int ones) {
	if (idx == n && ones == h) {
		puts(s.c_str());
		return;
	}
	if (idx == n)
		return;
	s += '0';
	calc(idx + 1, ones);
	s.pop_back();
	if (ones == h)
		return;
	s += '1';
	calc(idx + 1, ones + 1);
	s.pop_back();
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &h);
		calc(0, 0);
		if (t != 0)
			puts("");
	}
	return 0;
}
