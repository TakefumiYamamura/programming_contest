#include <iostream>
#include <vector>
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
	int w, n, k;
	cin >> w;
	cin >> n >> k;
	// int dp[50][10000];
	int weight[51];
	int value[51];

	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i] >> value[i];
	}
	int dp[10010][52]; // 次元削減 重さと何
	Fill(dp, 0);
	int dp2[10010][52];
	Fill(dp2, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = w; j >= 0; --j)
		{
			for (int s = k; s >= 0; --s)
			{
				dp2[j][s] = dp[j][s];
				if(j + weight[i] <= w &&  dp2[j + weight[i]][s+1] <  dp2[j][s] + value[i]){
					dp2[j + weight[i]][s+1] = dp2[j][s] + value[i];
				}
			}
		}

		for (int j = 0; j <= w; ++j)
		{
			for (int s = 0; s <= k ; ++s)
			{
				dp[j][s] = dp2[j][s];
			    dp2[j][s] = 0;
			}
		}
	}

	cout << dp[w][k] << endl;

}
