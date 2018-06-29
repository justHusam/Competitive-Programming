#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, string> hs;
char s[2222];

int main(int argc, char **argv) {
	hs[".-"] = "A";
	hs["-..."] = "B";
	hs["-.-."] = "C";
	hs["-.."] = "D";
	hs["."] = "E";
	hs["..-."] = "F";
	hs["--."] = "G";
	hs["...."] = "H";
	hs[".."] = "I";
	hs[".---"] = "J";
	hs["-.-"] = "K";
	hs[".-.."] = "L";
	hs["--"] = "M";
	hs["-."] = "N";
	hs["---"] = "O";
	hs[".--."] = "P";
	hs["--.-"] = "Q";
	hs[".-."] = "R";
	hs["..."] = "S";
	hs["-"] = "T";
	hs["..-"] = "U";
	hs["...-"] = "V";
	hs[".--"] = "W";
	hs["-..-"] = "X";
	hs["-.--"] = "Y";
	hs["--.."] = "Z";
	hs["-----"] = "0";
	hs[".----"] = "1";
	hs["..---"] = "2";
	hs["...--"] = "3";
	hs["....-"] = "4";
	hs["....."] = "5";
	hs["-...."] = "6";
	hs["--..."] = "7";
	hs["---.."] = "8";
	hs["----."] = "9";
	hs[".-.-.-"] = ".";
	hs["--..--"] = ",";
	hs["..--.."] = "?";
	hs[".----."] = "'";
	hs["-.-.--"] = "!";
	hs["-..-."] = "/";
	hs["-.--."] = "(";
	hs["-.--.-"] = ")";
	hs[".-..."] = "&";
	hs["---..."] = ":";
	hs["-.-.-."] = ";";
	hs["-...-"] = "=";
	hs[".-.-."] = "+";
	hs["-....-"] = "-";
	hs["..--.-"] = "_";
	hs[".-..-."] = "\"";
	hs[".--.-."] = "@";
	int t, cas = 1;
	scanf("%d", &t);
	gets(s);
	while (t-- != 0) {
		gets(s);
		string sol = "", w = "";
		int p = 0;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == ' ') {
				if (!w.empty()) {
					sol += hs[w];
					w = "";
				}
				if (++p == 2) {
					sol += " ";
					p = 0;
				}
			} else {
				p = 0;
				w += s[i];
			}
		}
		if (!w.empty())
			sol += hs[w];
		printf("Message #%d\n%s\n", cas++, sol.c_str());
		if (t != 0)
			puts("");
	}
	return 0;
}
