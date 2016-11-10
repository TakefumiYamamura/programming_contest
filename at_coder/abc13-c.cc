#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

const ll INF=1LL<<60;

struct Food{
	ll price;
	ll value;
};

class Temperance
{
public:
	ll days, resource;
	Food cheap, luxuary;
	ll down;
	ll expense;
	Temperance();
	~Temperance();
	void exec();
};


Temperance::Temperance(){
	expense = 0;
	cin >> days >> resource;
	cin >>  luxuary.price >> luxuary.value >> cheap.price >> cheap.value >> down;
}

Temperance::~Temperance(){}

void Temperance::exec(){
	expense = INF;
	for (ll i = 0; i <= days; ++i)
	{
		ll luxuary_num = ((days - i) * down - i * cheap.value - resource) / (luxuary.value + down) + 1;
		if(luxuary_num < 0) continue;
		// cout << " cheap " << i << " luxuary " << luxuary_num << " expense " << cheap.price * i + luxuary.price * luxuary_num << endl; 
		expense = min( expense, cheap.price * i + luxuary.price * luxuary_num);
	}
	cout << expense << endl;

}

int main(){
	Temperance t = Temperance();
	t.exec();
}
