#include <iostream>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class BigArray
{
private:
	long long n;
	long long k;
	map<long long, long long> mp;
public:
	BigArray(){
		cin >> n >> k;
		for (long long i = 0; i < n; ++i)
		{
			long long a;
			long long b;
			cin >> a >> b;
			mp[a] += b;
		}
	}
	void exec(){
		long long cur_i = 0;
		for (auto itr = mp.begin(); itr != mp.end(); ++itr)
		{
			cur_i += itr->second;
			if(cur_i >= k){
				cout << itr->first << endl; 
				return;
			}
		}
	}
};

int main(){
	BigArray ba = BigArray();
	ba.exec();
}
