#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ConsecutiveNumbers {
public:
	vector<int> missingNumber(vector<int> numbers) {
		vector<int> res;
		sort(numbers.begin(), numbers.end());
		bool can = true;
		for (size_t i = 1; i < numbers.size() && can; ++i)
			can &= numbers[i] - 1 == numbers[i - 1];
		if (can) {
			if (numbers[0] != 1)
				res.push_back(numbers[0] - 1);
			res.push_back(numbers.back() + 1);
			return res;
		}
		for (size_t i = 1; i < numbers.size(); ++i) {
			if (numbers[i] - 1 == numbers[i - 1])
				continue;
			if (numbers[i] - 2 != numbers[i - 1] || res.size()) {
				res.clear();
				break;
			}
			res.push_back(numbers[i] - 1);
		}
		return res;
	}
};