#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	double a = 1.000000000000000;
	int x = 1;
	a = a / 4 * 4;
	x = x / 4 * 4;
	if(a==x){
		cout << "ddd"<< endl;
	}else{
		cout << "dame" << endl;
	}
}