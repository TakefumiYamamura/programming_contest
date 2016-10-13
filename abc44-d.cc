#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#define ll long long
using namespace std;

ll compute(ll b, ll n){
	if(n<b){
		return n;
	}else{
		return  compute(b, n/b + n%b);
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
	while(b*b < n){
		if(compute(b, n) == s){
			cout << b << endl;
			return 0;
		} 
		b++;
	}
	// そうじゃないときは|n-s|の最大公約数で|n-s|をわったものにプラス１がB
	

	cout << -1 << endl;
	return 0;
}
