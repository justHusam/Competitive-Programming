#include <bits/stdc++.h>
using namespace std;

bool check(char ch) {
	ch = tolower(ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		string res = "";
		for (size_t i = 0; i < s.length(); ++i) {
			string temp = "";
			if (isalpha(s[i])) {
				while (isalpha(s[i]))
					temp += s[i++];
				if (check(temp[0]))
					res += temp + "ay";
				else
					res += temp.substr(1, temp.length() - 1) + temp[0] + "ay";
				--i;
			} else
				res += s[i];
		}
		cout << res << endl;
	}
	return 0;
}
