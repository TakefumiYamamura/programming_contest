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

#define eps 10e-8

using namespace std;

class ProgressPie
{
public:
	int p;
	double x, y;
	ProgressPie();
	~ProgressPie();
	string exec();
};

ProgressPie::ProgressPie(){
	cin >> p >> x >> y;

}

ProgressPie::~ProgressPie(){}

string ProgressPie::exec(){

	if(50 <= x && 50 <= y){
		double difX = x - 50;
		double difY = y - 50;
		if(p <= 25){
			if(difY * tan(2 * M_PI *  p / 100.0) - difX > eps){
				return "black" ;
			}else{
				return "white";
			}

		}else{
			if(50*50 - difX*difX >= difY*difY){
				return "black" ;
			}else{
				return "white";
			}
		}

	}

	if(50 <= x && 50 >= y){
		double difX = x - 50;
		double difY =  50 - y;
		if(p < 25){
			return "white";

		}
		if(p <= 50){
			if(difX * tan(2 * M_PI *  (p-25) / 100.0) - difY > eps){
				return "black" ;
			}else{
				return "white";
			}
		}else{
			if(50*50 - difX*difX >= difY*difY){
				return "black" ;
			}else{
				return "white";
			}
		}

	}

	if(50 >= x && 50 >= y){
		double difX = 50 - x;
		double difY = 50 - y;
		if(p < 50){
			return "white";

		}
		if(p <= 75){
			if(difY * tan(2 * M_PI *  (p-75) / 100.0) - difX > eps){
				return "black" ;
			}else{
				return "white";
			}
		}else{
			if(50*50 - difX*difX >= difY*difY){
				return "black" ;
			}else{
				return "white";
			}
			
		}

	}

	if(50 >= x && 50 <= y){
		double difX = 50 - x;
		double difY = y - 50;
		if(p < 75){
			return "white";
		}
		if(p <= 100){
			if(difX * tan(2 * M_PI *  (p-75) / 100.0) - difY > eps){
				return "black" ;
			}else{
				return "white";
			}
		}else{
			if(50*50 - difX*difX >= difY*difY){
				return "black" ;
			}else{
				return "white";
			}
		}

	}


}

int main(){

	string filename = "test.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		ProgressPie problem = ProgressPie();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}
