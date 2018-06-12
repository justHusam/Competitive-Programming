#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Hexspeak {

public:
	string decode(long long ciphertext) {
		string res = "";
		while (ciphertext > 0) {
			int m = ciphertext % 16;
			if (m >= 2 && m <= 9)
				return "Error!";
			if (m == 0)
				res += 'O';
			else if (m == 1)
				res += 'I';
			else
				res += m - 10 + 'A';
			ciphertext /= 16;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
