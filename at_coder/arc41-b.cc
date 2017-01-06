#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Ameba
{
public:
	int n, m;
	vector<vector<int > > b;
	vector<vector<int > > ans;
	Ameba();
	~Ameba();
	void exec();	
};

Ameba::Ameba(){
	cin >> n >> m;
	b.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i)
	{
		b[i].resize(m);
		ans[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			ans[i][j] = 0;
			cin >> b[i][j];
		}
	}

}

Ameba::~Ameba(){}

void Ameba::exec(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans[i][j] = 0;
			cin >> b[i][j];
		}
	}

}

int main(){
	Ameba a = Ameba()
	a.exec();
}