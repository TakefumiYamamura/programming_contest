#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <map>
#define ll long long 

using namespace std;

int main(){
	string s;
	cin >> s;
	map<string, int> hash;

	for (int i = 0; i < s.length(); ++i)
	{
		if(i+1 < s.length() && s[i] == s[i+1]){
			cout << i+1 << " " << i+2 << endl;
			return 0;
		}
		if(i+2 < s.length() && s[i] == s[i+2]){
			cout << i+1 << " " << i+3 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
}
