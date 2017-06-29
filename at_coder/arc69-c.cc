#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

#define MAX_N 10011
#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

class Frequency
{
private:
	int n;
	vector<int> a;
	vector<int> ans;
	map<int, int> hash;//ある数が何個あるか
	map<int, int> place;//ある数が一番左にある時のインデックス

public:
	Frequency(){
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		ans = vector<int>(n, 0);
		for (int i = n-1; i >= 0; --i)
		{
			place[a[i]] = i;
			hash[a[i]]++;
			// hash_array[i] = hash;
		}
	}
	void exec(){
		auto itr = hash.end();
		itr--;
		int tmp = 0; // 今の数より大きい数の個数
		while(true){
			int cur = itr->first;//今の数
			int p = place[cur]; 
			tmp += itr->second; // 今の数の個数
			itr--;
			int next = itr->first;//次に小さい数
			if(p < place[next]) place[next] = p;
			ans[place[cur]] += (cur - next) * tmp;
			if(itr == place.begin()){
				int first = itr->first;
				tmp += itr->second;
				ans[0] += first * tmp;
				// int first = itr->first;
				// if(first == 0)
				break;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << endl;
		}
	}
};

int main(){
	Frequency m = Frequency();
	m.exec();
}