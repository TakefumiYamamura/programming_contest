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
	unordered_set<int> us;
	vector<int> a;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		while(us.find(a[i]) != us.end()){
			us.erase(a[j]);
			j++;
		} 
		us.insert(a[i]);
		ans = max(ans, (int)us.size());		
	}
	cout << ans << endl;

}
