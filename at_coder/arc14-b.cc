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

#define ll long long

using namespace std;

int main() {
	int n;
	unordered_set<string> us;
	cin >> n;
	string before = "";
	for (int i = 0; i < n; ++i)
	{
		string cur;
		cin >> cur;
		if(us.find(cur) != us.end()){
			if(i % 2 == 0) {
				cout << "LOSE" << endl;
			} else {
				cout << "WIN" << endl;
			} 
			return 0;
		}
		us.insert(cur);
		if(i == 0) {
			before = cur;
			continue;
		}
		if(before[before.length() - 1] != cur[0]) {
			if(i % 2 == 0) {
				cout << "LOSE" << endl;
			} else {
				cout << "WIN" << endl;
			} 
			return 0;
		}
		before = cur;
	}
	cout << "DRAW" << endl;
}