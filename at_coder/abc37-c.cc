#include <iostream>

using namespace std;
#define ll long long

int main(){
	int n, k;
	int a[10000010];
	ll s[10000010];
	s[0] = 0;
	ll sum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s[i] = a[i] + s[i-1];
	}
	for (int i = 0; i + k <= n ; ++i)
	{
		sum += s[i+k] - s[i];
	}
	cout << sum << endl;
}
