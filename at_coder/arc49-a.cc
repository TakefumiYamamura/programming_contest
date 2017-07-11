#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;
	vector<int> v;
	v.resize(4);
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	string ans = "";
	int itr = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if(v[itr] == i){
			ans += '"';
			itr++;
		}
		ans += str[i];
	}
	if(v[itr] == str.size()) ans += '"';
	cout << ans << endl;
}
