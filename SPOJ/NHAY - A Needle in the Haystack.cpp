#include <bits/stdc++.h>
using namespace std;

string str, ptr;
vector<int> P, res;

int main(int argc, char **argv) {
	int n;
	while (cin >> n) {
		cin >> ptr >> str;
		P.clear();
		P.resize(ptr.size(), 0);
		for (size_t i = 1, k = 0; i < ptr.size(); ++i) {
			while (k > 0 && ptr[k] != ptr[i])
				k = P[k - 1];
			if (ptr[k] == ptr[i])
				++k;
			P[i] = k;
		}
		res.clear();
		for (size_t i = 0, k = 0; i < str.size(); ++i) {
			while (k > 0 && ptr[k] != str[i])
				k = P[k - 1];
			if (ptr[k] == str[i])
				++k;
			if (k == ptr.size()) {
				res.push_back(i - ptr.size() + 1);
				k = P[k - 1];
			}
		}
		for (size_t i = 0; i < res.size(); ++i)
			printf("%d\n", res[i]);
		puts("");
	}
	return 0;
}
