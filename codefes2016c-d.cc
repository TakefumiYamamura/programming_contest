#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#define ll long long
using namespace std;

#define MOD 1000000007

class Solve
{
private:
	int h;
	int w;
	vector<string> c;
public:
	Solve(){
		cin >> h >> w;
		for (int i = 0; i < h; ++i)
		{
			string tmp;
			cin >> tmp;
			c.push_back(tmp);
		}
	}

	void exec(){
		if(s.size() < 4){
			cout << "No" << endl;
			return;
		}
		string tmp = "YAKI";
		for (int i = 0; i < 4; ++i)
		{
			if(s[i] != tmp[i]) {
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;

	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
