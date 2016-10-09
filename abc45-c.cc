#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long 

using namespace std;




int main(){
	string s;
	cin >> s;
	ll sum = 0;
	for (int i = 0; i < 1 << (s.length() - 1); ++i)
	{
		string tmp;
		for (int j = 0; j < s.length(); ++j)
		{
			tmp.push_back(s[j]);
			if(i >> j & 1){
				tmp.push_back('+');
			}
		}
		// cout << tmp << endl;
		int tmp_count = 0;
		for (int j = tmp.length()-1; j >= 0 ; --j)
		{
			if(tmp[j] != '+'){
				sum += ((ll)(tmp[j] - '0') * pow(10, tmp_count));
				// cout << ((int)(tmp[j] - '0') * pow(10, tmp_count)) << endl;
				tmp_count++;
			}else{
				tmp_count = 0;
			}
		}
	}
	cout << sum << endl;
}
