#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class DictionaryOrder
{
public:
	int n, k;
	string s;

	string ans;
	map<char, int> remain_char_count;
	map<char, int> need_char_count;

	DictionaryOrder();
	~DictionaryOrder();
	void exec();
	
};

DictionaryOrder::DictionaryOrder(){
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; ++i)
	{
		if(remain_char_count[s[i]]){
			remain_char_count[s[i]]++;
		}else{
			remain_char_count[s[i]] = 1;
		}
	}
	need_char_count = remain_char_count;
}

DictionaryOrder::~DictionaryOrder(){}

void DictionaryOrder::exec(){
	string ans = "";
	for (int i = 0; i < n; ++i)
	{
		need_char_count[s[i]]--;
		for (int j = 0; j < 26; ++j)
		{
			char next_char = (char)('a' + j);
			if(remain_char_count[next_char] == 0) continue;
			remain_char_count[next_char]--;

			int tmp_cost = 0;
			for (int l = 0; l < i; ++l)
			{
				if(s[l] != ans[l]) tmp_cost++;
			}
			if(next_char != s[i]) tmp_cost++;s
			tmp_cost += (n-1-i);
			for (int l = 0; l < 26; ++l)
			{
				char tmp_char = (char)('a' + l);
				tmp_cost -= min(remain_char_count[tmp_char], need_char_count[tmp_char]);
			}
			if(tmp_cost > k){
				remain_char_count[next_char]++;
				continue;
			}

			ans.push_back(next_char);
			break;
		}
	}
	cout << ans << endl;
}

int main(){
	DictionaryOrder dic = DictionaryOrder();
	dic.exec();
}
