#include <bits/stdc++.h>
using namespace std;

int m, temp, cnt, res;
map<char, int> ava;
char s[1000009];

int main(int argc, char **argv) {
	while (scanf("%d\n", &m) && m != 0) {
		ava.clear();
		for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
			ava.insert(make_pair(i, 0));
		}
		gets(s);
		temp = cnt = res = 0;
		for (int i = 0, len = strlen(s), str = 0; i < len; i++) {
			if (cnt >= m) {
				if (ava[s[i]] == 0) {
					if (ava[s[str]] == 1) {
						cnt--;
					}
					ava[s[str]]--;
					if (temp > res)
						res = temp;
					i--;
					str++;
					temp--;
				} else {
					temp++;
					ava[s[i]]++;
				}
			} else {
				if (ava[s[i]] == 0) {
					cnt++;
				}
				temp++;
				ava[s[i]]++;
			}
		}
		if (temp > res)
			res = temp;
		printf("%d\n", res);
	}
	return 0;
}
