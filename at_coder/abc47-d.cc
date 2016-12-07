#include <iostream>
#include <vector>

using namespace std;

class InvisibleHand
{
public:
	int n, t;
	vector<int> a;
	InvisibleHand();
	~InvisibleHand();
	void exec();
};

InvisibleHand::InvisibleHand(){
	cin >> n >> t;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

InvisibleHand::~InvisibleHand(){}

void InvisibleHand::exec(){
	int max = a[n-1];
	int dif = 0;
	int count = 0;
	for (int i = n-2; i >= 0; --i)
	{
		if(max - a[i] > dif){
			count = 1;
			dif = max - a[i];
		}else if(max - a[i] == dif){
			count++;
		}
		if(a[i] > max){
			max = a[i];
		}
	}
	cout << count << endl;

}

int main(){
	InvisibleHand ih = InvisibleHand();
	ih.exec();

}
