#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char s[500];
	int T;
	scanf("%d", &T);
	gets(s);
	while (T-- != 0) {
		gets(s);
		stringstream ss(s);
		vector<int> v;
		int temp;
		while (!ss.eof())
			if (ss >> temp)
				v.push_back(temp);
		int mx = 0;
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t j = i + 1; j < v.size(); ++j)
				mx = max(mx, __gcd(v[i], v[j]));
		printf("%d\n", mx);
	}
	return 0;
}
