#include <iostream>
#include <vector>

using namesapce std;

class Marble
{
public:
	int r, g, b;
	vector<int> array
	Marble();
	~Marble();
	void exec();
};

Marble::Marble(){
	cin >> r >> g >> b;
}

Marble::~Marble(){}

void Marble::exec(){

}

int main(){
	Marble m = Marble();
	m.exec();
}
