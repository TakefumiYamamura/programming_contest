#include <iostream>

using namespace std;

class Riddle
{
public:
	int n, m;
	Riddle();
	~Riddle();
	void exec();
};


Riddle::Riddle(){
	cin >> n >> m;
}

Riddle::~Riddle(){}

void Riddle::exec(){
	for (int adult = 0; adult <= n; ++adult)
	{
		int old = 4*n - 2*adult - m;
		int baby = n - adult - old;
		if(old < 0 || baby < 0) continue;
		if(baby * 4 + adult * 2 + old * 3 == m){
			cout << adult << " " << old << " " << baby << endl;
			return;
		}
	}
	cout << "-1 -1 -1" << endl;
}

int main(){
	Riddle r = Riddle();
	r.exec();
}
