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
	int k;
	cin >> n >> k;
	vector<int> a = vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int ans = 0;
	int i = 0;
	int j = 0;

	while(j < n) {
		if(a[j-1] < a[j]) {
			j++;
		} else {
			if(j - i >= k) {
				ans += j - i + 1 - k ;
			}
			// cout << i << " " << j << endl;
			i = j;
			j++;
		}
	}
	if(a[n-2] < a[n-1] && n - i >= k) {
		ans += n - i + 1 - k;
	}

	cout << ans << endl;
}
