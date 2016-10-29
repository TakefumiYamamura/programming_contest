#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	string onkai = "WBWBWWBWBWBW";
	string ans[12] = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
    vector<string> v;
    for (int i = 0; i < 12; ++i)
    {
    	string tmp = "";
    	for (int j = 0; j < 20; ++j)
    	{
    		tmp.push_back(onkai[(i+j)%12]);
    	}
    	v.push_back(tmp);
    }

    for (int i = 0; i < 12; ++i)
    {
    	if(s == v[i]){
    		cout << ans[i] << endl;
    	}
    }
    return 0;
}
