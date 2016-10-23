#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long 
using namespace std;

int main(){
	string s;
	cin >> s;

	bool flag1 = false;
	bool flag2 = false; 

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == 'C'){
			flag1 = true;
		}
		if(flag1 && s[i] == 'F'){
			flag2 = true;
		}
	}
	if(flag2){
		cout << "Yes" << endl; 
	}else{
		cout << "No" << endl;
	}


}
