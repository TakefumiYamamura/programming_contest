#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Num
{
	int val;
	int index;
	static bool ValDesc(Num& a, Num& b){
		return a.val < b.val;
	}
	static bool IndDesc(Num& a, Num& b){
		return a.index < b.index;
	}
};


int main(){
	int n;
	vector<Num> nums;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		Num n;
		cin >> n.val;
		n.index = i;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end(), Num::ValDesc);

	int count = 0;
	int back;
	back = nums[0].val;
	nums[0].val = 0;
	for (int i = 1; i < n; ++i)
	{
		if(back != nums[i].val){
			count++;
		}
		back = nums[i].val;
		nums[i].val = count;
	}
	sort(nums.begin(), nums.end(), Num::IndDesc);

	for (int i = 0; i < n; ++i)
	{
		cout << nums[i].val << endl;
	}

	return 0;

}
