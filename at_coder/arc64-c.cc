#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


class BoxesAndCandies
{
public:
	long long n, x;
	long long sum;
	// int dp[100001][2];
	vector<long long> a;
	BoxesAndCandies();
	~BoxesAndCandies();
	void exec();
};

BoxesAndCandies::BoxesAndCandies(){
	cin >> n >> x;
	a.push_back(0);
	for (long long i = 0; i < n; ++i)
	{
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	a.push_back(0);
}

BoxesAndCandies::~BoxesAndCandies(){}

void BoxesAndCandies::exec(){
	sum = 0;
	vector<long long> b = a;
	for (int i = 1; i <= n; ++i)
	{
		if(a[i-1] + a[i] > x){
			sum += a[i] + a[i-1] - x;
			a[i] -= a[i] + a[i-1] - x;
		}
	}
	long long r_sum = 0;

	for (int i = 1; i <= n; ++i)
	{
		if(b[i+1] + b[i] > x){
			r_sum += b[i] + b[i+1] - x;
			b[i] -= b[i] + b[i+1] - x;
		}
	}
	cout << min(sum, r_sum) << endl;
}

int main(){
	BoxesAndCandies bac = BoxesAndCandies();
	bac.exec();
}
