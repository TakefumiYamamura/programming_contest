#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int n;
	ll t[100100];
	ll a[100100];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> a[i];
	}

	for (int i = 1; i < n; ++i)
	 {
	 	if(t[i-1] > t[i] || a[i-1] > a[i]){
	 		ll tmp_mul = max( (t[i-1] - 1)/ t[i] + 1, (a[i-1] - 1) / a[i] + 1);
	 		t[i] *= tmp_mul;
	 		a[i] *= tmp_mul;
	 	}

	 }

	 cout << t[n-1] + a[n-1] << endl;

}
