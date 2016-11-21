#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

class Calc123
{
public:
	int n;
	int dp[101][301];
	bool ng[301];
	Calc123();
	~Calc123();
	void exec();
	
};


Calc123::Calc123(){
	cin >> n;
	Fill(dp, 0);
	Fill(ng, true);
	for (int i = 0; i < 3; ++i)
	{
		int tmp;
		cin >> tmp;
		ng[tmp] = false;
	}
}

Calc123::~Calc123(){}

void Calc123::exec(){
	if(!ng[n]){
		cout << "NO" << endl;
		return;
	}
	dp[0][n] = 1;
	for (int i = 0; i < 100 ; ++i)
	{
		for (int j = 0; j <= 300; ++j)
		{
			if(dp[i][j] == 1){
				if(ng[j-1]) dp[i+1][j-1] = 1;
				if(ng[j-2]) dp[i+1][j-2] = 1;
				if(ng[j-3]) dp[i+1][j-3] = 1;

			}
		}
		if(dp[i+1][0]){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;

}


int main(){
	Calc123 c = Calc123();
	c.exec();
}
