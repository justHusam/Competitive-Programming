#include <bits/stdc++.h>
using namespace std;

class Sortness {

public:
	double getSortness(vector<int> a) {
		int res = 0;
		for (size_t i = 0; i < a.size(); i++) {
			for (int j = i; j >= 0; j--)
				if (a[j] > a[i])
					res++;
			for (size_t j = i; j < a.size(); j++)
				if (a[j] < a[i])
					res++;
		}
		return (double) res / a.size();
	}
};
