#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

using namespace std;

class Difficulty
{
private:
    ll n;
    vector<ll> d;
    unordered_map<ll, ll> hash;
    vector<vector<ll> > dp;

public:
    Difficulty() {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            ll tmp;
            cin >> tmp;
            d.push_back(tmp);
        }
        dp = vector<vector<ll> >(n, vector<ll>(4, 0) );
    }

    void exec() {
        sort(d.begin(), d.end());
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                int idx = lower_bound(d.begin(), d.end(), 2 * d[i]) - d.begin();
                if(idx == n) continue;
                dp[idx][j+1] += dp[i][j];
                dp[idx][j+1] %= MOD;
            }

            for (int i = 0; i + 1 < n; ++i)
            {
                dp[i+1][j+1] += dp[i][j+1];
                dp[i+1][j+1] %= MOD;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += dp[i][3];
            ans %= MOD;
        }
        cout << ans << endl;
    }

};

int main() {
    Difficulty d = Difficulty();
    d.exec();
}
