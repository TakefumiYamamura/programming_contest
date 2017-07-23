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
	string str;
	cin >> str;
	int count = 0;
	int ans = 0;
	if(str.size() == 1) {
		cout << 0 << endl; 
		return 0;
	}

	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] != str[str.size() - 1 - i]) {
			count++;
		}
	}
	if(count == 0) {
		if(str.size() % 2 == 0) {
			cout << 25 * str.size() << endl;
		} else {
			cout << 25 * (str.size() - 1)<< endl;
		}
		return 0;
	}
	if(count > 2){
		cout << 25 * str.size() << endl;
		return 0;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] == str[str.size() - 1 - i] || i == str.size() - 1 - i) {
			ans += 25;
		} else {
			ans += 24;
		}
	}
	cout << ans << endl;

}