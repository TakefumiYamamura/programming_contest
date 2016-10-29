#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long
#define MAX_N 51
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int k, n;
vector<string> val;
vector<string> str;
int len[MAX_N];
string ans[10];

//指定した数で文字列の長さがあってるか
bool check_num(){
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		for (int j = 0; j < val[i].length(); ++j)
		{
			int tmp = val[i][j] - '1';
			count += len[tmp];
		}
		if(count != str[i].length()) return false;
	}
	return true;
}

//中身に矛盾がないか
bool check_contents(){
	string ans[10];
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		for (int j = 0; j < val[i].length(); ++j)
		{
			int tmp = val[i][j] - '1';
			string tmp_str;
			for (int l = count; l < count + len[tmp]; ++l)
			{
				tmp_str.push_back(str[i][l]);
			}
			if(ans[tmp].empty()){
				ans[tmp] = tmp_str;
			} else {
				if(ans[tmp] != tmp_str) return false;
			}
			count += len[tmp];
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << ans[i] << endl;
	}
	return true;
}


int main(){
	cin >> k >> n;
	for (int i = 0; i < n; ++i)
	{
		string v,w;
		cin >> v >> w;
		val.push_back(v);
		str.push_back(w);
	}

	// 3bit全探索
	for (int mask = 0; mask < pow(3, k); ++mask)
	{
		int tmp = mask;
		for (int i = 0; i < k; ++i)
		{
			len[i] = tmp % 3 + 1 ;
			tmp /= 3;
		}
		if(!check_num()) continue;
		if(check_contents()) break;
	}

	return 0;
}
