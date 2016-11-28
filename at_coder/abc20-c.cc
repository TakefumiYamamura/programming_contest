#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define ll long long

const ll MAX = 1e9+7;

struct Point
{
	int x, y;
};

class GoingThrough
{
public:
	int h, w, t;
	Point start, goal;
	vector<vector<int > > s;
	GoingThrough();
	~GoingThrough();
	void exec();
	void binarySearch();
	int warshalFroid(int cost);
};

GoingThrough::GoingThrough(){
	cin >> h >> w >> t;
	s.resize(h);
	for (int i = 0; i < h; ++i)
	{
		s[i].resize(w);
		string tmp;
		cin >> tmp;
		for (int j = 0; j < w; ++j)
		{
			if(tmp[j] == 'S'){
				start.x = i;
				start.y = j;
				s[i][j] = 0;
			}else if(tmp[j] == 'G'){
				goal.x = i;
				goal.y = j;
				s[i][j] = 0;
			}else if(tmp[j] == '.'){
				s[i][j] = 1;
			}else if(tmp[j] == '#'){
				s[i][j] = 2;
			}
		}
	}
}

GoingThrough::~GoingThrough(){}

void GoingThrough::exec(){
	binarySearch();
	// cout << warshalFroid(3) << endl;
}

void GoingThrough::binarySearch(){
	int left = 0;
	int right = t;
	int mid =  (left + right) / 2;
	while(left + 1 < right){
		mid = (left + right) / 2;
		if(warshalFroid(mid) <= t){
			// cout << warshalFroid(mid) << " x " << mid << endl; 
			left = mid;
		}else{
			right = mid;
		}
	}
	cout << left << endl;
}

int GoingThrough::warshalFroid(int cost){
	int dp[10][10][10][10];
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			for (int k = 0; k < h; ++k)
			{
				for (int l = 0; l < w; ++l)
				{
					dp[i][j][k][l] = MAX;
				}
			}
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			int tmp;
			if(s[i][j] == 1){
				tmp = 1;
			}else if(s[i][j] == 2){
				tmp = cost;
			}else{
				tmp = 1;
			}
			// for (int k = i-1; k <= i+1; ++k)
			// {
			// 	for(int l = j-1; l <= j+1; ++l){
			int k,l;
			k = i-1; l = j;
			if(k >= 0 && k < h && l >= 0 && l < w) dp[k][l][i][j] = tmp;
			k = i+1; l = j;
			if(k >= 0 && k < h && l >= 0 && l < w) dp[k][l][i][j] = tmp;
			k = i; l = j-1;
			if(k >= 0 && k < h && l >= 0 && l < w) dp[k][l][i][j] = tmp;
			k = i; l = j+1;
			if(k >= 0 && k < h && l >= 0 && l < w) dp[k][l][i][j] = tmp;


			// }
		}
	}
	for (int k = 0; k < h*w ; ++k){
		for (int i = 0; i < h*w; ++i){
			for (int j = 0; j < h*w; ++j){
				dp[i/w][i%w][j/w][j%w] = min(dp[i/w][i%w][j/w][j%w], dp[i/w][i%w][k/w][k%w] + dp[k/w][k%w][j/w][j%w]);
 			}
 		}
	}
	return dp[start.x][start.y][goal.x][goal.y];
}

int main(){
	GoingThrough gt = GoingThrough();
	gt.exec();
}

