#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%i", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		cin.ignore();
		string s;
		getline(cin, s);
		size_t i;
		bool ok = true;
		for (i = 0; i < s.length() && ok; i++)
			if (s[i] != '#' && s[i] != ' ')
				ok = false;
		if (!ok) {
			string res = "", temp = "";
			size_t b = i - 1;
			do {
				temp += s[b++];
			} while (b < s.length() && isalpha(s[b]));
			if (b < s.length())
				res = s.substr(++b, s.length() - b) + " ";
			res += temp;
			if (i - 1 > 0)
				res += " " + s.substr(0, i - 2);
			puts(res.c_str());
		} else
			puts(s.c_str());
	}
	return 0;
}
