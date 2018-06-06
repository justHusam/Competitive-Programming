#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n) {
		vector<int> v;
		while (n-- != 0) {
			char s[100];
			scanf("%s", s);
			sort(s, s + strlen(s));
			v.push_back(atoi(s));
		}
		sort(v.begin(), v.end());
		printf("%d\n", v.back());
	}
	return 0;
}
