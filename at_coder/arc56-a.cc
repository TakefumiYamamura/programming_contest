#include <iostream>
#include <algorithm>

using namespace std;

class Mikan
{
public:
	long long a, b, k, l;
	Mikan();
	void exec();
	
};

Mikan::Mikan(){
	cin >> a >> b >> k >> l;
}

void Mikan::exec(){
	cout << min( (k/l) * b + a * (k%l), ((k)/l + 1) * b )<< endl;

}


int main(){
	Mikan m = Mikan();
	m.exec();
}
