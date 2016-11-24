#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int ans = 0;
	bool flag = true;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == '0'){
			flag = false;
		}
		if(s[i] == '+') {
			if(flag){
				ans++;
			}
			flag = true;
		}
	}
	if(flag) ans++;
	cout << ans << endl;

}
