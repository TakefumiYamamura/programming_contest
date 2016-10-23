#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

int main(){
	ll k, t;
	ll a[101];
	ll max = 0;
	cin >> k >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> a[i];
		if(a[i] > max){
			max = a[i];
		}
	}
	if(max > k/2){
		if(k % 2 == 0){
			cout << 2 * (max - k/2) - 1 << endl;
		}else{
			cout << 2 * (max - k/2 - 1) << endl; 
		}
	}else{
		cout << 0 << endl;
	}

	
}
