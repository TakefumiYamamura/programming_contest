#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	string str;
	int k;
	cin >> str;
	cin >> k;
	string tmp_str = "abcdefghijklmnopqrstuvwxyz";
	unordered_map<char, int> um;
	for (int i = 0; i < tmp_str.size(); ++i)
	{
		um[tmp_str[i]] = i;
	}
	for (int i = 0; i < str.size(); ++i)
	{

		if(26 - um[str[i]] <= k){
			k -= 26 - um[str[i]];
			str[i] = 'a';
		}

	}
	str[str.size() - 1] = str[str.size() - 1] + k;
	cout << str << endl;
}
