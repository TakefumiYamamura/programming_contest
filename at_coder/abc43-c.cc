#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long
using namespace std;

int main(){
	int n;
	int a[101];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ll ans = 1000*1000;
	for (int i = -100; i < 101; ++i)
	{
		ll tmp = 0;
		for (int j = 0; j < n; ++j)
		{
			tmp += (a[j] - i) * (a[j] - i);
		}
		ans = min(tmp, ans);
	}
	cout << ans << endl;

}
