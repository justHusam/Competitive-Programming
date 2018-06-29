#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[105];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	gets(s);
	while (T-- != 0) {
		gets(s);
		map<char, int> hs;
		for (int i = 0; s[i]; ++i)
			if (s[i] != ' ')
				++hs[s[i]];
		map<char, int>::iterator it;
		int res = 0;
		priority_queue<int> qu, v;
		for (int i = 1; i <= 6; ++i)
			for (int j = 1; j <= 6; ++j)
				qu.push(-(i + j));
		for (it = hs.begin(); it != hs.end(); ++it)
			v.push(it->second);
		while (!v.empty()) {
			int t = v.top();
			v.pop();
			int m = qu.top() * -1;
			qu.pop();
			res += m * t;
		}
		printf("%d\n", res);
	}
	return 0;
}
