#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
class YakinikuRestaurants
{
public:
	int n, m;
	vector<long long>a;
	vector<vector<long long> >b;
	vector<vector<long long> >imos;
	YakinikuRestaurants();
	~YakinikuRestaurants();
	void exec();
};

YakinikuRestaurants::YakinikuRestaurants(){
	cin >> n >> m;
	a.push_back(0);
	for (int i = 0; i < n-1; ++i)
	{
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 1; i < n; ++i)
	{
		a[i] += a[i-1];

	}

	b.resize(n);
	for (int i = 0; i < n; ++i)
	{
		b[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> b[i][j];
		}
	}

	imos.resize(m);
	for (int i = 0; i < m; ++i)
	{

		imos[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			if(j == 0){
				imos[i][j] = b[j][i];
			}else{
				imos[i][j] = max(imos[i][j-1], b[j][i]);

			}
		}
	}
}

YakinikuRestaurants::~YakinikuRestaurants(){}

void YakinikuRestaurants::exec(){
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		long long tmpAns = 0;
		for (int j = 0; j < m; ++j)
		{
			tmpAns += imos[j][i];
		}
		ans = max(ans, tmpAns - a[i]);
	}
	cout << ans << endl;
}

int main(){
	YakinikuRestaurants yr = YakinikuRestaurants();
	yr.exec();
}
