#include <iostream>
#include <algorithm>
#include <vector>
#define ull unsigned long long

using namespace std;

int main(){
	int n, m;
	int edges[17][17] = {0};
	ull dp[(1<<16)+1] = {0};//Don't forget initialize.
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		edges[y-1][x-1] = 1;
	}
	dp[0] = (ull)1;

	for (int bit = 0; bit < (1 << n); ++bit)
	{
		for (int j = 0; j < n; ++j)
		{
			if((bit >> j & 1) != 1){
				bool check = true;
				for (int k = 0; k < n; ++k)
				{
					if((bit >> k & 1) != 1 && edges[k][j] == 1 ){
						check = false;
						break;
					}
				}
				if(check){
					dp[bit|(1<<j)] += dp[bit];
				}
			}
		}
	}
	cout << dp[(1<<n)-1] << endl;

}
