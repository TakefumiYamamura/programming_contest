#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> disk;
	unordered_map<int, int> um;
	for (int i = 1; i <= n; ++i)
	{
		disk.push_back(i);
		um[i] = i-1;
	}
	int before = 0;
	for (int i = 0; i < m; ++i)
	{
		int tmp;
		cin >> tmp;
		if(tmp == before) continue;
		int next_p = um[tmp];
		um[before] = next_p;
		disk[next_p] = before;
		um.erase(tmp);
		// um[tmp] = -1;
		before = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << disk[i] << endl;
	}
}
