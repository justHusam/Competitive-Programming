#include <bits/stdc++.h>
using namespace std;

class DivideByZero {

public:

	int CountNumbers(vector<int> numbers) {
		bool need = true;
		while (need) {
			need = false;
			sort(numbers.begin(), numbers.end());
			for (int i = numbers.size() - 1; i >= 0; --i) {
				for (int j = i - 1; j >= 0; --j) {
					int c = numbers[i] / numbers[j];
					if (find(numbers.begin(), numbers.end(), c) == numbers.end()) {
						need = true;
						numbers.push_back(c);
					}
				}
			}
		}
		return numbers.size();
	}
};
