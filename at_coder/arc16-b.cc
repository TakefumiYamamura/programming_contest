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

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	vector<string> strs;
	for (int i = 0; i < n; ++i)
	{
		string str = "";
		for (int j = 0; j < 9; ++j)
		{
			char tmp;
			cin >> tmp;
			str += tmp;
		}
		strs.push_back(str);
	}
	strs.push_back(".........");
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if(strs[j][i] == 'x'){
				ans++;
			}else if(strs[j][i] == 'o') {
				ans++;
				while(strs[j+1][i] == 'o'){
					j++;
				}
			}
		}
	}

	cout << ans << endl;
}

