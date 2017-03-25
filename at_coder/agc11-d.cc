#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#define ll long long
using namespace std;

#define MOD 1000000007

class Solve
{
private:
	int n;
	int k;
	string s;
	unordered_map<string, int> hash1;
	unordered_map<int, string> hash2;
public:
	Solve(){
		cin >> n >> k;
		cin >> s;
	}

	string fetch_next(string tmp){
		string cur = tmp;
		int i = 0;

		bool ltor = true;

		while(i < n && i >= 0){
			// cout << i << endl;
			if(ltor){
				if(cur[i] == 'A'){
					cur[i] = 'B';
					i--;
					ltor = false;
				}else{
					cur[i] = 'A';
					i++;
				}
			}else{
				if(cur[i] == 'A'){
					cur[i] = 'B';
					i++;
					ltor = true;
				}else{
					cur[i] = 'A';
					i--;
				}
			}
			// cout << cur << endl;
		}
		return cur;
	}

	void exec(){
		// hash2[0] = s;
		// hash1[s] = 0;
		int itr = 0;
		string cur = s;
		while(hash1.find(cur) == hash1.end()){
			hash1[cur] = itr;
			hash2[itr] = cur;
			itr++;
			cur = fetch_next(cur);
			// cout << cur << endl;
		}

		// cout << itr << endl;



		cout << hash2[(k)%itr] << endl;
	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}

