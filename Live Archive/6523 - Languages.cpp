#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, string> hs;
char s[300];
vector<string> v;
map<string, string>::iterator it;

string calc(const string &s) {
	string res = "";
	for (size_t i = 0; i < s.size(); ++i)
		if (isalpha(s[i]))
			res += tolower(s[i]);
		else
			res += s[i];
	return res;
}

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	getchar();
	while (n-- != 0) {
		gets(s);
		v.clear();
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
			v.push_back(z);
		if (v.size() == 0)
			continue;
		for (size_t i = 1; i < v.size(); ++i)
			hs[calc(v[i])] = v[0];
	}
	gets(s);
	while (gets(s) > 0) {
		int n = strlen(s);
		string w = "";
		for (int i = 0; i < n; ++i) {
			if (s[i] == '\'' || s[i] == '-' || isalpha(s[i])) {
				if (isalpha(s[i]))
					s[i] = tolower(s[i]);
				w += s[i];
				continue;
			}
			if (w.empty())
				continue;
			it = hs.find(w);
			w = "";
			if (it != hs.end()) {
				puts(it->second.c_str());
				break;
			}
		}
		it = hs.find(w);
		if (it != hs.end())
			puts(it->second.c_str());
	}
	return 0;
}
