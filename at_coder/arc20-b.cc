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

int main() {
	int n;
	int c;
	cin >> n;
	cin >> c;
	unordered_map<int, int> um1;
	unordered_map<int, int> um2;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if(i % 2 == 0) {
			um1[tmp]++;
		} else {
			um2[tmp]++;
		}
	}

	int ans = INT_MAX / 2;

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if(i == j) continue;
			ans = min(ans, c * (n - um1[i] - um2[j]));
		}
	}
	cout << ans << endl;
}
