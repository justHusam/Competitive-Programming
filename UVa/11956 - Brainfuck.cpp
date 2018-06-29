#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
char s[N];
int arr[100];

string calc(int x) {
	string res = "";
	for (int it = 0; it < 2; ++it) {
		int m = x % 16;
		x /= 16;
		if (m < 10)
			res += char(m + '0');
		else {
			m -= 10;
			res += char(m + 'A');
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		memset(arr, 0, sizeof arr);
		scanf("%s", s);
		int at = 0, n = strlen(s);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '.')
				continue;
			if (s[i] == '+') {
				++arr[at];
				if (arr[at] > 255)
					arr[at] = 0;
				continue;
			}
			if (s[i] == '-') {
				--arr[at];
				if (arr[at] < 0)
					arr[at] = 255;
				continue;
			}
			if (s[i] == '>') {
				++at;
				if (at > 99)
					at = 0;
				continue;
			}
			if (s[i] == '<') {
				--at;
				if (at < 0)
					at = 99;
			}
		}
		printf("Case %d:", cas++);
		for (int i = 0; i < 100; ++i) {
			string x = calc(arr[i]);
			printf(" %s", x.c_str());
		}
		puts("");
	}
	return 0;
}
