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

using namespace std;

std::ifstream ifs("input1.txt");

class Solver
{
public:
	int n;
	Solver();
	int exec();
};

Solver::Solver(){
	ifs >> n;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		ifs >> tmp;
	}
}


int Solver::exec(){
	return 0;
}

int main(){
	string filename = "test1.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	ifs >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		Solver problem = Solver();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

