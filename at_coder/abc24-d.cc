#include <iostream>
#include <algorithm>
using namespace std;
 
#define ll long long
 
const ll MOD = 1000000007;
 
class Num {
	ll value;
public:
	ll operator + (Num obj) {
		return (this->value + obj.value) % MOD;
	}
 
	ll operator - (Num obj) {
		return (this->value - obj.value + MOD) % MOD;
	}
 
	ll operator * (Num obj) {
		return (this->value * obj.value) % MOD;
	}
	Num(ll value) { this->value = value; }
};
 
ll pow(ll a, ll e){
    ll tmp = 1;
    while(e > 0){
        if( e & 1ll){
            tmp = tmp * a % MOD ;
        }
        a = a * a % MOD;
        e >>= 1; 
    }
    return tmp;
}
 
ll rev(ll n){
	return pow(n, MOD - 2) % MOD;
}
 
int main(){
	ll s, t, u;
	cin >> s >> t >> u;
	Num a(s), b(t), c(u);
 
	ll x, y;
	x = c * (b - a);
	x *= rev(Num(a * b) - c * ((b - a)));
	x %= MOD;
	y = b * (c-a);
	y *= rev(Num(a * c) - b * ((c - a)));
	y %= MOD;
 
	cout << x << " " << y << endl;
}