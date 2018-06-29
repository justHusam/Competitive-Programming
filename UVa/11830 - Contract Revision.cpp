#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int d;
	string s;
	while (cin >> d >> s && d != 0) {
		string res = "";
		for (int i = 0; s[i]; ++i)
			if (s[i] - '0' != d)
				res += s[i];
		size_t idx = 0;
		while (idx < res.size() && res[idx] == '0')
			++idx;
		if (idx == res.size())
			puts("0");
		else {
			for (; idx < res.size(); ++idx)
				putchar(res[idx]);
			puts("");
		}
	}
	return 0;
}
