#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RhombusCount
{
public:
	int r, c, k;
	int ans;
	vector<vector<int > > map;
	vector<vector<int > > longtitude_count;
	RhombusCount();
	~RhombusCount();
	void exec();
};

RhombusCount::RhombusCount(){
	cin >> r >> c >> k;
	map.resize(r);
	longtitude_count.resize(r);
	for (int i = 0; i < r; ++i)
	{
		string tmp;
		cin >> tmp;
		map[i].resize(c);
		longtitude_count[i].resize(c);
		for (int j = 0; j < c; ++j)
		{
			longtitude_count[i][j] = 0;
			if(tmp[j] == 'x'){
				map[i][j] = 0;
			}else{
				map[i][j] = 1;
			}
		}
	}
}

RhombusCount::~RhombusCount(){}

void RhombusCount::exec(){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int count = 0;
			for (int m = 0; m < k; ++m)
			{
				if(i-m >= 0 && i+m < r && map[i-m][j] && map[i+m][j]){
					count++;
				}else{
					break;

				}
			}
			longtitude_count[i][j] = count;
		}
	}


	ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			bool flag = true;
			for (int m = 0; m < k; ++m)
			{
				if(j-m < 0 || j+m >= c || longtitude_count[i][j-m] < k - m || longtitude_count[i][j+m] < k - m){
					flag = false;
					break;
				}
			}
			if(flag){
				// cout << i << j << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	RhombusCount rc = RhombusCount();
	rc.exec();
}
