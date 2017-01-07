#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 

#define eps 10e-8

using namespace std;

class FightingTheZombie
{
public:
	int n;
	int ans;
	vector<int> w;
	map<int , int>hash;
	FightingTheZombie();
	~FightingTheZombie();
	double exec();
};

FightingTheZombie::FightingTheZombie(){
	cin >> n;
	ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if(tmp >= 50){
			ans++;
			continue;
		}
		hash[tmp]++;
		w.push_back(tmp);
	}
}

FightingTheZombie::~FightingTheZombie(){}

double FightingTheZombie::exec(){
	sort(w.begin(), w.end());
	while(w.size() > 0){
		int last = w[w.size()-1];
		int times  = 50  / last;
		if(last * times != 50){
			times++;
		}
		if(w.size()  >=  times){
			w.pop_back();
			w.erase(w.begin(), w.begin() + times - 1);
			ans++;
		}else{
			break;
		}
	}
	return ans;
}



int main(){
	string filename = "test.txt";
	ofstream writing_file;
	writing_file.open(filename, std::ios::out);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		FightingTheZombie problem = FightingTheZombie();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}
	// vector<int > test;
	// test.push_back(0);
	// test.push_back(1);
	// test.push_back(2);
	// test.push_back(3);
	// // cout << *test.end() << endl;
	// test.erase(test.begin(), test.begin()+2);
	// for (int i = 0; i < test.size(); ++i)
	// {
	// 	cout << test[i];
	// }
	// cout << endl;
}
