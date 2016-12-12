#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ull unsigned long long
#define ll long long
#define eps 10e-10

int main(){
	ull a, k;
	cin >> a >> k;
	ull ans = 0;
	if(k == 0){
		cout << 2*1000000000000 - a << endl;
		return 0;
	}
	while(a < 2*1000000000000){
		a += 1 + k*a;
		ans += 1;
	}
	cout << ans << endl;
}

