#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class DayDream
{
public:
	string s;
	vector<string> checkString;
	DayDream();
	~DayDream();
	int dfs(int k);
	void exec();
};


DayDream::DayDream(){
	cin >> s;
	checkString.push_back("dream");
	checkString.push_back("dreamer");
	checkString.push_back("erase");
	checkString.push_back("eraser");
}

DayDream::~DayDream(){}

int DayDream::dfs(int k){
	if(k == s.size()) return s.size();
	int maxV = 0;
	for (int i = 0; i < 4; ++i)
	{
		bool flag = false;
		for (int j = 0; j < checkString[i].size(); ++j)
		{
			if(s.size() >= k+j && s[k+j] == checkString[i][j]){
				flag = true;
			}else{
				flag = false;
				break;
			}
		}
		if(flag){
			maxV = max(maxV, dfs(k+checkString[i].size()) );
		}
	}
	return maxV;
}

void DayDream::exec(){
	if(dfs(0) == s.size()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}

int main(){
	DayDream dd = DayDream();
	dd.exec();
}
