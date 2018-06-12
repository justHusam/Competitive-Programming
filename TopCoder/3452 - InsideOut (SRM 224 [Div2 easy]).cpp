#include <bits/stdc++.h>
using namespace std;

class InsideOut {

public:
	string unscramble(string line) {
		string res;
		int mid = line.length() / 2, ed = line.length() - 1;
		for (int i = mid - 1; i >= 0; --i)
			res += line[i];

		for (int i = ed; i >= mid; --i)
			res += line[i];
		return res;
	}
};

int main(int argc, char **argv) {
	return 0;
}
