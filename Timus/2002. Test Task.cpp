#include <bits/stdc++.h>
using namespace std;

char a[33], b[33], c[33];
map<string, string> hs;
set<string> in;

int main(int argc, char **argv) {
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", a);
		if (!strcmp(a, "register")) {
			scanf("%s%s", b, c);
			if (hs.find(b) == hs.end()) {
				hs[b] = c;
				puts("success: new user added");
			} else
				puts("fail: user already exists");
		} else if (!strcmp(a, "login")) {
			scanf("%s%s", b, c);
			map<string, string>::iterator it = hs.find(b);
			if (it == hs.end())
				puts("fail: no such user");
			else if (it->second != string(c))
				puts("fail: incorrect password");
			else if (in.find(b) != in.end())
				puts("fail: already logged in");
			else {
				in.insert(b);
				puts("success: user logged in");
			}
		} else {
			scanf("%s", b);
			if (hs.find(b) == hs.end())
				puts("fail: no such user");
			else if (in.find(b) == in.end())
				puts("fail: already logged out");
			else {
				in.erase(b);
				puts("success: user logged out");
			}
		}
	}
	return 0;
}
