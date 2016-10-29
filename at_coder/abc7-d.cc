#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll digDP(ll n){
	ll dp[20][2][2];
	ll size = 0;
	string s = to_string(n);
	size = s.size();
	//dp[i][j][k] 
	//i桁目まで確定,j:=禁止されている値かどうかのフラグ,k:= n未満が確定しているかどうかのフラグ
	Fill(dp, (ll)0);
	dp[0][0][0] = 1;

	for (int i = 0; i < size; ++i)
	{
		ll digit = s[i] - '0';
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				for (int d = 0; d < (k ? 10: digit+1); ++d){
					dp[i+1][j || d == 4 || d == 9][k || d < digit] += dp[i][j][k];
				}
			}
		}
	}
	return dp[size][1][1] + dp[size][1][0];
}



int main(){
	ll a, b;
	cin >> a >> b;
	cout << digDP(b) - digDP(a-1) << endl;

}
