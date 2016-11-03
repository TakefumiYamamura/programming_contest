#include <iostream>
#include <vector>
#define NMAX 100010
#define ll long long
#define MOD 1000000007
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n,  m;
    vector<int> tastes;
    cin >> n >> m;
    tastes.push_back(0);

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        tastes.push_back(tmp);
    }

    ll dp[NMAX];
    Fill(dp, 0);
    dp[0] = 1;
    ll imos = 1;
    int start = 0;
    bool check[NMAX];
    Fill(check, false);
    for (int i = 1; i <= n; ++i)
    {
        if(check[tastes[i]]){
            for (int j = start; j < i; ++j)
            {
                imos = (imos - dp[j] + MOD) % MOD;
                if(tastes[i] == tastes[j]){
                    imos = (imos + dp[j]) % MOD;
                    // その味がなくなるまでしゃくとりの左をすすめる
                    start = j + 1;
                    break;
                }
                check[tastes[j]] = false;
            }
        }
        check[tastes[i]] = true;

        dp[i] = imos % MOD;
        dp[i] %= MOD;
        imos += dp[i]; 
        imos %= MOD;
        cout << dp[i] << " imos " << imos << " "<< start  << " i "<< i << endl;
    }
    cout << dp[n] % MOD << endl;
}
