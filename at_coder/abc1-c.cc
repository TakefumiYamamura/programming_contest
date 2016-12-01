#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WindPower
{
public:
	int deg;
	double dis;

	WindPower();
	~WindPower();
	void exec();
};

WindPower::WindPower(){
	cin >> deg >> dis;
}

WindPower::~WindPower(){}

void WindPower::exec(){
	deg *= 10;
	deg += 36000;
	deg -= 1125;
	deg %= 36000;
	deg /= 2250;

	int w;
	dis /= 60;
	if (dis < 0.25){
		w = 0;
		deg = 16;
	}
	else if (dis < 1.55)
		w = 1;
	else if (dis < 3.35)
		w = 2;
	else if (dis < 5.45)
		w = 3;
	else if (dis < 7.95)
		w = 4;
	else if (dis < 10.75)
		w = 5;
	else if (dis < 13.85)
		w = 6;
	else if (dis < 17.15)
		w = 7;
	else if (dis < 20.75)
		w = 8;
	else if (dis < 24.45)
		w = 9;
	else if (dis < 28.45)
		w = 10;
	else if (dis < 32.65)
		w = 11;
	else
		w = 12;
	string dir[] = {
		"NNE",
		"NE",
		"ENE",
		"E",
		"ESE",
		"SE",
		"SSE",
		"S",
		"SSW",
		"SW",
		"WSW",
		"W",
		"WNW",
		"NW",
		"NNW",
		"N",
		"C"
	};
	cout << dir[deg] << " " << w << endl;

}

int main(){
	WindPower wp = WindPower();
	wp.exec(); 

}
