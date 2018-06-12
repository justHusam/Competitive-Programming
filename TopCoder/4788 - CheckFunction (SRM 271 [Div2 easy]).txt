#include <bits/stdc++.h>
using namespace std;

class CheckFunction {

public:
	int newFunction(string code) {
		int res = 0;
		for (size_t i = 0; i < code.length(); ++i) {
			switch (code[i]) {
			case '0':
			case '6':
			case '9':
				res += 6;
				break;
			case '1':
				res += 2;
				break;
			case '2':
			case '3':
			case '5':
				res += 5;
				break;
			case '4':
				res += 4;
				break;
			case '7':
				res += 3;
				break;
			case '8':
				res += 7;
				break;
			}
		}
		return res;
	}
};
