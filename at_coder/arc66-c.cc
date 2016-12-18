#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

#define MOD 1000000007

class LiningUp
{
public:
	int n;
	vector<int> a;

	LiningUp(){
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int  tmp;
			cin >> tmp;
			a.push_back(tmp);

		}
	}

	ll pow(ll num, ll e){
	    ll tmp = 1;
	    while(e > 0){
	        if( e & 1ll){
	            tmp = tmp * num % MOD;
	        }
	        num = num * num % MOD;
	        e >>= 1; 
	    }
	    return tmp % MOD;
	}

	void exec(){
		vector<ll> check;
		check.resize(n+1);
		for (int i = 0; i < n; ++i)
		 {
		 	check[i] = 0;
		 }
		if(n % 2 == 0){
			for (int i = 0; i < n; ++i)
			{
				// cout << i << " " << a[i] << endl;

				if(a[i] % 2 == 0 || a[i] >= n){
					cout << "0" << endl;
					return;
				}else{
					check[a[i]]++;
					if(check[a[i]] > 2){
						cout << "0" << endl;
						return;
					}
				}
				// cout << i << " " << a[i] << endl;
			}
		} else {
			for (int i = 0; i < n; ++i)
			{
				if(a[i] % 2 == 1 || a[i] >= n){
					cout << "0" << endl;
					return;
				}else{
					check[a[i]]++;
					if(a[i] == 0 && check[a[i]] == 2){
						cout << "0" << endl;
						return;
					}
					if(check[a[i]] > 2){
						cout << "0" << endl;
						return;
					}
				}
			}

		}

		cout << pow(2, n/2) << endl;

	}
};

int main(){
	LiningUp lu = LiningUp();
	lu.exec();
}
