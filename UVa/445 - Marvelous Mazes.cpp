#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {

		for (size_t i = 0; i < s.length(); ++i)
			if (s[i] == '!')
				puts("");
			else {
				int toPrint = 0, j;
				for (j = i; s[j] >= '0' && s[j] <= '9'; ++j)
					toPrint += atoi((s.substr(j, 1)).c_str());
				i = j;
				if (s[i] == 'j')
					for (int c = 1; c <= toPrint; c++)
						printf(" ");
				else
					for (int c = 1; c <= toPrint; c++)
						printf("%c", s[i]);
			}
		puts("");
	}
	return 0;
}
