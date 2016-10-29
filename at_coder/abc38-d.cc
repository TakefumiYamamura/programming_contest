#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

struct Present{
	int w, h;
	static bool Asc(const Present& x, const Present& y){
		if(x.w == y.w){
			return x.h > y.h;
		}else{
			return x.w > y.w;
		}
	}
};

int main(){
	int n;
	cin >> n;
	vector<Present> presents;
	int dp[1000001];
	for (int i = 0; i < n; ++i)
	{
		Present p;
		cin >> p.w >> p.h;
		presents.push_back(p);
	}

	sort(presents.begin(), presents.end(), Present::Asc);
	int k = 0;

	for (int i = 0; i < n-1; ++i)
	{
		if(presents[k].w == presents[k+1].w){
			remove(presents, k);
			k--;
		}
		k++;
	}

	dp[0] = 1;

	for (int i = 1; i < presents.length(); ++i)
	{
		if(presents[i].h > presents[i-1].h){
			dp[i] = dp[i-1] + 1;
		}
	}





}

