#include <iostream>
#define ll long long 
using namespace std;

const ll MOD = 1e9+7;

ll factorial[200003];
ll revfac[200003];

ll con(ll a, ll b){
    return factorial[a] * revfac[b] % MOD * revfac[a-b] % MOD; 
}

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


void set_factorial(ll n){
    factorial[0] = 1;
    revfac[0] = 1; 
    for (int i = 1; i <= n; ++i)
    {
        factorial[i] = factorial[i-1] * i % MOD;
        revfac[i] = pow(factorial[i], MOD - 2) % MOD;
    }
}

int main(){
    ll h, w, a, b;
    cin >> h >> w >> a >> b;

    set_factorial(h+w);
    ll ans = 0;
    for (int i = 0; i <= h-a-1; ++i)
    {
        ans += con(b+i-1, i) * con(w-b+h-i-2, w-b-1) % MOD;
    }
    cout << ans % MOD << endl;
}