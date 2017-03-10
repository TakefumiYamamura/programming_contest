#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 

#define ull unsigned long long
#define ll long long
#define eps 10e-10

using namespace std;

ull pow(ull a, ull e){
    ull tmp = 1;
    while(e > 0){
        if( e & 1ll){
            tmp = tmp * a;
        }
        a = a * a;
        e >>= 1; 
    }
    return tmp;
}

class Probability
{
public:
	int times;
	int sideNum;
	vector<vector<long double> > p;//p[n][sum] nサイコロの数　sum和　
	Probability(int n, int sideNum);
	~Probability();
	void setp();
	// long double fetchp(int n, int side);
};

Probability::Probability(int n_, int sideNum_){
	this->times = n_;
	this->sideNum = sideNum_;
	setp();
}

Probability::~Probability(){}

void Probability::setp(){
	p.resize(times + 1);
	for (int i = 0; i <= times; ++i)
	{
		p[i] = vector<long double>(times*sideNum+1, 0);
	}
	for (int i = 1; i <= sideNum ; ++i)
	{
		p[1][i] = (1.0 / sideNum);
	}

	for (int i = 1; i < times; ++i)
	{
		int middle = ((i+1) * sideNum + i+1)/2;
		int last = (i+1) * sideNum;
		for (int j = i; j <= middle; ++j)
		{
			p[i+1][j] = p[i+1][j-1] + p[i][j-1]/(long double)sideNum;
			p[i+1][last-j+i+1]  = p[i+1][j];
		}
	}
}

// long double  Probability::fetchp(int times, int ){
// 	return p[n][k];
// }


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
	Probability p6 = Probability(12, 6);
	for (int i = 1; i < 5; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			printf("%.6Lf ", p6.p[i][j]);
		}
		cout << endl;
	}
	// string filename = "test.txt";
	// ofstream writing_file;
	// writing_file.open(filename, std::ios::out);
	// int testCase;
	// cin >> testCase;
	// for (int i = 0; i < testCase; ++i)
	// {
	// 	FightingTheZombie problem = FightingTheZombie();
	// 	writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	// }
}
