#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e6 + 9;
char s[N];
int arr[26];

int main(int argc, char **argv) {
	string s[] = { "ABCDE", "FGHIJ", "KLMNO", "PQRST", "UVWXY", "Z" };
	for (int i = 0; i < 6; ++i)
		for (size_t j = 0; j < s[i].length(); ++j)
			arr[s[i][j] - 'A'] = i + j + 2;
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int res = 0;
		for (int i = 0; s[i]; ++i)
			res += arr[s[i] - 'A'];
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
