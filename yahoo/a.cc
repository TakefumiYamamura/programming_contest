#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

#define ll long long
#define MOD 1000000007

using namespace std;

class Solver
{
public:
	string str;
	map<char, int> hash;
	Solver(){
		cin >> str;
	}
	void exec(){
		string tmp = "yahoo";
		for (int i = 0; i < tmp.length(); ++i)
		{
			hash[tmp[i]]++;
		}
		for (int i = 0; i < str.length(); ++i)
		{
			if(hash.find(str[i]) == hash.end()){
				cout << "NO" << endl;
				return;
			}else{
				hash[str[i]]--;
			}
		}
		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			if(itr->second != 0){
				cout << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl;

	}
};


int main(){
	Solver problem = Solver();
	problem.exec();

}

