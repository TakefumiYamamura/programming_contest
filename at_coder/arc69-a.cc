#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 10011
#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

class SccPuzzele
{
private:
	ll n, m;
public:
	SccPuzzele(){
		cin >> n >> m;

	}
	void exec(){
		ll ans = 0;
		if(n * 2 < m){
			ans += n;
			m -= n*2;
			ans += m / 4;
		}else{
			ans += m / 2;
		}
		cout << ans << endl;

	}
};

int main(){
	SccPuzzele sp = SccPuzzele();
	sp.exec();
}