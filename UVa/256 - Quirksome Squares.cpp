#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	vector<string> res[10];
	res[2]= {"00", "01", "81"};
	res[4]= {"0000","0001","2025","3025","9801"};
	res[6]= {"000000", "000001" ,"088209", "494209" ,"998001"};
	res[8]= {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};
	int n;
	while (scanf("%d", &n) > 0) {
		for (size_t i = 0; i < res[n].size(); ++i)
			puts(res[n][i].c_str());
	}
	return 0;
}
