#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class MagicBox
{
public:
	int n;
	set<int> a;
	MagicBox();
	~MagicBox();
	void exec();
};

MagicBox::MagicBox(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		while(tmp % 2 == 0){
			tmp = tmp/2;
		}
		a.insert(tmp);
	}
}

MagicBox::~MagicBox(){}

void MagicBox::exec(){
	cout << a.size() << endl;
}

int main(){
	MagicBox mg = MagicBox();
	mg.exec();
}
