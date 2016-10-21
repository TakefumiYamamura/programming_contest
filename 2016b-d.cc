#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long

using namespace std; 

ll a[100001];
ll sum = 0;
int n;

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sum += a[0] - 1;
	ll limit = 2;
	for (int i = 1; i < n; ++i)
	{
		ll tmp_limit = limit;
		if(a[i] == limit){
			limit++;
		}

		sum += a[i]/tmp_limit;
		if(a[i] % tmp_limit == 0){
			sum--;
		} 
	}
	cout << sum << endl;
}
