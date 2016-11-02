#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define N_MAX 19
#define M_MAX 19
#define ll long long

struct chocho
{
	int to;
	int happiness;
};

int main(){
	int n, m, p, q, r;
	int x[N_MAX * M_MAX];
	int y[N_MAX * M_MAX];
	int z[N_MAX * M_MAX];
	vector<chocho> G[M_MAX];

	cin >> n >> m >> p >> q >> r;

	for (int i = 0; i < r; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		chocho tmp = {y, z};
		G[x].push_back(tmp);
	}

    ll ans = 0;
	for (int i = 0; i < 1 << n; ++i)
	{
		int count = 0;
		for (int j = 0; j < n; ++j)
		{
			if(i >> j & 1) count++;
		}
		if(count == p){
			vector<int> happy(m, 0);
			for (int j = 0; j < n; ++j)
			{
				if(i >> j & 1){
					for (int k = 0; k < G[j].size(); ++k)
					{
						happy[G[j][k].to] += G[j][k].happiness;
					}
				}
			}
			sort(happy.begin(), happy.end(), greater<int>());
			ll tmp = 0;
			for (int j = 0; j < q ; ++j)
			{
				tmp += happy[j];
			}
			ans = max(tmp, ans);
		}
	}

	cout << ans << endl;


}
