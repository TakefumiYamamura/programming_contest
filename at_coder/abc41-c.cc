#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
#define MAX 1000001
using namespace std;


struct Num{
	ll value, index;
	static bool Asc(const Num& x, const Num& y){ return x.value > y.value ;}
};

int main(){
	ll n;
	cin >> n;
	vector<Num> nums;
	for (int i = 1; i <= n; ++i)
	{
		Num num;
		cin >> num.value;
		num.index = i;
		nums.push_back(num);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << nums[i].index << " " << nums[i].value<< endl;
	}

	sort(nums.begin(), nums.end(), Num::Asc);
	for (int i = 0; i < n; ++i)
	{
		cout << nums[i].index << " " << nums[i].value<< endl;
	}

}
