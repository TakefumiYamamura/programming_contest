#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long 

using namespace std;

int main(){
	string s;
	string ans;
	ans = "CODEFESTIVAL2016";
	int count = 0;
	cin >> s;
	for (int i = 0; i < 16; ++i)
	{
		if (s[i] != ans[i])
		{
			count++;
		}
	}
	cout << count << endl;
}