#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[123456];
char r1[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\' };
char r2[] = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'' };
char r3[] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' };

int get(char c) {
	for (int i = 0; i < 12; ++i)
		if (c == r1[i])
			return r1[i - 2];
	for (int i = 0; i < 11; ++i)
		if (c == r2[i])
			return r2[i - 2];
	for (int i = 0; i < 10; ++i)
		if (c == r3[i])
			return r3[i - 2];
	if (c == '{')
		return 'o';
	if (c == '}')
		return 'p';
	if (c == '|')
		return '[';
	if (c == ':')
		return 'k';
	if (c == '\"')
		return 'l';
	if (c == '<')
		return 'n';
	if (c == '>')
		return 'm';
	if (c == '?')
		return ',';
	return c;
}

int main(int argc, char **argv) {
	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		printf("%c", get(tolower(s[i])));
	puts("");
	return 0;
}
