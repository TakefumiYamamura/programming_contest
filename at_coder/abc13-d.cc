#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Amida
{
public:
	int n, m, d;
	vector<int> a;
	vector<int> to_a;

	Amida();
	~Amida();
	void exec();
	void setResultAmida();
	
};

Amida::Amida(){
	cin >> n >> m >> d;
	for (int i = 0; i < m; ++i)
	{
		int tmp;
		cin >> tmp;
		tmp--;
		a.push_back(tmp);
	}
}

Amida::~Amida(){}

void Amida::exec(){
	setResultAmida();
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		ans.push_back(i);
	}
	for (int i = 0; d >> i > 0; i++)
	{
			if(d >> i & 1){
				vector<int> tmp(n);
				for (int j = 0; j < n; ++j)
				{
					tmp[j] = to_a[ans[j]];
				}
				for (int j = 0; j < n; ++j)
				{
					ans[j] = tmp[j];
				}
		    }

			vector<int> new_to_a(n);
			for (int j = 0; j < n; ++j)
			{
				new_to_a[j] = to_a[to_a[j]];
			}
			
			for (int j = 0; j < n; ++j)
			{
				to_a[j] = new_to_a[j];
			}
	}


	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] + 1 << endl;
	}
}

void Amida::setResultAmida(){
	vector<int> tmp;
	for (int i = 0; i < n; ++i)
	{
		tmp.push_back(i);
	}
	for (int i = 0; i < m; ++i)
	{
		swap(tmp[a[i]], tmp[a[i]+1]);
	}

	to_a.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		to_a[tmp[i]] = i;
	}

}

int main(){
	Amida amida = Amida();
	amida.exec();
}
