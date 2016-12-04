#include <iostream>
#include <vector>

using namespace std;

class SectionDiv
{
public:
	int n, k;
	vector<vector<int > > w;
	SectionDiv();
	~SectionDiv();
	void exec();
};

SectionDiv::SectionDiv(){
	cin >> n >> k;
	w.resize(n);
	for (int i = 0; i < n; ++i)
	{
		w[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> w[i][j];
		}
	}

}

SectionDiv::~SectionDiv(){}

void SectionDiv::exec(){

}

int main(){

}
