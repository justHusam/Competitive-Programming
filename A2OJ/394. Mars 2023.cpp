#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
//    freopen("a", "r", stdin);
	int n;
	scanf("%d", &n);
	while (n-- != 0) {
		int w, h;
		char ss[10];
		scanf("%d%d%s", &w, &h, ss);
		string s = ss;
		s = s.substr(0, s.length() - 1);
		int he = atoi(s.c_str());
		if (w == h - 100 && h >= 170 && he >= 90)
			puts("PASS");
		else
			puts("FAIL");
	}
	return 0;
}
