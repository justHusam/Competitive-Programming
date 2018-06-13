#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[111];
pair<int, int> P, N;

void calc() {
	int at = 1, x = 0, y = 0;
	while (isdigit(s[at]))
		x = x * 10 + (s[at++] - '0');
	++at;
	while (s[at])
		y = y * 10 + (s[at++] - '0');
	if (s[0] == '-') {
		N.first += x;
		N.second += y;
	} else {
		P.first += x;
		P.second += y;
	}
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && strcmp(s, "###")) {
		P = N = make_pair(0, 0);
		do {
			calc();
		} while (scanf("%s", s) && strcmp(s, "$$$") && strcmp(s, "###"));
		P.first += P.second / 60;
		P.second %= 60;
		N.first += N.second / 60;
		N.second %= 60;
		P.first -= N.first;
		if (N.second <= P.second)
			P.second -= N.second;
		else {
			N.second -= P.second;
			--P.first;
			P.second = 60 - N.second;
		}
		printf("%d:%02d\n", P.first, P.second);
	}
	return 0;
}
