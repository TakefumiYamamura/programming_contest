#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class MultipleArray
{
public:
	long long n;
	vector<long long> a;
	vector<long long> b;
	MultipleArray();
	~MultipleArray();
	void exec();
};

MultipleArray::MultipleArray(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long tmpA, tmpB;
		cin >> tmpA >> tmpB;
		a.push_back(tmpA);
		b.push_back(tmpB);
	}
}

MultipleArray::~MultipleArray(){}

void MultipleArray::exec(){
	long long sum = 0;
	for (int i = n-1; i >= 0 ; --i)
	{
		int tmp = (a[i] + sum) % b[i];
		if(tmp == 0) continue;
		sum += b[i]  - tmp;
	}
	cout << sum << endl;
}

int main(){
	MultipleArray solution = MultipleArray();
	solution.exec();
}
