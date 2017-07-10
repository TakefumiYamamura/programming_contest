#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class CardEater
{
private:
	int n;
	vector<int> a;
	unordered_map<int, int> um;

public:
	CardEater() {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			um[a[i]]++;
		}
	}

	void exec() {
		int count = 0;
		int odd_count = 0;
		for(auto itr : um) {
			count++;
			if(itr.second % 2 == 0) {
				odd_count++;
			}
		}
		if(odd_count % 2 == 1) count--;
		cout << count << endl;
	}
	
};

int main() {
	CardEater ce = CardEater();
	ce.exec();
}
