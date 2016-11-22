#include <iostream>
#include <vector>

using namespace std;



int pow(int x, int e){
	int ans = 1;
	while(e > 0){
		if(e & 1){
			ans *= x; 
		}
		x *= x;
		e = e >> 1;
	}
	return ans;
}

int main(){
	int n, k;
	vector<vector<int > > t;
	cin >> n >> k;
	t.resize(n);
	for (int i = 0; i < n; ++i)
	{
		t[i].resize(k);
		for (int j = 0; j < k; ++j)
		{
			cin >> t[i][j];
		}
	}
	//kビットの整数をn個選ぶ

	for (int i = 0; i < pow(k, n+1) ; ++i)
	{
		int ans = 0;
		int tmp = 1;
		for (int j = 0; j < n; ++j)
		{			
			ans ^= t[j][i/tmp%k];
			tmp *= k;
		}
		if(ans == 0){
			cout << "Found" << endl;
			return 0;
		}
	}
	cout << "Nothing" << endl;

}
