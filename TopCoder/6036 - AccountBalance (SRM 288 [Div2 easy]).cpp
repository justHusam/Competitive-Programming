#include <bits/stdc++.h>
using namespace std;

class AccountBalance {

public:
	int processTransactions(int startingBalance, vector<string> transactions) {
		char type;
		int amount;
		for (int i = 0; i < transactions.size(); ++i) {
			stringstream ss(transactions[i]);
			ss >> type;
			ss >> amount;
			if (type == 'C')
				startingBalance += amount;
			else
				startingBalance -= amount;
		}
		return startingBalance;
	}
};
