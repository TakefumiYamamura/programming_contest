#include <iostream>
#include <vector>

using namespace std;

class Coin
{
public:
	int n;
	vector<int> c;
	Coin();
	~Coin();
	void exec();
	int countDivisor(int num);
};

Coin::Coin(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		c.push_back(tmp);
	}

}

Coin::~Coin(){}

void Coin::exec(){
	double ans = 0;
	for (int i = 0; i < tmp; ++i)
	{
		int tmp = countDivisor(c[i]);
		ans += (double)((tmp+1)/2) / (double)tmp
	}
	printf("%.10f\n", ans);
}

int Coin::countDivisor(int num){
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(c[i] % num == 0) ans++;
	}
	return ans;
}


int main(){
	Coin c = Coin();
	c.exec();
}