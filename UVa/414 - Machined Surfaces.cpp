#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[26];
	int rows;
	while (scanf("%d", &rows) && rows != 0) {
		vector<int> v;
		int res = 0;
		gets(s);
		for (int i = 0; i < rows; ++i) {
			int sp = 0;
			gets(s);
			int len = strlen(s);
			for (int b = 0; b < len; ++b)
				if (s[b] == ' ')
					++sp;
			v.push_back(sp);
		}
		sort(v.begin(), v.end());
		for (size_t i = 1; i < v.size(); i++)
			res += v[i] - v[0];
		printf("%d\n", res);
	}
	return 0;
}
