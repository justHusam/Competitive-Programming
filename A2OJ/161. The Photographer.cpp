#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int T;
	cin >> T;
	while (T-- != 0) {
		string s;
		cin >> s;
		if (next_permutation(s.begin(), s.end()))
			puts(s.c_str());
		else
			puts("DONE");
	}
	return 0;
}
