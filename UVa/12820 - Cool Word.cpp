#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

inline bool check(char *s) {
	map<char, int> cnt;
	set<char> st;
	for (int a = 0; s[a]; ++a)
		++cnt[s[a]], st.insert(s[a]);
	set<int> x;
	map<char, int>::iterator it;
	for (it = cnt.begin(); it != cnt.end(); ++it)
		x.insert(it->second);
	return x.size() > 1 && x.size() == st.size();
}

int main(int argc, char **argv) {
	int n, k = 1;
	while (scanf("%d", &n) > 0) {
		int res = 0;
		while (n--) {
			char s[33];
			scanf("%s", s);
			res += check(s);
		}
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
