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

using namespace std;

class HashVI {
public:
	int operator() (const vector<int> &x) const {
		const int C = 997;
		int t = 0;
		for (int i = 0; i < x.size(); ++i)
		{
			t = t * C + x[i];
		}
		return t;
	}
};

class RedBlackTree
{
private:
	int n;
	vector<int> colors;
	unordered_map<vector<int>, bool, HashVI> mp;

public:
	RedBlackTree() {
		cin >> n;
		colors.resize(2*n);
		for (int i = 0; i < n; ++i)
		{
			cin >> colors[i];
			colors[i+n] = colors[i];
		}
	}

	bool check(vector<int>& a, vector<int>& b) {
		for (int i = 0; i < a.size(); ++i)
		{
			if(a[i] != b[i]) return false;
		}
		return true;
	}

	void solve() {
		int ans = 1;
		vector<int> cur = colors;
		mp[colors] = true;
		while(true) {
			vector<int> before = cur;
			for (int i = 0; i < n; ++i)
			{
				if(before[(i + 1) % n] == cur[i] && before[(i + n - 1) % n] == cur[i]) cur[i] = (cur[i] + 1) % 2;
			}
			if(check(before, cur)) {
				cout << ans << endl;
				return;
			}
			if(mp.find(cur) != mp.end()) {
				cout << -1 << endl;
				return;
			}
			mp[cur] = true;
			ans++;
		}
	}

	bool all_same(const vector<int>& array) {
		for (int i = 0; i < array.size(); ++i)
		{
			if(array[0] != array[i]) return false;
		}
		return true;
	}

	void solve2() {
		if(all_same(colors)) {
			cout << -1 << endl;
			return;
		}

		int len = 0;
		int i = 0;

		while(i < colors.size()) {
			int count = 0;
			for (int j = i; j < colors.size(); ++j)
			{
				if(colors[i] == colors[j]) {
					count++;
				} else {
					len = max(len, count);
					i = j;
					break;
				}
				if(j + 1 == colors.size() ) {
					len = max(len, count);
					i = j+1;
					break;
				} 
			}
		}
		cout << (len + 1) / 2 << endl;
	}
};

int main() {
	RedBlackTree rbt = RedBlackTree();
	rbt.solve2();
}
