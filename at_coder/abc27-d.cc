#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main(){
	string s;
	cin >> s;
	ll imos = 0;
	vector<ll> m;

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == '+'){
			imos++;
		} else if (s[i] == '-') {
			imos--;
		} else {
			m.push_back(imos);
		}
	}

	sort(m.begin(), m.end());

	ll ans = 0;
	for (int i = 0; i < m.size(); ++i)
	{
		if(i < m.size()/2){
			ans -= m[i]; 
		}else{
			ans += m[i];
		}
	}

	cout << ans << endl;

}
