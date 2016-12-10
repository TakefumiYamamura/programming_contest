#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class GoldGame
{
public:
	int w, h, n;
	vector<vector<int > > map;
	GoldGame();
	~GoldGame();
	void exec();
};

GoldGame::GoldGame(){
	cin >> w >> h;
	cin >> n;
}

GoldGame::~GoldGame(){}

void GoldGame::exec(){

}

int main(){
	GoldGame gg = GoldGame();
	gg.exec();
}
