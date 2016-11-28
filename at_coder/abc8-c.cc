#include <iostream>
#include <vector>
#include <stdio.h>

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
	for (int i = 0; i < n; ++i)
	{
		int tmp = countDivisor(c[i]);
		if(tmp%2 == 0){
			ans += 0.5;
		}else{
			ans += ((tmp+1)/ 2.0 ) / (double)tmp;
		}
	}
	printf("%.10f\n", ans);
}

int Coin::countDivisor(int num){
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(num % c[i] == 0) ans++;
	}
	return ans;
}


int main(){
	Coin c = Coin();
	c.exec();
}