#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		char in[50];
		scanf("%s", in);
		string s = in;
		int n = s.length();
		set<string> st;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < n; ++j) {
				if (j + i > n)
					break;
				st.insert(s.substr(j, i));
			}
		bool res = true;
		for (set<string>::iterator it = st.begin(); res && it != st.end(); ++it) {
			string s = *it;
			reverse(s.begin(), s.end());
			res &= st.find(s) != st.end();
		}
		if (res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
