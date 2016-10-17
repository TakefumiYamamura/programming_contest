#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
#define MAX 1000001
using namespace std;

// int n;
// int a[MAX], b[1000000001];

// void merge_sort(int start, int finish){
// 	int mid = finish/2;
// 	int right[MAX];
// 	int left[MAX];
// 	if(start - mid == 0){
// 		return ;
// 	}
//     merge_sort(start, finish/2);
// 	merge_sort(finish/2 + 1, finish);
// 	for (int i = 1; i <= mid; ++i)
// 	{
// 		right[i] = a[i];
// 	}
// 	for (int i = 1; i <= finish - mid; ++i)
// 	{
// 		left[i] = a[mid + i];
// 	}
// 	int r = 1;
// 	int l = 1;
// 	for (int i = 1; i <= finish - start; ++i)
// 	{
// 		if(right[r] > left[l]){
// 			a[start+i] = right[r];
// 			r++;
// 		}else{
// 			a[start+i] = left[l];
// 		}
// 	}
// }

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
		// cin >> a[i];
		// b[a[i]] = i;	
		Num num;
		cin >> num.value;
		num.index = i;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), Num::Asc);
	// merge_sort(1,n);
	for (int i = 0; i < n; ++i)
	{
		cout << nums[i].index << endl;
	}

}
