#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char in[100];

int main(int argc, char **argv) {
	while (scanf("%s", in) > 0) {
		string s = string(in);
		int n = s.length();
		set<string> st;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i + j > n)
					break;
				string x = s.substr(j, i);
				string y = x;
				reverse(y.begin(), y.end());
				if (x == y)
					st.insert(x);
			}
		printf("The string '%s' contains %d palindromes.\n", in, st.size());
	}
	return 0;
}
