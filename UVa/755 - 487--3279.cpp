#include<bits/stdc++.h>
using namespace std;

char get(char c) {
	c = tolower(c);
	if (c == 'a' || c == 'b' || c == 'c')
		return '2';
	if (c == 'd' || c == 'e' || c == 'f')
		return '3';
	if (c == 'g' || c == 'h' || c == 'i')
		return '4';
	if (c == 'j' || c == 'k' || c == 'l')
		return '5';
	if (c == 'm' || c == 'n' || c == 'o')
		return '6';
	if (c == 'p' || c == 'r' || c == 's')
		return '7';
	if (c == 't' || c == 'u' || c == 'v')
		return '8';
	return '9';
}

char s[11111];

int main(int argc, char **argv) {
	int t;
	bool newLine = false;
	scanf("%d", &t);
	while (t-- != 0) {
		if (newLine)
			puts("");
		newLine = true;
		int n;
		scanf("%d", &n);
		map<string, int> hs;
		while (n-- != 0) {
			scanf("%s", s);
			string r = "";
			for (int i = 0; s[i]; ++i)
				if (isalpha(s[i]))
					r += get(s[i]);
				else if (isdigit(s[i]))
					r += s[i];
			r = r.substr(0, 3) + '-' + r.substr(3);
			++hs[r];
		}
		vector<pair<string, int> > res;
		map<string, int>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it)
			if (it->second != 1)
				res.push_back(make_pair(it->first, it->second));
		if (res.empty())
			puts("No duplicates.");
		else {
			for (size_t i = 0; i < res.size(); ++i)
				printf("%s %d\n", res[i].first.c_str(), res[i].second);
		}
	}
	return 0;
}
