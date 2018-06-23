#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, const string &m = "") {
	string r = s;
	reverse(r.begin(), r.end());
	if (m != "")
		return r == m;
	return r == s;
}

bool isMirrored(const string &s) {
	string temp = "";
	for (size_t i = 0; i < s.length(); ++i)
		switch (s[i]) {
		case 'A':
			temp += 'A';
			break;
		case 'E':
			temp += '3';
			break;
		case 'H':
			temp += 'H';
			break;
		case 'I':
			temp += 'I';
			break;
		case 'J':
			temp += 'L';
			break;
		case 'L':
			temp += 'J';
			break;
		case 'M':
			temp += 'M';
			break;
		case 'O':
			temp += 'O';
			break;
		case 'S':
			temp += '2';
			break;
		case 'T':
			temp += 'T';
			break;
		case 'U':
			temp += 'U';
			break;
		case 'V':
			temp += 'V';
			break;
		case 'W':
			temp += 'W';
			break;
		case 'X':
			temp += 'X';
			break;
		case 'Y':
			temp += 'Y';
			break;
		case 'Z':
			temp += '5';
			break;
		case '1':
			temp += '1';
			break;
		case '2':
			temp += 'S';
			break;
		case '3':
			temp += 'E';
			break;
		case '5':
			temp += 'Z';
			break;
		case '8':
			temp += '8';
			break;
		}
	if (s.length() != temp.length())
		return false;
	if (isPalindrome(temp, s))
		return true;
	return false;
}

int main(int argc, char **argv) {
	string s;
	while (cin >> s) {
		if (!isPalindrome(s) && !isMirrored(s))
			cout << s << " -- is not a palindrome.\n" << endl;
		else if (isPalindrome(s) && !isMirrored(s))
			cout << s << " -- is a regular palindrome.\n" << endl;
		else if (!isPalindrome(s) && isMirrored(s))
			cout << s << " -- is a mirrored string.\n" << endl;
		else if (isPalindrome(s) && isMirrored(s))
			cout << s << " -- is a mirrored palindrome.\n" << endl;
	}
	return 0;
}
