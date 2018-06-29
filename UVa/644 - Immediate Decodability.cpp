#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int caseN = 1;
	char s[15];
	while (scanf("%s", s) > 0) {
		vector<string> v;
		v.push_back(string(s));
		while (scanf("%s", s) && s[0] != '9')
			v.push_back(string(s));
		int n = v.size();
		bool res = true;
		for (int i = 0; i < n && res; ++i)
			for (int j = i + 1; j < n && res; ++j) {
				if (v[i].length() < v[j].length() && v[j].substr(0, v[i].length()) == v[i])
					res = false;
				if (v[j].length() < v[i].length() && v[i].substr(0, v[j].length()) == v[j])
					res = false;
			}
		printf("Set %d ", caseN++);
		if (res)
			puts("is immediately decodable");
		else
			puts("is not immediately decodable");
	}
	return 0;
}
