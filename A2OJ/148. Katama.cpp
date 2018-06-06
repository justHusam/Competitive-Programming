#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s) && s != "***") {
		vector<int> v;
		for (size_t i = 0; i < s.size(); ++i)
			if (isdigit(s[i]))
				v.push_back(s[i] - '0');
		reverse(v.begin(), v.end());
		for (size_t i = 0; i < s.size(); ++i)
			printf("%s%d", i ? " " : "", v[i]);
		puts("");
	}
	return 0;
}
