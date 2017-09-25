#include <iostream>
#include <unordered_map>
#define ll long long

using namespace std;

int main() {
	string str;
	ll k;
	cin >> str;
	cin >> k;
	string tmp_str = "abcdefghijklmnopqrstuvwxyz";
	unordered_map<char, ll> um;
	for (ll i = 0; i < tmp_str.size(); ++i)
	{
		um[tmp_str[i]] = i;
	}
	for (ll i = 0; i < str.size(); ++i)
	{
		if(str[i] == 'a') continue;
		if(26 - um[str[i]] <= k){
			k -= 26 - um[str[i]];
			str[i] = 'a';
		}

	}
	int last_id = um[str[str.size() - 1]];
	str[str.size() - 1] = tmp_str[(last_id + k) % 26 ] ;
	cout << str << endl;
}
