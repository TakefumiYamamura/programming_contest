#include <iostream>
#include <string>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

const int mod = 1e9 + 7;
int dp[101010][2]; // pos, less

int main() {
    string A;
    cin >> A;
    int n = A.length();

    dp[0][0] = 1;
    rep (i, n) rep (j, 2) {
        int lim = j ? 9 : A[i] - '0';
        rep (d, lim + 1) {
            (dp[i + 1][j || d < lim] += dp[i][j]) %= mod;
        }
    }

    int ans = 0;
    rep (j, 2) (ans += dp[n][j]) %= mod;
    cout << ans << endl;
    return 0;
}
