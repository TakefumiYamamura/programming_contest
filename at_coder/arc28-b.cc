#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <set>
#include <climits>

#define ll long long

using namespace std;

class SpecialPrize
{
private:
	int n;
	int k;
	vector<int> x;
	unordered_map<int, int> um;
	set<int> st;
public:
	SpecialPrize() {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			x.push_back(tmp);
			um[tmp] = i+1;
		}
	}

	void exec() {
		for (int i = 0; i < n; ++i)
		{
			st.insert(x[i]);
			if(st.size() > k) {
				auto itr2 = st.end();
				itr2--;
				st.erase(itr2);
			}
			if(st.size() >= k) {
				auto itr = st.end();
				itr--;
				cout << um[*itr] << endl;
			}
		}
	}
};


int main() {
	SpecialPrize sp = SpecialPrize();
	sp.exec();
}
