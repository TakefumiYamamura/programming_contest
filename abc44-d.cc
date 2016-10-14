#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long
using namespace std;

ll compute(ll b, ll n){
	if(n<b){
		return n;
	}else{
		return  compute(b, n/b) + n%b;
	}
}

int main(){
	ll n, s;
	ll b = 2;
	ll ans = -1;
	cin >> n;
	cin >> s;
	if(n == s){
		cout << n+1 << endl;
		return 0;
	}
	while(b*b <= n){
		if(compute(b, n) == s){
			cout << b << endl;
			return 0;
		} 
		b++;
	}
	// そうじゃないときは|n-s|の最大公約数で|n-s|をわったものにプラス１がB
	ll ab = abs(n-s);
	ll sq = sqrt(ab);

	bool flag = false;
	b = 1000000000005;
	for (ll p = 1; p < sqrt(n); ++p)
	{
		if(ab % p == 0 ){
			if(ab/p + 1 >= sqrt(n) ) {
				if(compute(ab/p+1, n) == s){
					b = min(ab/p + 1, b);
			        flag = true;
				}
			}
		}
	}
	if(flag){
		cout << b << endl;
		return 0;
	}

	cout << -1 << endl;
	return 0;
}
