#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main(){
	ll n;
	cin >> n;

	ll depth  = 0;

	for (ll i = n; i > 0 ; i /= 2)
	{
		depth++;
	}
	ll x = 1;
	ll count = 0;
	// cout << depth << endl;

	if(depth % 2 == 0){
		while(x <= n){
			if(count % 2 == 0){
				x  = x * 2;
			} else {
				x = x * 2 + 1;
			}
			count ++;
		}
	} else {
		while(x <= n){
			if(count % 2 == 0){
				x  = x * 2 + 1;
			} else {
				x = x * 2;
			}
			count ++;
		}		
	}


	if(count % 2 == 0){
		cout << "Takahashi" << endl;
	}else{
		cout << "Aoki" << endl;
	}
}