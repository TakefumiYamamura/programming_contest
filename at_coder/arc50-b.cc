#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long

const ll MAX = 2e18+7;


using namespace std;

class Bouquet
{
public:
	ll r, b;
	ll x, y;
	Bouquet();
	~Bouquet();
	void exec();	
};

Bouquet::Bouquet(){
	cin >> r >> b;
	cin >> x >> y;
}

Bouquet::~Bouquet(){}

void Bouquet::exec(){
	ll left = 0;
	ll right = MAX;
	ll mid = (right + left) / 2;
	while(left + 1 < right){
		ll tmpR = r - mid;
		ll tmpL = l - mid; 
		if(tmpR < 0 || tmpL < 0){
			right = mid;
			continue;
		}


	}


}

int main(){
	Bouquet b = Bouquet();
	b.exec();
}