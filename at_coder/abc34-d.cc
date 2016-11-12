#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct water
{
	double w;
	double p;
};

//決め打ち二分木探索
int main(){
	int k, n;
	vector<water> water_array;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		double w, p;
		cin >> w >> p;
		water tmp = {w, p};
		water_array.push_back(tmp);
	}

	double ok = 0.0;
	double ng = 100.0;
	double middle;

	while( (ng - ok) > 1e-12 )
	{
		middle = (ok + ng) / 2.0;
		vector<double> greedy;
		for (int i = 0; i < water_array.size(); ++i)
		{
			greedy.push_back(water_array[i].w * (water_array[i].p - middle)/ 100.0);
		}

		sort(greedy.begin(), greedy.end(), greater<double>() );


		double sum = 0;

		for (int i = 0; i < k; ++i)
		{
			sum += greedy[i];
		}
		// cout << endl;

		if(sum >= 0){
			ok = middle;
		}else{
			ng = middle;
		}
	}

	printf("%.10f\n", middle);
}
