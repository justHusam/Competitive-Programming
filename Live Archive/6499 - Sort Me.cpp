#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, k = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		char in[55];
		scanf("%s", in);
		map<char, char> hs;
		for (char i = 'A'; i <= 'Z'; ++i)
			hs[in[i - 'A']] = i;
		vector<pair<string, string> > v;
		for (int i = 0; i < n; ++i) {
			char s[55];
			string temp;
			scanf("%s", s);
			for (int j = 0; s[j]; ++j)
				temp += hs[s[j]];
			v.push_back(make_pair(temp, s));
		}
		sort(v.begin(), v.end());
		printf("year %d\n", k++);
		for (int i = 0; i < n; ++i)
			puts(v[i].second.c_str());
	}
	return 0;
}
